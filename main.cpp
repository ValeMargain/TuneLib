#include <iostream>
#include <vector>
#include <string>
#include "Biblioteca.h"
#include "Cancion.h"

void mostrarMenu() {
    std::cout << "\n=== MENU BIBLIOTECA DE CANCIONES ===\n";
    std::cout << "1. Agregar cancion\n";
    std::cout << "2. Eliminar cancion\n";
    std::cout << "3. Editar cancion\n";
    std::cout << "4. Consultar cancion\n";
    std::cout << "5. Mostrar todas las canciones\n";
    std::cout << "6. Ordenar por titulo\n";
    std::cout << "7. Ordenar por artista\n";
    std::cout << "8. Ordenar por album\n";
    std::cout << "9. Ordenar por duracion\n";
    std::cout << "10. Mostrar cancion con mayor y menor duracion\n";
    std::cout << "11. Exportar a TXT\n";
    std::cout << "12. Buscar por album\n";
    std::cout << "13. Crear lista de reproduccion\n";
    std::cout << "14. Recargar archivo\n";
    std::cout << "0. Salir\n";
    std::cout << "Seleccione una opcion: ";
}

int main() {
    Biblioteca biblioteca("canciones.txt");
    int opcion;
    
    do {
        mostrarMenu();
        std::cin >> opcion;
        std::cin.ignore(); // limpiar buffer
        std::string titulo, artista, album;
        int duracion;

        switch (opcion) {
            case 1: // Agregar cancion
                std::cout << "Titulo: ";
                std::getline(std::cin, titulo);
                std::cout << "Artista: ";
                std::getline(std::cin, artista);
                std::cout << "Album: ";
                std::getline(std::cin, album);
                std::cout << "Duracion (segundos): ";
                std::cin >> duracion;
                std::cin.ignore();
                if(biblioteca.agregarCancion(Cancion(titulo, artista, album, duracion)))
                    std::cout << "Cancion agregada correctamente.\n";
                else
                    std::cout << "Error al agregar cancion.\n";
                break;

            case 2: // Eliminar
                std::cout << "Titulo a eliminar: ";
                std::getline(std::cin, titulo);
                if(biblioteca.eliminarCancion(titulo))
                    std::cout << "Cancion eliminada.\n";
                else
                    std::cout << "No se encontro la cancion.\n";
                break;

            case 3: // Editar
                std::cout << "Titulo a editar: ";
                std::getline(std::cin, titulo);
                std::cout << "Nuevo titulo: ";
                std::getline(std::cin, artista); // reutilizamos variable
                std::cout << "Nuevo artista: ";
                std::getline(std::cin, album);
                std::cout << "Nueva duracion: ";
                std::cin >> duracion;
                std::cin.ignore();
                if(biblioteca.editarCancion(titulo, Cancion(artista, album, titulo, duracion)))
                    std::cout << "Cancion editada.\n";
                else
                    std::cout << "No se encontro la cancion.\n";
                break;

            case 4: // Consultar
                std::cout << "Titulo a consultar: ";
                std::getline(std::cin, titulo);
                {
                    Cancion* c = biblioteca.consultarCancion(titulo);
                    if(c) c->mostrar();
                    else std::cout << "Cancion no encontrada.\n";
                }
                break;

            case 5: // Mostrar todas
                biblioteca.mostrarCanciones();
                break;

            case 6: // Ordenar por titulo
                biblioteca.ordenarPorTitulo();
                std::cout << "Vector ordenado por titulo.\n";
                break;

            case 7: // Ordenar por artista
                biblioteca.ordenarPorArtista();
                std::cout << "Vector ordenado por artista.\n";
                break;

            case 8: // Ordenar por album
                biblioteca.ordenarPorAlbum();
                std::cout << "Vector ordenado por album.\n";
                break;

            case 9: // Ordenar por duracion
                biblioteca.ordenarPorDuracion();
                std::cout << "Vector ordenado por duracion.\n";
                break;

            case 10: // Mostrar extremos de duracion
                biblioteca.mostrarExtremosDuracion();
                break;

            case 11: // Exportar a TXT
                std::cout << "Nombre de archivo a exportar: ";
                std::getline(std::cin, titulo);
                if(biblioteca.exportarTXT(titulo))
                    std::cout << "Archivo exportado correctamente.\n";
                else
                    std::cout << "Error al exportar archivo.\n";
                break;

            case 12: // Buscar por album
                std::cout << "Album a buscar: ";
                std::getline(std::cin, album);
                biblioteca.buscarPorAlbum(album);
                break;

            case 13: // Crear lista de reproduccion
                {
                    std::vector<std::string> titulos;
                    std::string input;
                    std::cout << "Ingrese titulos para lista (vacio para terminar):\n";
                    while(true) {
                        std::getline(std::cin, input);
                        if(input.empty()) break;
                        titulos.push_back(input);
                    }
                    std::cout << "Nombre archivo lista: ";
                    std::getline(std::cin, titulo);
                    if(biblioteca.crearListaReproduccion(titulo, titulos))
                        std::cout << "Lista de reproduccion creada.\n";
                    else
                        std::cout << "Error al crear lista.\n";
                }
                break;

            case 14: // Recargar
                biblioteca.recargar();
                std::cout << "Archivo recargado.\n";
                break;

            case 0:
                std::cout << "Saliendo del programa...\n";
                break;

            default:
                std::cout << "Opcion invalida.\n";
                break;
        }

    } while(opcion != 0);

    return 0;
}
