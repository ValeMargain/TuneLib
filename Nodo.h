#ifndef NODO_H
#define NODO_H

#include "Cancion.h"
/*
  Clase: Nodo
  Representa un nodo dentro de una lista doblemente ligada.
  Cada nodo almacena un objeto de tipo `Cancion` y dos punteros
  que permiten recorrer la lista en ambas direcciones.
*/
class Nodo {
public:
    Cancion value;   // Dato almacenado en el nodo (una canción)
    Nodo* previous;  // Puntero al nodo anterior
    Nodo* next;      // Puntero al nodo siguiente

   //Constructor
    Nodo(const Cancion& c)
        : value(c), previous(nullptr), next(nullptr) {}
};

#endif
