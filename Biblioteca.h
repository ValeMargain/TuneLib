#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>
#include <algorithm>
#include "Cancion.h"
#include "AVL.h"

namespace mergesort_vec {

/**
 * Metodo: mid_index
 * Calcula el indice medio entre dos posiciones para dividir el vector.
 * Complejidad: O(1)
 */
inline int mid_index(int left, int right) {
    return left + (right - left) / 2;
}

/**
 * Metodo: mergeTitulo
 * Mezcla dos sub-vectores ordenados por titulo.
 * Complejidad: O(n)
 */
inline void mergeTitulo(std::vector<Cancion>& a, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    std::vector<Cancion> L; L.reserve(n1);
    std::vector<Cancion> R; R.reserve(n2);
    int idx;
    for (idx = 0; idx < n1; ++idx) L.push_back(a[left + idx]);
    for (idx = 0; idx < n2; ++idx) R.push_back(a[mid + 1 + idx]);

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i].getTitulo() <= R[j].getTitulo()) {
            a[k] = L[i];
            ++i;
        } else {
            a[k] = R[j];
            ++j;
        }
        ++k;
    }
    while (i < n1) {
        a[k] = L[i];
        ++i; ++k;
    }
    while (j < n2) {
        a[k] = R[j];
        ++j; ++k;
    }
}

/**
 * Metodo: mergeArtista
 * Mezcla dos sub-vectores ordenados por artista.
 * Complejidad: O(n)
 */
inline void mergeArtista(std::vector<Cancion>& a, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    std::vector<Cancion> L; L.reserve(n1);
    std::vector<Cancion> R; R.reserve(n2);
    int idx;
    for (idx = 0; idx < n1; ++idx) L.push_back(a[left + idx]);
    for (idx = 0; idx < n2; ++idx) R.push_back(a[mid + 1 + idx]);

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i].getArtista() <= R[j].getArtista()) {
            a[k] = L[i];
            ++i;
        } else {
            a[k] = R[j];
            ++j;
        }
        ++k;
    }
    while (i < n1) {
        a[k] = L[i];
        ++i; ++k;
    }
    while (j < n2) {
        a[k] = R[j];
        ++j; ++k;
    }
}

/**
 * Metodo: mergeAlbum
 * Mezcla dos sub-vectores ordenados por album.
 * Complejidad: O(n)
 */
inline void mergeAlbum(std::vector<Cancion>& a, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    std::vector<Cancion> L; L.reserve(n1);
    std::vector<Cancion> R; R.reserve(n2);
    int idx;
    for (idx = 0; idx < n1; ++idx) L.push_back(a[left + idx]);
    for (idx = 0; idx < n2; ++idx) R.push_back(a[mid + 1 + idx]);

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i].getAlbum() <= R[j].getAlbum()) {
            a[k] = L[i];
            ++i;
        } else {
            a[k] = R[j];
            ++j;
        }
        ++k;
    }
    while (i < n1) {
        a[k] = L[i];
        ++i; ++k;
    }
    while (j < n2) {
        a[k] = R[j];
        ++j; ++k;
    }
}

/**
 * Metodo: mergeDuracion
 * Mezcla dos sub-vectores ordenados por duracion.
 * Complejidad: O(n)
 */
inline void mergeDuracion(std::vector<Cancion>& a, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    std::vector<Cancion> L; L.reserve(n1);
    std::vector<Cancion> R; R.reserve(n2);
    int idx;
    for (idx = 0; idx < n1; ++idx) L.push_back(a[left + idx]);
    for (idx = 0; idx < n2; ++idx) R.push_back(a[mid + 1 + idx]);

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i].getDuracion() <= R[j].getDuracion()) {
            a[k] = L[i];
            ++i;
        } else {
            a[k] = R[j];
            ++j;
        }
        ++k;
    }
    while (i < n1) {
        a[k] = L[i];
        ++i; ++k;
    }
    while (j < n2) {
        a[k] = R[j];
        ++j; ++k;
    }
}

/**
 * Metodo: mergeSortRecTitulo
 * Ordena recursivamente un vector por titulo usando Merge Sort.
 * Complejidad: O(n log n)
 */
inline void mergeSortRecTitulo(std::vector<Cancion>& a, int left, int right) {
    if (left >= right) return;
    int mid = mid_index(left, right);
    mergeSortRecTitulo(a, left, mid);
    mergeSortRecTitulo(a, mid + 1, right);
    mergeTitulo(a, left, mid, right);
}

