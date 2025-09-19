#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include "Cancion.h"

using namespace std;

class Biblioteca {
private:
    vector<Cancion> canciones;
    string nombreArchivo;

    void cargarArchivo();
    void guardarArchivo();
    void merge(vector<Cancion>& arr, int left, int mid, int right);
    void mergeSort(vector<Cancion>& arr, int left, int right);
    int buscarCancionRec(int low, int high, const string& titulo); // Búsqueda recursiva

public:
    Biblioteca(string archivo);

    void agregarCancion(Cancion c);
    void eliminarCancion(string titulo);
    void editarCancion(string titulo, Cancion nuevaCancion);
    Cancion* consultarCancion(const string& titulo); // Usará búsqueda recursiva
    void mostrarCanciones();
    void ordenarPorTitulo();
    void crearCancionesPrueba();

    
    vector<Cancion> buscarPorAlbum(string album);
    void ordenarPorDuracion();
    void mostrarMasLargaYCorta();
    void exportarCSV(string nombreArchivoCSV);
    void crearLista(string nombreLista);
    int contarCanciones();
};



Biblioteca::Biblioteca(string archivo) {
    nombreArchivo = archivo;
    cargarArchivo();
}

void Biblioteca::cargarArchivo() {
    canciones.clear();
    ifstream file(nombreArchivo.c_str());
    if (!file.is_open()) {
        cout << "Archivo no encontrado, se crearán canciones de prueba en: " << nombreArchivo << endl;
        crearCancionesPrueba();
        return;
    }

    string linea;
    while (getline(file, linea)) {
        stringstream ss(linea);
        string titulo, artista, album, duracionStr;
        if (getline(ss, titulo, ',') &&
            getline(ss, artista, ',') &&
            getline(ss, album, ',') &&
            getline(ss, duracionStr, ',')) {
            int duracion = stoi(duracionStr);
            canciones.push_back(Cancion(titulo, artista, album, duracion));
        }
    }
    file.close();
    cout << canciones.size() << " canciones cargadas desde " << nombreArchivo << "\n";
}

void Biblioteca::guardarArchivo() {
    ofstream file(nombreArchivo.c_str());
    for (size_t i = 0; i < canciones.size(); i++) {
        file << canciones[i].getTitulo() << ","
             << canciones[i].getArtista() << ","
             << canciones[i].getAlbum() << ","
             << canciones[i].getDuracion() << "\n";
    }
    file.close();
}

void Biblioteca::crearCancionesPrueba() {
    canciones.clear();
    canciones.push_back(Cancion("Song1","Artist1","Album1",200));
    canciones.push_back(Cancion("Song2","Artist2","Album2",290));
    canciones.push_back(Cancion("Song3","Artist3","Album3",142));
    canciones.push_back(Cancion("Song4","Artist4","Album4",282));
    canciones.push_back(Cancion("Song5","Artist5","Album5",188));
    canciones.push_back(Cancion("Song6","Artist6","Album6",172));
    canciones.push_back(Cancion("Song7","Artist7","Album7",355));
    canciones.push_back(Cancion("Song8","Artist8","Album8",331));
    canciones.push_back(Cancion("Song9","Artist9","Album9",165));
    canciones.push_back(Cancion("Song10","Artist10","Album10",164));
    canciones.push_back(Cancion("Song11","Artist11","Album11",124));
    canciones.push_back(Cancion("Song12","Artist12","Album12",132));
    canciones.push_back(Cancion("Song13","Artist13","Album13",171));
    canciones.push_back(Cancion("Song14","Artist14","Album14",376));
    canciones.push_back(Cancion("Song15","Artist15","Album15",297));
    canciones.push_back(Cancion("Song16","Artist16","Album16",274));
    canciones.push_back(Cancion("Song17","Artist17","Album17",284));
    canciones.push_back(Cancion("Song18","Artist18","Album18",193));
    canciones.push_back(Cancion("Song19","Artist19","Album19",264));
    canciones.push_back(Cancion("Song20","Artist20","Album20",249));
    canciones.push_back(Cancion("Song21","Artist21","Album21",188));
    canciones.push_back(Cancion("Song22","Artist22","Album22",254));
    canciones.push_back(Cancion("Song23","Artist23","Album23",139));
    canciones.push_back(Cancion("Song24","Artist24","Album24",304));
    canciones.push_back(Cancion("Song25","Artist25","Album25",344));
    canciones.push_back(Cancion("Song26","Artist26","Album26",286));
    canciones.push_back(Cancion("Song27","Artist27","Album27",208));
    canciones.push_back(Cancion("Song28","Artist28","Album28",165));
    canciones.push_back(Cancion("Song29","Artist29","Album29",171));
    canciones.push_back(Cancion("Song30","Artist30","Album30",335));
    canciones.push_back(Cancion("Song31","Artist31","Album31",141));
    canciones.push_back(Cancion("Song32","Artist32","Album32",313));
    canciones.push_back(Cancion("Song33","Artist33","Album33",229));
    canciones.push_back(Cancion("Song34","Artist34","Album34",141));
    canciones.push_back(Cancion("Song35","Artist35","Album35",266));
    canciones.push_back(Cancion("Song36","Artist36","Album36",243));
    canciones.push_back(Cancion("Song37","Artist37","Album37",274));
    canciones.push_back(Cancion("Song38","Artist38","Album38",220));
    canciones.push_back(Cancion("Song39","Artist39","Album39",335));
    canciones.push_back(Cancion("Song40","Artist40","Album40",158));
    canciones.push_back(Cancion("Song41","Artist41","Album41",213));
    canciones.push_back(Cancion("Song42","Artist42","Album42",267));
    canciones.push_back(Cancion("Song43","Artist43","Album43",390));
    canciones.push_back(Cancion("Song44","Artist44","Album44",162));
    canciones.push_back(Cancion("Song45","Artist45","Album45",275));
    canciones.push_back(Cancion("Song46","Artist46","Album46",200));
    canciones.push_back(Cancion("Song47","Artist47","Album47",204));
    canciones.push_back(Cancion("Song48","Artist48","Album48",357));
    canciones.push_back(Cancion("Song49","Artist49","Album49",209));
    canciones.push_back(Cancion("Song50","Artist50","Album50",239));

    guardarArchivo();
}

