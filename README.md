# TuneLib
Este proyecto es una biblioteca musical que permite registrar, consultar, editar y organizar canciones. Se basa en la siguiente lógica de uso:

**Ejemplo de uso de TuneLib:**

1. Registrar canciones: Permite agregar nuevas canciones indicando su título, artista, álbum y duración. Cada canción se guarda automáticamente en la biblioteca para futuras consultas.

2. Consultar una canción específica: Permite buscar una canción por su título para ver todos sus detalles, incluyendo artista, álbum y duración.

3. Editar información de una canción existente: Permite actualizar los datos de una canción previamente registrada, como corregir el título, cambiar el artista o ajustar la duración.

4. Mostrar todas las canciones disponibles: Muestra en pantalla la lista completa de canciones registradas en la biblioteca con todos sus detalles.

5. Ordenar canciones por título: Organiza la lista de canciones alfabéticamente según el título de cada canción para facilitar la búsqueda.

6. Ordenar canciones por duración: Permite organizar las canciones de acuerdo con su duración, ya sea de la más corta a la más larga o viceversa.

7. Buscar canciones por álbum: Permite localizar todas las canciones que pertenecen a un mismo álbum, mostrando rápidamente la colección completa de un artista o disco.

8. Crear listas de reproducción personalizadas: Permite generar listas de canciones seleccionadas por el usuario, para escucharlas o gestionarlas como una colección independiente.

9. Mostrar la canción más larga y la más corta: Identifica y muestra las canciones con mayor y menor duración dentro de la biblioteca, facilitando comparaciones o selección de canciones según tiempo disponible.

10. Exportar la biblioteca a un archivo CSV: Permite guardar todas las canciones en un archivo CSV para consultarlas o usarlas en otras aplicaciones.

11. Generar canciones de prueba automáticamente: Si al iniciar el programa no se encuentra el archivo de la biblioteca, el sistema crea 50 canciones de ejemplo con títulos, artistas y álbumes ficticios, para que la aplicación funcione inmediatamente y se puedan probar todas las funcionalidades.

**Selección y uso de la estructura de datos**

Se utiliza un vector de objetos Cancion para registrar las canciones porque necesito:

Acceso rápido a cualquier canción por su posición.

Poder recorrer toda la lista para mostrar o buscar canciones.

Cada canción es un objeto que contiene: título, artista, álbum y duración en segundos. Los elementos se pueden insertar, eliminar o editar usando las funciones agregarCancion, eliminarCancion y editarCancion, que se encuentran en el archivo Biblioteca.h en las líneas 175, 180 y 190 respectivamente.

**Selección de algoritmo de ordenamiento**

Para este problema se utiliza un algoritmo de tipo Merge Sort para organizar las canciones por título en orden alfabético ascendente.

Elegí Merge Sort porque es rápido en la mayoría de los casos y estable, y porque es poco probable encontrarme con su peor caso, ya que la lista inicial de canciones siempre se carga desordenada.

La función donde se puede ver el uso del Merge Sort es ordenarPorTitulo, ubicada en Biblioteca.h líneas 217-224.