/**
 * Metodo: mergeSortRecArtista
 * Ordena recursivamente un vector por artista usando Merge Sort.
 * Complejidad: O(n log n)
 */
inline void mergeSortRecArtista(std::vector<Cancion>& a, int left, int right) {
    if (left >= right) return;
    int mid = mid_index(left, right);
    mergeSortRecArtista(a, left, mid);
    mergeSortRecArtista(a, mid + 1, right);
    mergeArtista(a, left, mid, right);
}

/**
 * Metodo: mergeSortRecAlbum
 * Ordena recursivamente un vector por album usando Merge Sort.
 * Complejidad: O(n log n)
 */
inline void mergeSortRecAlbum(std::vector<Cancion>& a, int left, int right) {
    if (left >= right) return;
    int mid = mid_index(left, right);
    mergeSortRecAlbum(a, left, mid);
    mergeSortRecAlbum(a, mid + 1, right);
    mergeAlbum(a, left, mid, right);
}

/**
 * Metodo: mergeSortRecDuracion
 * Ordena recursivamente un vector por duracion usando Merge Sort.
 * Complejidad: O(n log n)
 */
inline void mergeSortRecDuracion(std::vector<Cancion>& a, int left, int right) {
    if (left >= right) return;
    int mid = mid_index(left, right);
    mergeSortRecDuracion(a, left, mid);
    mergeSortRecDuracion(a, mid + 1, right);
    mergeDuracion(a, left, mid, right);
}

/**
 * Metodo: mergeSortTitulo
 * Ordena un vector completo por titulo.
 * Complejidad: O(n log n)
 */
inline void mergeSortTitulo(std::vector<Cancion>& a) {
    if ((int)a.size() <= 1) return;
    mergeSortRecTitulo(a, 0, (int)a.size() - 1);
}

/**
 * Metodo: mergeSortArtista
 * Ordena un vector completo por artista.
 * Complejidad: O(n log n)
 */
inline void mergeSortArtista(std::vector<Cancion>& a) {
    if ((int)a.size() <= 1) return;
    mergeSortRecArtista(a, 0, (int)a.size() - 1);
}

/**
 * Metodo: mergeSortAlbum
 * Ordena un vector completo por album.
 * Complejidad: O(n log n)
 */
inline void mergeSortAlbum(std::vector<Cancion>& a) {
    if ((int)a.size() <= 1) return;
    mergeSortRecAlbum(a, 0, (int)a.size() - 1);
}

/**
 * Metodo: mergeSortDuracion
 * Ordena un vector completo por duracion.
 * Complejidad: O(n log n)
 */
inline void mergeSortDuracion(std::vector<Cancion>& a) {
    if ((int)a.size() <= 1) return;
    mergeSortRecDuracion(a, 0, (int)a.size() - 1);
}

} 
class Biblioteca {
private:
    std::vector<Cancion> registros;   // preserva orden de registro en archivo
    AVL arbol;                        // AVL por título
    std::string nombreArchivo;

    /**
     * Metodo: cargarArchivo
     * Lee el archivo TXT y carga todas las canciones al vector y al AVL.
     * Complejidad: O(n log n)
     */
    void cargarArchivo() {
        registros.clear();
        arbol.clear();
        std::ifstream file(nombreArchivo.c_str());
        if(!file.is_open()) {
            std::cout << "No se pudo abrir el archivo " << nombreArchivo << "\n";
            return;
        }
        std::string linea;
        while(std::getline(file, linea)) {
            if(linea.empty()) continue;
            std::stringstream ss(linea);
            std::string t, a, al, dStr;
            if(std::getline(ss, t, ',') && std::getline(ss, a, ',') &&
               std::getline(ss, al, ',') && std::getline(ss, dStr, ',')) {
                try {
                    int d = std::atoi(dStr.c_str());
                    Cancion c(t,a,al,d);
                    registros.push_back(c);
                    arbol.add(c);
                } catch(...) {
                    std::cout << "Error en formato de duracion en linea: " << linea << "\n";
                }
            }
        }
        file.close();
    }

