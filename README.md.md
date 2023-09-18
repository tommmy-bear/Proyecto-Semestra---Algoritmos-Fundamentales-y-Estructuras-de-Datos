# Proyecto Semestral - Busqueda Por Spotify 2023

## Descripción del proyecto

Este código pretende ser un programa que lee y analiza datos de un archivo CSV que contiene datos de transmisión de canciones de Spotify en 2023. A continuación se muestran los elementos y pasos principales del código.

- **Encabezado Incluye:** El código incluye varias bibliotecas C++ estándar, como `<iostream>`, `<string>`, `<sstream>`, `<fstream>`, `<vector>` y `<algorithm>`. También incluye un archivo de encabezado definido por el usuario llamado "sorts.h".

- **Definición de Macro:** Define una macro llamada `spotify_file` con el valor "spotify_2023.csv", que probablemente sea el nombre del archivo CSV a leer.

- **Estructura de Datos:** Define una estructura llamada `song_stream` para almacenar información sobre las canciones, incluido su nombre, número de transmisiones y nombre del artista.

- **Funciones de Clasificación:** El código define varias funciones de clasificación como `compare`, `operator<` y `compare_name` que se utilizan para ordenar y buscar el vector de objetos `song_stream`.

- **Función Principal:** La función principal es el punto de partida del programa.

  - Abre el archivo CSV especificado por la macro `spotify_file`.
  - Inicializa las variables y el vector para almacenar los datos de flujo de la pista.
  - Lee el archivo CSV línea por línea, extrae la información de la canción y la almacena en objetos de secuencia de canciones, que luego se agregan al vector de la canción.
  - Ordena el vector de canciones utilizando una clasificación de combinación personalizada, probablemente definida en el archivo de encabezado "sorts.h".
  - Solicita al usuario el nombre del artista, luego busca en el vector de canciones canciones de ese artista e imprime los resultados.

- **Cerrar Archivo:** El programa cierra el archivo de entrada antes de salir.

En resumen, el código lee los datos de transmisión de Spotify desde un archivo CSV, los almacena en un vector de estructuras de datos personalizadas, clasifica los datos por número de transmisiones y permite al usuario buscar canciones de un artista específico. El algoritmo de clasificación utilizado en este código es "merge sort" dado que es eficiente en términos de tiempo y suele tener un rendimiento constante de O(n log n), donde 'n' es el número de elementos a ordenar. Esto lo hace eficiente incluso para grandes conjuntos de datos.
