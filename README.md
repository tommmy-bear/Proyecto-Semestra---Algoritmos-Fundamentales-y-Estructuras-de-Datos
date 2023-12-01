# TC1031 - Proyecto Semestral Integral - A01028008 - Tomás Pérez Vera -Sitema de Búsqueda en Spotify

Es un hecho que hoy en dia la industria musical, como muchas otras, ha pasado de tener un sistema de producción análoga a digital, dado el desarrollo de plataformas como Spotify, las cuales permiten una más rapida manera de publicar y mostrar al mundo el nuevo material que diversos artistas se dedican a producir todos los dias. 

Dado el panorama actual que la industria musical está viviendo, este proyecto tiene el objetivo de poder simular una propuetsa de un pequeño sistema para un trabajador de *Spotify* en el que le permita poder buscar a un artista que esté suscrito a la plataforma, de tal manera que se le puedan desplegar todas las canciones que ha publicado en la misma, todas estas ordenadas en cuestión de la cantidad de *streams* que cada una de ha tenido a lo largo del tiempo, siguiendo un orden descendente con respecto a las repproducciones registradas; así mismo, este programa de igual manera le permite al usuario poder agregar de manera manual más información a la pseudo base de datos conectada a este, pues de ser necesario, el usuario podrá ser capaz de agregar una nueva canción de un determinado artista, el nombre del mimos y la cantidad de reproducciones que esta ha tenido desde su lanzamiento. 

# SICT0301 Evalúa los componentes

## Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa.

El método sort en el código es justo la implementación algoritmo Merge Sort para listas enlazadas. Para su funcionamiento, este se encuentra compuesto de funciones auxiliares. A continuación el análisis asintótico de estas: 

* **split**: Divide la lista en dos mitades. La función recorre la lista hasta el medio, lo que tiene una complejidad de *O(n/2)*, es decir, *O(n)*.

* **mergeSort**: Es una función recursiva que divide la lista (usando split) y luego fusiona las mitades ordenadas. La división de la lista en mitades hasta llegar a listas de tamaño 1 implica una profundidad de recursión de *O(log n)*

* **merge**: Este método combina dos listas ordenadas. En el peor de los casos, cada elemento de ambas listas será comparado, lo que conlleva una complejidad de *O(n)* para cada fusión.

En sí, la complejidad asintótica de Merge Sort en listas es *O(n log(n))*. Este cálculo se deriva del hecho de que cada nivel de recursión implica procesar cada nodo (*O(n)*) y hay *log(n)* niveles de recursión debido a la división continua de la lista en mitades.

## Hace un análisis de complejidad correcto y completo todas las estructuras de datos y cada uno de sus usos en el programa

Este programa se implementa la estructura de lista doblemente ligada, con la que se pretenden almacenar todas las canciones del artista buscado por el usuario; la elección de estructura de datos se debio a que su complejidad asintótica temporal para inserción en el peor de los casos es de *O(1)*; para acceso y busqueda de igual forma tiene una complejidad asintótica temporal es de *O(n)* para el peor de los casos, y su complejidad asintótica espacial para el peor de los casos es de *O(n)*.

## Hace un análisis de complejidad correcto y completo para todos los demás componentes del programa y determina la complejidad final del programa.

Una vez analizadas las complejidades asintóticas de la estructura de datos y el algoritmo de ordenamiento implementados en el proyecto, a continuación se muestran loa analísis asíntotico de los demás elementos del programa:

  **1. search artist**: 

  **Complejidad temporal**: La función searchArtist tiene dos partes principales: la lectura de un archivo y la inserción en la lista enlazada.
    * Lectura de archivo: *O(n)* donde *n* es el número de líneas en al archivo. 
    * Inserción de la lista: En el peor de los casos, este es *O(1)* por nodo. 

**Complejidad Espacial**: *O(n)*,ya que almacena *n* nodos.

**2. addDataToFile** 

**Complejidad temporal**: *O(1)*, asumiendo que la escritura en el archivo es constante.
**Complejidad espacial**: *O(1)*, sin uso significativo de memoria adicional.

**3. main**

**Complejidad temporal**: Si el usuario Si elige buscar un artista, es 
*O(n)*; en cambio si elige agregar uno, es: *O(1)*.

**Complejidad espacial**: *O(1)* o *O(n)* si se elige buscar un artista.

**4. Análisis Total**
Con base en los análisis asintóticos previos, se obtuvieron los siguientes aálisis asintóticos totales del programa: 

**Análisis temporal**: En el peor casos buscar un artista y luego ordenarlo con base en sus *streams*, es *O (n log n)*.

**Análisis espacial**:O(n) para almacenar la lista y *O(log n)* para el sort, resultando en *O(n)* total.

# SICT0302 Toma decisiones 

## Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.

Con el fin de poder simular el uso de una base de datos para este proyecto, se descargó un archivo de valores separados por coma, o .csv, con más de 900 datos, en donde se incluyen el nombre del artista, título de la canción que publicó y la cantidad de *streams* que ha tenido desde su lanzamiento. Una vez obtenida la fuente de datos a ocupar, en sí, la base de todo el código se enecuentra en la implementación del algoritmo de ordenamiento *merge sort* dado que su complejidad asintótica temporal para el peor de los casos es de *O(n log(n))*

## Selecciona una estructura de datos adecuada al problema y lo usa correctamente.

En este programa se implementa la estructura de lista doblemente ligada, con la que se pretenden almacenar todas las canciones del artista buscado por el usuario; la elección de estructura de datos se debio a que su complejidad asintótica temporal para inserción en el peor de los casos es de *O(1)*; para acceso y busqueda de igual forma tiene una complejidad asintótica temporal es de *O(n)* para el peor de los casos, y su complejidad asintótica espacial para el peor de los casos es de *O(n)*.

# SICT0303 Implementa acciones científicas

## Implementa mecanismos para consultar información de las estructras correctos

La función searchArtist busca y muestra canciones de un artista específico en una lista doblemente enlazada. Abre y lee un archivo CSV, procesa cada línea para extraer el nombre del artista, el nombre de la pista y el número de reproducciones, y compara el nombre del artista con el proporcionado. Si coincide, añade la información a la lista. Después de leer todas las líneas, la función cierra el archivo, ordena la lista por número de reproducciones y la imprime.

## Implementa mecanismos de lectura de archivos para cargar datos a las estructuras de manera correcta

El programa lee un archivo CSV llamado "project.csv" utilizando la biblioteca estándar de C++. Abre el archivo, lee cada línea y utiliza un std::istringstream para separar los campos delimitados por comas, extrayendo así los datos de artistas, pistas y reproducciones. Después de procesar todas las líneas, el archivo se cierra de manera segura.

## Implementa mecanismos de escritura de archivos para guardar los datos  de las estructuras de manera correcta

La función addDataToFile() en C++ permite al usuario ingresar datos de un artista, incluyendo el nombre del artista, el nombre de la canción y las reproducciones. Estos datos se añaden a "project.csv" en una nueva línea, utilizando el formato CSV. La función maneja la apertura segura del archivo y muestra un mensaje de error si no puede abrirlo.