    /**
     * Metodo: guardarArchivo
     * Escribe el vector registros completo sobre el archivo TXT.
     * Complejidad: O(n)
     */
    void guardarArchivo() {
        std::ofstream file(nombreArchivo.c_str());
        if(!file.is_open()) {
            std::cout << "No se pudo guardar el archivo " << nombreArchivo << "\n";
            return;
        }
        for(const Cancion& c : registros) {
            file << c.getTitulo() << "," << c.getArtista() << "," << c.getAlbum() << "," << c.getDuracion() << "\n";
        }
        file.close();
    }

public:
    Biblioteca(const std::string& archivo) : nombreArchivo(archivo) {
        cargarArchivo();
    }

    /**
     * Metodo: agregarCancion
     * Agrega una nueva cancion al vector y AVL, si no existe
     * Complejidad: O(log n)
     */
    bool agregarCancion(const Cancion& c) {
        if (arbol.find(c.getTitulo())) {
            std::cout << "La cancion ya existe.\n";
            return false;
        }
        registros.push_back(c);
        arbol.add(c);
        guardarArchivo();
        std::cout << "Cancion agregada correctamente.\n";
        return true;
    }

    /**
     * Metodo: eliminarCancion
     * Elimina una cancion del vector y AVL por titulo
     * Complejidad: O(n)
     */
    bool eliminarCancion(const std::string& titulo) {
        if (!arbol.find(titulo)) {
            std::cout << "Cancion no encontrada.\n";
            return false;
        }
        arbol.remove(titulo);
        int index = -1;
        std::size_t i;
        for (i = 0; i < registros.size(); ++i) {
            if (registros[i].getTitulo() == titulo) {
                index = (int)i;
                break;
            }
        }
        if (index != -1) {
            registros.erase(registros.begin() + index);
        }
        guardarArchivo();
        std::cout << "Cancion eliminada correctamente.\n";
        return true;
    }

    /**
     * Metodo: editarCancion
     * Edita los datos de una cancion existente
     * Complejidad: O(n)
     */
    bool editarCancion(const std::string& titulo, const Cancion& nueva) {
        int index = -1;
        std::size_t i;
        for (i = 0; i < registros.size(); ++i) {
            if (registros[i].getTitulo() == titulo) { index = (int)i; break; }
        }
        if (index == -1) {
            std::cout << "Cancion no encontrada para editar.\n";
            return false;
        }
        if (nueva.getTitulo() != titulo && arbol.find(nueva.getTitulo())) {
            std::cout << "Ya existe otra cancion con el nuevo titulo.\n";
            return false;
        }
        arbol.remove(titulo);
        arbol.add(nueva);
        registros[index] = nueva;
        guardarArchivo();
        std::cout << "Cancion editada correctamente.\n";
        return true;
    }

     /**
     * Metodo: consultarCancion
     * Busca una cancion por titulo y devuelve un puntero
     * Complejidad: O(n)
     */
    Cancion* consultarCancion(const std::string& titulo) {
        int index = -1;
        std::size_t i;
        for (i = 0; i < registros.size(); ++i) {
            if (registros[i].getTitulo() == titulo) { index = (int)i; break; }
        }
        if (index != -1) return &registros[index];
        return NULL;
    }

     /**
     * Metodo: mostrarCanciones
     * Muestra todas las canciones en pantalla
     * Complejidad: O(n)
     */
    bool mostrarCanciones() const {
        if (registros.empty()) {
            std::cout << "No hay canciones registradas.\n";
            return false;
        }
        std::size_t i;
        for (i = 0; i < registros.size(); ++i) {
            registros[i].mostrar();
        }
        return true;
    }

    /**
     * Metodo: ordenarPorTitulo
     * Muestra canciones ordenadas por titulo usando AVL
     * Complejidad: O(n)
     */
    bool ordenarPorTitulo() const {
        if (registros.empty()) {
            std::cout << "No hay canciones registradas.\n";
            return false;
        }
        std::vector<Cancion> orden = arbol.inorder();
        std::size_t i;
        for (i = 0; i < orden.size(); ++i) orden[i].mostrar();
        return true;
    }

    /**
     * Metodo: ordenarPorArtista
     * Muestra canciones ordenadas por artista usando MergeSort
     * Complejidad: O(n log n)
     */
    void ordenarPorArtista() const {
        if (registros.empty()) {
            std::cout << "No hay canciones.\n";
            return;
        }
        std::vector<Cancion> copia = registros;
        mergesort_vec::mergeSortArtista(copia);
        std::size_t i;
        for (i = 0; i < copia.size(); ++i) copia[i].mostrar();
    }

