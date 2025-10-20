#ifndef CANCION_H
#define CANCION_H

#include <string>
#include <iostream>

/*
  Clase: Cancion
  Representa una cancion dentro del sistema.
  Contiene los datos esenciales (titulo, artista, album y duracion)
  y metodos para su acceso, modificacion y visualizacion.

  Cumple un rol principal dentro de la biblioteca musical, ya que
  cada nodo de la lista almacena un objeto de este tipo.
*/
class Cancion {
private:
    std::string titulo;   
    std::string artista;  
    std::string album;   
    int duracion;         // Duración en segundos

public:
    
    //Constructor por defecto
     
    Cancion() : titulo(""), artista(""), album(""), duracion(0) {}

    
    //Constructor parametrizado
    Cancion(const std::string& t, const std::string& a, const std::string& al, int d)
        : titulo(t), artista(a), album(al), duracion(d) {}

    //Getters
    std::string getTitulo() const { 
        return titulo; 
    }
    std::string getArtista() const { 
        return artista; 
    }
    std::string getAlbum() const { 
        return album; 
    }
    int getDuracion() const { 
        return duracion; 
    }

    //Setters

    void setTitulo(const std::string& t) { 
        titulo = t; 
    }
    void setArtista(const std::string& a) { 
        artista = a; 
    }
    void setAlbum(const std::string& al) { 
        album = al; 
    }
    void setDuracion(int d) { 
        duracion = d; 
    }

    /*
      Metodo: mostrar()
      Imprime la informacion de la cancion
    */
    void mostrar() const {
        std::cout << titulo << " - " << artista << " - " 
                  << album << " - " << duracion << "s\n";
    }

    /*
      Sobrecarga del operador <=
      Permite comparar canciones por titulo, lo que facilita
      el ordenamiento en algoritmos como Merge Sort.
      Complejidad: O(1)
    */
    bool operator<=(const Cancion& other) const {
        return titulo <= other.titulo;
    }
};

#endif
