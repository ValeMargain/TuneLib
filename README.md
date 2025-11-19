# TuneLib
Este proyecto permite registrar, editar, eliminar y consultar canciones en una biblioteca, así como ordenarlas por título, artista, álbum o duración. Los datos se guardan en un archivo TXT para persistencia entre ejecuciones y se pueden crear listas de reproducción basadas en títulos específicos.

###SICT0302B: Toma decisiones
##Selecciona y usa una estructura lineal adecuada al problema
Se utiliza un vector para guardar todas las canciones registradas en el orden de carga.Esto permite recorrer la lista, copiarla y ordenarla fácilmente. Se puede acceder a canciones por índice y recorrerla completamente para mostrar o buscar canciones.

##Selecciona un algoritmo de ordenamiento adecuado al problema
Se utiliza Merge Sort para ordenar canciones por artista, álbum o duración. Se eligió Merge Sort porque es eficiente y estable, con complejidad garantizada de:
* Mejor caso: O(n log n)
* Caso promedio: O(n log n)
* Peor caso: O(n log n) 
##Usa un árbol adecuado para resolver un problema
Se utiliza un AVL para mantener canciones ordenadas por título. Esto permite inserciones, eliminaciones y búsquedas en tiempo logarítmico, evitando degeneración del árbol. Complejidades del AVL:
* Inserción:
    * Mejor caso: O(log n)
    * Caso promedio: O(log n)
    * Peor caso: O(log n) (siempre balanceado) 
* Eliminación:
    * Mejor caso: O(log n)
    * Caso promedio: O(log n)
    * Peor caso: O(log n) 
* Búsqueda:
    * Mejor caso: O(1) (si el nodo buscado es la raíz)
    * Caso promedio: O(log n)
    * Peor caso: O(log n)

El recorrido inorder del AVL se utiliza para mostrar canciones ordenadas por título en O(n).

###SICT0301B: Evalúa los componentes
##Presenta casos de prueba correctos y completos para todas las funciones y procedimientos del programa
El programa incluye un menú interactivo que permite probar el funcionamiento de cada método de manera directa. Dentro de cada opción del menú se realizan validaciones básicas para garantizar que no se ingresen datos incorrectos o inconsistentes.
Los casos de prueba incluyen:
* Acceso, inserción y eliminación en el vector de canciones (registros)
* Ordenamiento por Merge Sort de título, artista, álbum y duración
* Búsqueda, inserción y eliminación en el AVL por título
* Exportación de listas a archivo TXT y lectura de canciones desde archivos 
Esto asegura que todas las funcionalidades del programa se puedan verificar en ejecución real, validando entradas y evitando errores de ejecución.

##Análisis de complejidad de los componentes
Vector (registros)
* Acceso por índice: O(1)
* Búsqueda secuencial por valor: O(n)
* Inserción al final: O(1) amortizado
* Eliminación por búsqueda: O(n) 
Merge Sort (para artista, álbum, duración)
* Mejor caso: O(n log n)
* Caso promedio: O(n log n)
* Peor caso: O(n log n) 
AVL (para título)
* Inserción: O(log n)
* Eliminación: O(log n)
* Búsqueda: O(log n)
* Recorrido inorder: O(n) 
Otras funciones importantes
* Crear lista de reproducción: O(m * n), donde m es el número de títulos a incluir y n el total de canciones
* Exportar TXT: O(n)
* Mostrar extremos de duración: O(n)
* Buscar por álbum: O(n) 
##Complejidad final del programa
* Las operaciones dominantes son Merge Sort y recorrido del AVL por lo que la complejidad combinada promedio y peor caso del programa es O(n log n) 

###SICT0303B: Implementa acciones científicas
##Implementa mecanismos para consultar información de las estructuras correctamente

* Buscar canción por título: AVL, O(log n)
* Buscar canción por álbum: vector, O(n)
* Mostrar canciones ordenadas por título: recorrido inorder del AVL, O(n)
* Ordenar por artista, álbum o duración: Merge Sort, O(n log n)

##Implementa mecanismos de lectura de archivos
* Las canciones se cargan desde un archivo TXT al iniciar el programa
* Se valida que cada línea tenga todos los campos y que la duración sea numérica
  
##Implementa mecanismos de escritura de archivos
* Cambios como agregar, eliminar o editar canciones se guardan inmediatamente en el TXT
* Se pueden exportar archivos TXT o crear listas de reproducción en archivos separados 