    /**
     * Metodo: ordenarPorAlbum
     * Muestra canciones ordenadas por album usando MergeSort
     * Complejidad: O(n log n)
     */
    void ordenarPorAlbum() const {
        if (registros.empty()) {
            std::cout << "No hay canciones.\n";
            return;
        }
        std::vector<Cancion> copia = registros;
        mergesort_vec::mergeSortAlbum(copia);
        std::size_t i;
        for (i = 0; i < copia.size(); ++i) copia[i].mostrar();
    }

    /**
     * Metodo: ordenarPorDuracion
     * Muestra canciones ordenadas por duracion usando MergeSort
     * Complejidad: O(n log n)
     */
    void ordenarPorDuracion() const {
        if (registros.empty()) {
            std::cout << "No hay canciones.\n";
            return;
        }
        std::vector<Cancion> copia = registros;
        mergesort_vec::mergeSortDuracion(copia);
        std::size_t i;
        for (i = 0; i < copia.size(); ++i) copia[i].mostrar();
    }

    /**
     * Metodo: mostrarExtremosDuracion
     * Muestra la cancion mas corta y la mas larga
     * Complejidad: O(n)
     */
    void mostrarExtremosDuracion() const {
        if (registros.empty()) {
            std::cout << "No hay canciones.\n";
            return;
        }
        int idxMin = 0;
        int idxMax = 0;
        std::size_t i;
        for (i = 1; i < registros.size(); ++i) {
            if (registros[i].getDuracion() < registros[idxMin].getDuracion()) idxMin = (int)i;
            if (registros[i].getDuracion() > registros[idxMax].getDuracion()) idxMax = (int)i;
        }
        std::cout << "Cancion mas corta:\n";
        registros[idxMin].mostrar();
        std::cout << "Cancion mas larga:\n";
        registros[idxMax].mostrar();
    }


    /**
     * Metodo: exportarTXT
     * Exporta todas las canciones a un archivo TXT.
     * Complejidad: O(n)
     */
    bool exportarTXT(const std::string& archivo) const {
        std::ofstream file(archivo.c_str());
        if (!file.is_open()) {
            std::cout << "No se pudo exportar el archivo.\n";
            return false;
        }
        std::size_t i;
        for (i = 0; i < registros.size(); ++i) {
            const Cancion& c = registros[i];
            file << c.getTitulo() << "," << c.getArtista() << "," << c.getAlbum() << "," << c.getDuracion() << "\n";
        }
        file.close();
        std::cout << "Archivo TXT exportado correctamente.\n";
        return true;
    }

    /**
     * Metodo: buscarPorAlbum
     * Muestra canciones que pertenezcan a un album especifico
     * Complejidad: O(n)
     */
    void buscarPorAlbum(const std::string& album) const {
        bool found = false;
        std::size_t i;
        for (i = 0; i < registros.size(); ++i) {
            if (registros[i].getAlbum() == album) {
                registros[i].mostrar();
                found = true;
            }
        }
        if (!found) std::cout << "No se encontraron canciones del album: " << album << "\n";
    }

     /**
     * Metodo: contarCanciones
     * Retorna la cantidad de canciones en la biblioteca
     * Complejidad: O(1)
     */
    int contarCanciones() const {
        return (int)registros.size();
    }

    /**
     * Metodo: crearListaReproduccion
     * Crea un archivo TXT con canciones especificadas en un vector de titulos
     * Complejidad: O(n*m) n = canciones totales, m = titulos en lista
     */
    bool crearListaReproduccion(const std::string& archivo, const std::vector<std::string>& titulos) const {
        std::ofstream file(archivo.c_str());
        if (!file.is_open()) {
            std::cout << "No se pudo crear la lista de reproduccion.\n";
            return false;
        }
        std::size_t i;
        for (i = 0; i < titulos.size(); ++i) {
            const std::string& t = titulos[i];
            int idx = -1;
            std::size_t j;
            for (j = 0; j < registros.size(); ++j) {
                if (registros[j].getTitulo() == t) { idx = (int)j; break; }
            }
            if (idx != -1) {
                const Cancion& c = registros[idx];
                file << c.getTitulo() << "," << c.getArtista() << "," << c.getAlbum() << "," << c.getDuracion() << "\n";
            } else {
                std::cout << "Advertencia: no se encontro '" << t << "' y no fue incluida.\n";
            }
        }
        file.close();
        std::cout << "Lista de reproduccion creada en: " << archivo << "\n";
        return true;
    }

    void recargar() {
        cargarArchivo();
    }
};

#endif // BIBLIOTECA_H