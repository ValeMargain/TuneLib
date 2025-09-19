#include "Biblioteca.h"
#include <iostream>
#include <string>
#include <vector>

int main() {
    Biblioteca bib("./canciones.txt");
    int opcion;

    do {
        std::cout << "\n=== MENU BIBLIOTECA DE CANCIONES ===\n";
        std::cout << "1. Mostrar todas las canciones\n";
        std::cout << "2. Agregar cancion\n";
        std::cout << "3. Eliminar cancion\n";
        std::cout << "4. Editar cancion\n";
        std::cout << "5. Consultar cancion\n";
        std::cout << "6. Ordenar canciones por titulo\n";
        std::cout << "7. Buscar por album\n";
        std::cout << "8. Ordenar por duracion\n";
        std::cout << "9. Mostrar canciones mas largas/cortas\n";
        std::cout << "10. Exportar biblioteca a CSV\n";
        std::cout << "11. Crear lista de reproduccion\n";
        std::cout << "12. Contar numero total de canciones\n";
        std::cout << "13. Salir\n"; // última opción
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;
        std::cin.ignore(); // limpiar buffer

        switch(opcion) {
            case 1:
                bib.mostrarCanciones();
                break;
            case 2: {
                std::string t, a, al;
                int d;
                std::cout << "Titulo: "; std::getline(std::cin, t);
                std::cout << "Artista: "; std::getline(std::cin, a);
                std::cout << "Album: "; std::getline(std::cin, al);
                std::cout << "Duracion (segundos): "; std::cin >> d; std::cin.ignore();
                bib.agregarCancion(Cancion(t, a, al, d));
                break;
            }
            case 3: {
                std::string t;
                std::cout << "Titulo de la cancion a eliminar: ";
                std::getline(std::cin, t);
                bib.eliminarCancion(t);
                break;
            }
            case 4: {
                std::string t, nt, na, nal;
                int nd;
                std::cout << "Titulo de la cancion a editar: "; std::getline(std::cin, t);
                std::cout << "Nuevo Titulo: "; std::getline(std::cin, nt);
                std::cout << "Nuevo Artista: "; std::getline(std::cin, na);
                std::cout << "Nuevo Album: "; std::getline(std::cin, nal);
                std::cout << "Nueva Duracion (segundos): "; std::cin >> nd; std::cin.ignore();
                bib.editarCancion(t, Cancion(nt, na, nal, nd));
                break;
            }
            case 5: {
                std::string t;
                std::cout << "Titulo de la cancion a consultar: ";
                std::getline(std::cin, t);
                Cancion* c = bib.consultarCancion(t);
                if(c)
                    std::cout << "Encontrada: " 
                              << c->getTitulo() << " - " 
                              << c->getArtista() << " - " 
                              << c->getAlbum() << " - " 
                              << c->getDuracion() << "s\n";
                else
                    std::cout << "Cancion no encontrada.\n";
                break;
            }
            case 6:
                bib.ordenarPorTitulo();
                std::cout << "Canciones ordenadas por titulo.\n";
                break;
            case 7: {
                break;
            }
            case 8:
                break;
            case 9:
                break;
            case 10: {
                break;
            }
            case 11: {
                break;
            }
            case 12:
                break;
            case 13:
                std::cout << "Saliendo...\n";
                break;
            default:
                std::cout << "Opcion invalida.\n";
        }

    } while(opcion != 13);

    return 0;
}
