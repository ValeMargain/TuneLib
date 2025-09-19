#ifndef CANCION_H
#define CANCION_H

#include <string>
#include <iostream>

class Cancion {
private:
    std::string titulo;
    std::string artista;
    std::string album;
    int duracion; // en segundos

public:
    Cancion();
    Cancion(const std::string& t, const std::string& a,
            const std::string& al, int d);

    std::string getTitulo() const;
    std::string getArtista() const;
    std::string getAlbum() const;
    int getDuracion() const;

    void setTitulo(const std::string& t);
    void setArtista(const std::string& a);
    void setAlbum(const std::string& al);
    void setDuracion(int d);

    void mostrar() const;
};

Cancion::Cancion() : titulo(""), artista(""), album(""), duracion(0) {}

Cancion::Cancion(const std::string& t, const std::string& a,
                 const std::string& al, int d)
    : titulo(t), artista(a), album(al), duracion(d) {}

// Getters 
std::string Cancion::getTitulo() const { 
    return titulo; 
}
std::string Cancion::getArtista() const { 
    return artista; 
}
std::string Cancion::getAlbum() const { 
    return album; 
}
int Cancion::getDuracion() const { 
    return duracion; 
}

// Setters
void Cancion::setTitulo(const std::string& t) { 
    titulo = t; 
}
void Cancion::setArtista(const std::string& a) { 
    artista = a; 
}
void Cancion::setAlbum(const std::string& al) { 
    album = al; 
}
void Cancion::setDuracion(int d) { 
    duracion = d; 
}

// Metodo para mostrar una cancion
void Cancion::mostrar() const {
    std::cout << titulo << " - " << artista
              << " - " << album << " - "
              << duracion << "s\n";
}
#endif