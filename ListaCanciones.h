#ifndef LISTACANCIONES_H
#define LISTACANCIONES_H

#include "Nodo.h"
#include <iostream>

/**
 * Clase: ListaCanciones
 * Estructura de datos: Lista doblemente ligada
 * 
 * Justificación:
 * Esta estructura se seleccionó por permitir inserciones, eliminaciones y ediciones
 * dinamicas sin requerir un tamaño fijo o indices (a diferencia de un vector).
 * 
 **/
class ListaCanciones {
private:
    Nodo* head;   // Apunta al primer nodo de la lista
    Nodo* tail;   // Apunta al último nodo de la lista
    int size;     // Cantidad de canciones almacenadas

    /**
     * Metodo: dividir
     * Divide la lista en dos mitades para aplicar el algoritmo Merge Sort.
     * Complejidad: O(n)
     */
    Nodo* dividir(Nodo* h) {
        Nodo* lento = h;
        Nodo* rapido = h->next;

        while (rapido && rapido->next) {
            lento = lento->next;
            rapido = rapido->next->next;
        }

        Nodo* mitad = lento->next;
        lento->next = nullptr;
        if (mitad) mitad->previous = nullptr;
        return mitad;
    }

    /**
     * Metodo: fusionar
     * Une dos listas ordenadas en una sola lista ordenada
     * Complejidad: O(n)
     */
    Nodo* fusionar(Nodo* izq, Nodo* der) {
        if (!izq) return der;
        if (!der) return izq;

        if (izq->value.getTitulo() <= der->value.getTitulo()) {
            izq->next = fusionar(izq->next, der);
            if (izq->next) izq->next->previous = izq;
            izq->previous = nullptr;
            return izq;
        } else {
            der->next = fusionar(izq, der->next);
            if (der->next) der->next->previous = der;
            der->previous = nullptr;
            return der;
        }
    }

    /**
     * Metodo: mergeSortRec
     * Llama recursivamente a dividir() y fusionar() para ordenar la lista.
     * Complejidad: O(n log n)
     */
    Nodo* mergeSortRec(Nodo* h) {
        if (!h || !h->next) return h;
        Nodo* mitad = dividir(h);
        Nodo* izq = mergeSortRec(h);
        Nodo* der = mergeSortRec(mitad);
        return fusionar(izq, der);
    }

public:
   
    ListaCanciones() : head(nullptr), tail(nullptr), size(0) {}
    ~ListaCanciones() { clear(); }

    bool empty() const { return head == nullptr; }

    int length() const { return size; }

    Nodo* getHead() const { return head; }

    /**
     * Metodo: addLast
     * Inserta una nueva canción al final de la lista.
     * Complejidad: O(1)
     */
    bool addLast(const Cancion& c) {
        if (find(c.getTitulo())) {
            std::cout << "La canción ya existe.\n";
            return false;
        }
        Nodo* newNode = new Nodo(c);
        if (empty()) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->previous = tail;
            tail = newNode;
        }
        size++;
        std::cout << "Canción agregada correctamente.\n";
        return true;
    }

    /**
     * Metodo: find
     * Busca una cancion por titulo y devuelve el nodo correspondiente.
     * Complejidad: O(n)
     */
    Nodo* find(const std::string& titulo) {
        Nodo* p = head;
        while (p) {
            if (p->value.getTitulo() == titulo)
                return p;
            p = p->next;
        }
        return nullptr;
    }

    /**
     * Metodo: remove
     * Elimina una cancion de la lista por su titulo.
     * Complejidad: O(n)
     */
    bool remove(const std::string& titulo) {
        if (empty()) {
            std::cout << "No hay canciones para eliminar.\n";
            return false;
        }

        Nodo* p = find(titulo);
        if (!p) {
            std::cout << "Canción no encontrada.\n";
            return false;
        }

        if (p->previous) p->previous->next = p->next;
        else head = p->next;

        if (p->next) p->next->previous = p->previous;
        else tail = p->previous;

        delete p;
        size--;
        std::cout << "Canción eliminada correctamente.\n";
        return true;
    }

    /**
     * Metodo: clear
     * Elimina todos los nodos de la lista.
     * Complejidad: O(n)
     */
    void clear() {
        Nodo* p = head;
        while (p) {
            Nodo* tmp = p->next;
            delete p;
            p = tmp;
        }
        head = tail = nullptr;
        size = 0;
    }

    /**
     * Metodo: mostrar
     * Recorre toda la lista y muestra la informacion de cada cancion.
     * Complejidad: O(n)
     */
    void mostrar() const {
        if (empty()) {
            std::cout << "No hay canciones para mostrar.\n";
            return;
        }
        Nodo* p = head;
        while (p) {
            p->value.mostrar();
            p = p->next;
        }
    }

    /**
     * Metodo: ordenarPorTitulo
     * Ordena las canciones alfabeticamente por titulo mediante Merge Sort.
     * Complejidad: O(n log n)
     */
    void ordenarPorTitulo() {
        if (empty() || size < 2) {
            std::cout << "No hay suficientes canciones para ordenar.\n";
            return;
        }
        head = mergeSortRec(head);

        // Actualizar puntero tail
        Nodo* p = head;
        while (p->next) p = p->next;
        tail = p;

        std::cout << "Canciones ordenadas correctamente por título.\n";
    }

    /**
     * Metodo: editar
     * Modifica los datos de una cancion existente.
     * Complejidad: O(n)
     */
    bool editar(const std::string& titulo, const Cancion& nueva) {
        Nodo* n = find(titulo);
        if (!n) {
            std::cout << "Canción no encontrada para editar.\n";
            return false;
        }
        n->value = nueva;
        std::cout << "Canción editada correctamente.\n";
        return true;
    }
};

#endif