// Merge Sort 

void Biblioteca::merge(vector<Cancion>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<Cancion> L(n1), R(n2);

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i].getTitulo() <= R[j].getTitulo()) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void Biblioteca::mergeSort(vector<Cancion>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// CRUD 

void Biblioteca::agregarCancion(Cancion c) {
    canciones.push_back(c);
    guardarArchivo();
}

void Biblioteca::eliminarCancion(string titulo) {
    for (size_t i = 0; i < canciones.size(); ++i) {
        if (canciones[i].getTitulo() == titulo) {
            canciones.erase(canciones.begin() + i);
            break;
        }
    }
    guardarArchivo();
}

void Biblioteca::editarCancion(string titulo, Cancion nuevaCancion) {
    for (size_t i = 0; i < canciones.size(); ++i) {
        if (canciones[i].getTitulo() == titulo) {
            canciones[i] = nuevaCancion;
            break;
        }
    }
    guardarArchivo();
}

//  Consulta con búsqueda recursiva

Cancion* Biblioteca::consultarCancion(const string& titulo) {
    if (canciones.empty()) return nullptr;

    ordenarPorTitulo(); // Asegura lista ordenada
    int index = buscarCancionRec(0, canciones.size() - 1, titulo);
    if (index >= 0 && index < canciones.size() && canciones[index].getTitulo() == titulo)
        return &canciones[index];
    return nullptr;
}

int Biblioteca::buscarCancionRec(int low, int high, const string& titulo) {
    if (low > high) return -1;
    int mid = low + (high - low) / 2;
    const string& midTitulo = canciones[mid].getTitulo();

    if (titulo == midTitulo) return mid;
    else if (titulo < midTitulo) return buscarCancionRec(low, mid - 1, titulo);
    else return buscarCancionRec(mid + 1, high, titulo);
}

// Mostrar y Ordenar

void Biblioteca::mostrarCanciones() {
    if (canciones.empty()) {
        cout << "No hay canciones cargadas.\n";
        return;
    }
    for (size_t i = 0; i < canciones.size(); i++) {
        canciones[i].mostrar();
    }
}

void Biblioteca::ordenarPorTitulo() {
    if (canciones.empty()) return;
    mergeSort(canciones, 0, canciones.size() - 1);
}


vector<Cancion> Biblioteca::buscarPorAlbum(string album) { 
    return vector<Cancion>(); 
}
void Biblioteca::ordenarPorDuracion() {}
void Biblioteca::mostrarMasLargaYCorta() {}
void Biblioteca::exportarCSV(string nombreArchivoCSV) {}
void Biblioteca::crearLista(string nombreLista) {}
int Biblioteca::contarCanciones() { return canciones.size(); }

#endif
