#ifndef AVL_H
#define AVL_H

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include "Cancion.h"


class AVLNode {
public:
    Cancion value;       // Cancion almacenada en el nodo
    AVLNode* left;       // Hijo izquierdo
    AVLNode* right;      // Hijo derecho
    int height;          // Altura del nodo

    /**
     * Constructor de AVLNode
     * Inicializa el nodo con la cancion c y altura 1 (nodo hoja)
     */
    AVLNode(const Cancion& c) : value(c), left(NULL), right(NULL), height(1) {}
};

/**
 * Clase: AVL
 * Estructura de datos: Arbol binario de busqueda auto-balanceado (AVL)
 * 
 * Justificacion:
 * Se utiliza un arbol AVL para mantener las canciones ordenadas por titulo
 * de forma eficiente. Esta estructura garantiza que las operaciones de
 * busqueda, insercion y eliminacion tengan complejidad O(log n), evitando
 * que el arbol se desequilibre como en un arbol binario de busqueda normal.
 * El balanceo automatico permite mantener un rendimiento estable aunque
 * se realicen muchas modificaciones.
 **/

class AVL {
private:
    AVLNode* root;  // Raiz del arbol

    /**
     * Devuelve la altura de un nodo (0 si es NULL)
     * Complejidad: O(1)
     */
    int heightNode(AVLNode* n) const {
        return n ? n->height : 0;
    }

    /**
     * Calcula el factor de balance de un nodo
     * factor = altura(izquierda) - altura(derecha)
     * Complejidad: O(1)
     */
    int balanceFactor(AVLNode* n) const {
        if (!n) return 0;
        return heightNode(n->left) - heightNode(n->right);
    }

    /**
     * Actualiza la altura de un nodo en funcion de sus hijos
     * Complejidad: O(1)
     */
    void updateHeight(AVLNode* n) {
        if (n) {
            int hl = heightNode(n->left);
            int hr = heightNode(n->right);
            n->height = 1 + (hl > hr ? hl : hr);
        }
    }

    /**
     * Rotacion simple a la derecha
     * Corrige desbalance izquierdo-izquierdo
     * Complejidad: O(1)
     */
    AVLNode* rotateRight(AVLNode* y) {
        AVLNode* x = y->left;
        AVLNode* T2 = x->right;

        x->right = y;
        y->left = T2;

        updateHeight(y);
        updateHeight(x);

        return x;
    }

    /**
     * Rotacion simple a la izquierda
     * Corrige desbalance derecho-derecho
     * Complejidad: O(1)
     */
    AVLNode* rotateLeft(AVLNode* x) {
        AVLNode* y = x->right;
        AVLNode* T2 = y->left;

        y->left = x;
        x->right = T2;

        updateHeight(x);
        updateHeight(y);

        return y;
    }

    /**
     * Balancea un nodo tras inserciones o eliminaciones
     * Aplica rotaciones simples o dobles segun el factor de balance
     * Complejidad: O(1)
     */
    AVLNode* balanceNode(AVLNode* node) {
        if (!node) return node;
        updateHeight(node);
        int bf = balanceFactor(node);

        if (bf > 1) {
            if (balanceFactor(node->left) < 0) {
                node->left = rotateLeft(node->left);
            }
            return rotateRight(node);
        }
        if (bf < -1) {
            if (balanceFactor(node->right) > 0) {
                node->right = rotateRight(node->right);
            }
            return rotateLeft(node);
        }
        return node;
    }

    /**
     * Insercion recursiva de una cancion
     * Devuelve la nueva raiz del subarbol balanceado
     * Complejidad: O(log n)
     */
    AVLNode* insertRec(AVLNode* node, const Cancion& c) {
        if (!node) return new AVLNode(c);

        if (c.getTitulo() < node->value.getTitulo()) {
            node->left = insertRec(node->left, c);
        } else if (c.getTitulo() > node->value.getTitulo()) {
            node->right = insertRec(node->right, c);
        } else {
            return node; // titulo duplicado, no inserta
        }

        return balanceNode(node);
    }

    /**
     * Devuelve el nodo con el valor minimo en un subarbol
     * Complejidad: O(log n)
     */
    AVLNode* minValueNode(AVLNode* node) {
        AVLNode* current = node;
        while (current && current->left != NULL) current = current->left;
        return current;
    }

    /**
     * Eliminacion recursiva de un nodo por titulo
     * Complejidad: O(log n)
     */
    AVLNode* removeRec(AVLNode* node, const std::string& titulo) {
        if (!node) return node;

        if (titulo < node->value.getTitulo()) {
            node->left = removeRec(node->left, titulo);
        } else if (titulo > node->value.getTitulo()) {
            node->right = removeRec(node->right, titulo);
        } else {
            // nodo encontrado
            if (node->left == NULL || node->right == NULL) {
                AVLNode* temp = node->left ? node->left : node->right;
                if (!temp) {
                    delete node;
                    node = NULL;
                } else {
                    node->value = temp->value;
                    node->left = temp->left;
                    node->right = temp->right;
                    node->height = temp->height;
                    delete temp;
                }
            } else {
                AVLNode* temp = minValueNode(node->right);
                node->value = temp->value;
                node->right = removeRec(node->right, temp->value.getTitulo());
            }
        }

        if (!node) return node;
        return balanceNode(node);
    }

    /**
     * Busca recursivamente una cancion por titulo
     * Devuelve true si la encuentra, false si no
     * Complejidad: O(log n)
     */
    bool findRec(AVLNode* node, const std::string& titulo) const {
        if (!node) return false;
        if (titulo == node->value.getTitulo()) return true;
        if (titulo < node->value.getTitulo()) return findRec(node->left, titulo);
        return findRec(node->right, titulo);
    }

    /**
     * Recorrido inorder recursivo
     * Almacena los valores en un vector en orden alfabetico por titulo
     * Complejidad: O(n)
     */
    void inorderRec(AVLNode* node, std::vector<Cancion>& out) const {
        if (!node) return;
        inorderRec(node->left, out);
        out.push_back(node->value);
        inorderRec(node->right, out);
    }

    /**
     * Elimina todos los nodos del arbol recursivamente
     * Complejidad: O(n)
     */
    void deleteAll(AVLNode* node) {
        if (!node) return;
        deleteAll(node->left);
        deleteAll(node->right);
        delete node;
    }

public:
    /**
     * Constructor: inicializa un arbol vacio
     */
    AVL() : root(NULL) {}

    /**
     * Destructor: elimina todos los nodos
     */
    ~AVL() { clear(); }

    /**
     * Devuelve true si el arbol esta vacio
     * Complejidad: O(1)
     */
    bool empty() const { return root == NULL; }

    /**
     * Vacia el arbol eliminando todos los nodos
     * Complejidad: O(n)
     */
    void clear() {
        deleteAll(root);
        root = NULL;
    }

    /**
     * Inserta una cancion en el arbol
     * Complejidad: O(log n)
     */
    void add(const Cancion& c) {
        root = insertRec(root, c);
    }

    /**
     * Busca una cancion por titulo
     * Complejidad: O(log n)
     */
    bool find(const std::string& titulo) const {
        return findRec(root, titulo);
    }

    /**
     * Elimina una cancion por titulo
     * Complejidad: O(log n)
     */
    void remove(const std::string& titulo) {
        root = removeRec(root, titulo);
    }

    /**
     * Devuelve un vector de canciones en orden alfabetico por titulo
     * Complejidad: O(n)
     */
    std::vector<Cancion> inorder() const {
        std::vector<Cancion> out;
        inorderRec(root, out);
        return out;
    }
};

#endif // AVL_H
