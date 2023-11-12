# Sistema de Búsqueda en Spotify
Es un hecho que hoy en dia la industria musical, como muchas otras, ha pasado de tener un sistema de producción análoga a digital, dado el desarrollo de plataformas como Spotify, las cuales permiten una más rapida manera de publicar y mostrar al mundo el nuevo material que diversos artistas se dedican a producir todos los dias. 

## Objetivo del proyecto
Dado el panorama actual que la industria musical está viviendo, este proyecto tiene el objetivo de poder simular una propuetsa de un pequeño sistema para un trabajador de spotify en el que le permita poder buscar a un artista que esté suscrito a la plataforma, de tal manera que se le puedan desplegar todas las canciones que ha publicado en la misma, todas estas ordenadas en cuestión de la cantidad de *streams* que cada una de estas ha tenido a lo largo del tiempo, siguiendo un orden descendente con respecto a las repproducciones registradas; así mismo, este programa de igual manera le permite al usuario poder agregar de manera manual más información a la pseudo base de datos conectada a este, pues de ser necesario, el usuario podrá ser capaz de agregar una nueva canción de un determinado artista y la cantidad de reproducciones que esta ha tenido desde su lanzamiento. 

## Naturaleza del proyecto
Con el fin de poder simular el uso de una base de datos para este proyecto, se descargó un archivo de valores separados por coma, o .csv, con más de 900 datos, en donde se incluyen el nombre del artista, título de la canción que publicó y la cantidad de "streams" que ha tenido desde su lanzamiento. Una vez obtenida la fuente de datos a ocupar, en sí, la base de todo el código se enecuentra en la implementación del algoritmo de ordenamiento *merge sort* dado que su complejidad asintótica temporal para el peor de los casos es de *O(n log(n))*, con lo que sustenta que es la mejor opción para el manejo de grandes cantidades de datos. Así mismo, en este programa se implementa la estructura de lista doblemente ligada, con la que se pretenden almacenar todas las canciones del artista buscado por el usuario; la elección de estructura de datos se debio a que su complejidad asintótica temporal para inserción en el peor de los casos es de *O(1)*; para acceso y busqueda de igual forma tiene una complejidad asintótica temporal es de *O(n)* para el peor de los casos, y su complejidad asintótica espacial para el peor de los casos es de *O(n)*. En si la naturaleza de todo el programa consiste en que una vez el usuario haya buscado el artista de su interés, datos como su nombre, canción y número de reproducciones, se agreguen como aributos de un nodo, y después con base en la cantidad de *streams* para cada una de las canciones registradas, estás se ordenen haciendo uso del algoritmo *merge sort*.

## Análisis asintótico del código
Como puede ser visto el programa en general se divide en un archivo main y un header de título *DoublyLinkedList*, en sí, en el archivo main por sí mismo solo tiene la finalidad de crear una interfaz de comunicación con el usuario, puesto que manda a llamar todas la funciones del header para poder hacer todo el procesamiento y ordenamiento de datos, de ahí que la finalidad del main se resume al acceso de la pseudo base de datos, su modificación y como interfaz de entrada y salida de datos. Por otro lado, en el header *DoublyLinkedList* se encuentra la clase **DoublyLinkedList** vaya, donde se encuenytra su respectivo constructor y destructor, así como, los siguientes métodos que justo permiten el ordenamiento y almacenamiento de datos dentro de la lista, por ende, a continuación se describirán las complejidades asintóticas de cada uno de estos: 

### Método append
El método **append** añade un nuevo nodo al final de la lista, por ello su complejidad es *O(1)*, ya que solo implica actualizar un par de referencias (next y prev) sin importar el tamaño de la lista.

### Método printList
Este método recorre toda la lista imprimiendo los datos de cada nodo, por ellos su complejidad es *O(n)*, donde 
*n* es el número de nodos en la lista, ya que recorre cada nodo exactamente una vez.

### Método sort y Funciones Relacionadas (mergeSort, split, merge)
El método sort en el código es justo la implementación algoritmo Merge Sort para listas enlazadas. Este algoritmo tiene varias partes, que son: 
* **split**: Divide la lista en dos mitades. La función recorre la lista hasta el medio, lo que tiene una complejidad de *O(n/2)*, es decir, *O(n)*.

* **mergeSort**: Es una función recursiva que divide la lista (usando split) y luego fusiona las mitades ordenadas. La división de la lista en mitades hasta llegar a listas de tamaño 1 implica una profundidad de recursión de *O(log n)*

* **merge**: Este método combina dos listas ordenadas. En el peor de los casos, cada elemento de ambas listas será comparado, lo que conlleva una complejidad de *O(n)* para cada fusión.

En sí, la complejidad asintótica de Merge Sort en listas es *O(n log(n))*. Este cálculo se deriva del hecho de que cada nivel de recursión implica procesar cada nodo (*O(n)*) y hay *log(n)* niveles de recursión debido a la división continua de la lista en mitades.
