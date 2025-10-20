#ifndef BIBLIOTECA_H 
#define BIBLIOTECA_H


#include "ListaCanciones.h"
#include <fstream>
#include <sstream>
#include <string>

/*
  Clase: Biblioteca
  Administra una coleccion de canciones utilizando una lista doblemente ligada.
  Permite realizar operaciones CRUD, ordenar canciones, exportar informacion
  y manejar persistencia en archivo CSV.
*/
class Biblioteca {
private:
    ListaCanciones canciones;   // Estructura de datos principal (lista doblemente ligada)
    std::string nombreArchivo;  // Archivo donde se guardan las canciones

    /*
      Metodo: cargarArchivo()
      Carga los datos del archivo CSV en la lista de canciones.
    */
    void cargarArchivo() {
        canciones.clear();
        std::ifstream file(nombreArchivo);
        if (!file.is_open()){
            std::cout << "No se pudo abrir el archivo " << nombreArchivo << "\n";
            return;
        }

        std::string linea;
        while (getline(file, linea)) {
            std::stringstream ss(linea);
            std::string t, a, al, dStr;
            if (getline(ss, t, ',') && getline(ss, a, ',') && getline(ss, al, ',') && getline(ss, dStr, ',')) {
                try {
                    int d = std::stoi(dStr);
                    canciones.addLast(Cancion(t, a, al, d));
                } catch (...) {
                    std::cout << "Error en formato de duración en línea: " << linea << "\n";
                }
            }
        }
        file.close();
    }

    /*
      Método: guardarArchivo
      Guarda el contenido de la lista de canciones en el archivo CSV.
      Complejidad: O(n)
     */
    void guardarArchivo() {
        std::ofstream file(nombreArchivo);
        if (!file.is_open()) {
            std::cout << "No se pudo guardar el archivo " << nombreArchivo << "\n";
            return;
        }
        Nodo* p = canciones.getHead();
        while (p) {
            file << p->value.getTitulo() << ","
                 << p->value.getArtista() << ","
                 << p->value.getAlbum() << ","
                 << p->value.getDuracion() << "\n";
            p = p->next;
        }
        file.close();
    }

public:
   
    //Constructor
    Biblioteca(const std::string& archivo) : nombreArchivo(archivo) {
        cargarArchivo();
    }

    /*
      Método: agregarCancion
      Agrega una canción a la lista y actualiza el archivo.
      Complejidad: O(n) (por búsqueda previa en la lista)
    */
    bool agregarCancion(const Cancion& c) {
        if (!canciones.addLast(c)) return false;
        guardarArchivo();
        return true;
    }

    /*
      Método: eliminarCancion
      Elimina una cancion de la lista y actualiza el archivo.
      Complejidad: O(n)
    */
    bool eliminarCancion(const std::string& titulo) {
        bool eliminado = canciones.remove(titulo);
        if (eliminado) guardarArchivo();
        return eliminado;
    }

    /*
      Metodo: editarCancion
      Edita los datos de una cancion existente.
      Complejidad: O(n)
    */
    bool editarCancion(const std::string& titulo, const Cancion& nueva) {
        bool editada = canciones.editar(titulo, nueva);
        if (editada) guardarArchivo();
        return editada;
    }

    /*
      Metodo: consultarCancion
      Busca una cancion y devuelve un puntero a ella.
      Complejidad: O(n)
    */
    Cancion* consultarCancion(const std::string& titulo) {
        Nodo* n = canciones.find(titulo);
        if (n != nullptr) {
            return &n->value;
        } else {
            std::cout << "Cancion no encontrada.\n";
            return nullptr;
        }    
    }

    /*
      Método: mostrarCanciones
      Muestra todas las canciones en consola.
      Complejidad: O(n)
    */
    bool mostrarCanciones() {
        if (canciones.empty()) {
            std::cout << "No hay canciones registradas.\n";
            return false;
        }
        canciones.mostrar();
        return true;
    }

    /*
      Método: ordenarPorTitulo
      Ordena las canciones alfabéticamente por titulo usando Merge Sort.
      Complejidad: O(n log n)
    */
    bool ordenarPorTitulo() {
        if (canciones.empty()) {
            std::cout << "No hay canciones para ordenar.\n";
            return false;
        }
        canciones.ordenarPorTitulo();
        guardarArchivo();
        return true;
    }

    /*
      Metodo: exportarCSV
      Exporta las canciones a un archivo CSV nuevo.
      Complejidad: O(n)
    */
    bool exportarCSV(const std::string& archivo) {
        std::ofstream file(archivo);
        if (!file.is_open()) {
            std::cout << "No se pudo exportar el archivo.\n";
            return false;
        }

        Nodo* p = canciones.getHead();
        while (p) {
            file << p->value.getTitulo() << ","
                 << p->value.getArtista() << ","
                 << p->value.getAlbum() << ","
                 << p->value.getDuracion() << "\n";
            p = p->next;
        }

        file.close();
        std::cout << "Archivo exportado correctamente.\n";
        return true;
    }

    /*
      Metodo: contarCanciones
      Devuelve el numero total de canciones.
      Complejidad: O(1)
    */
    int contarCanciones() const {
        return canciones.length();
    }
};

#endif
