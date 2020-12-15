# Algoritmos y Estructura de Datos
## Proyecto sobre Grafos
--------

El proyecto del curso consiste en implementar una estructura de datos de grafo y un file parser. El proyecto cuenta con TestMenu que permite agregar grafos dirigidos o no dirigidos y luego, te permite obtener la densidad del grafo, el peso de las aristas, mostrar el grafo, eliminar algún vértice o arista, etc. Por otro lado, el Menú también permite mostrar los algoritmos de búsqueda
mediante ejemplos específicos para cada algoritmo. Algunos muestran sus variantes para dirigidos y no dirigidos, dicho sea el caso. Finalmente, se hace un testeo del JSON Parser, para mostrar los elementos de un documento JSON en un grafo dirigido y no dirigido. Para poder correr el código de este proyecto, es necesario el uso de CMAKE ya sea en los IDE de CLion o Visual Studio Code.

## Integrantes
- José Vásquez Ayala
- Luciano Zagastizabal Granadino

----
## Graph data structure

* El grafo debe ser dinámico (inserciones. eliminaciones, búsquedas, ...)
* Se debe implementar los dos tipos de grafos: dirigidos y no-dirigidos.
* No considerar loops ni multi-arista. 


### Methods:
```cpp
bool insertVertex(string id, V data); // Creates a new vertex in the graph with some data and an ID

bool createEdge(string start, string end, E data); // Creates a new edge in the graph with some data

bool deleteVertex(string id); // Deletes a vertex in the graph

bool deleteEdge(string start, string end); // Deletes an edge in the graph, it is not possible to search by the edge value, since it can be repeated

E &operator()(string start, string end); // Gets the value of the edge from the start and end vertexes

float density() const; // Calculates the density of the graph

bool isDense(float threshold = 0.5) const; // Calculates the density of the graph, and determine if it is dense dependening on a threshold value

bool isConnected(); // Detect if the graph is connected

bool isStronglyConnected() throw(); // Detect if the graph is strongly connected (only for directed graphs)

bool empty(); // If the graph is empty

void clear(); // Clears the graph
```

### Algorithms (Part 1):
```cpp
//Given the graph
UndirectedGraph<char, int> graph;

//1- Generates a MST graph using the Kruskal approach (only for undirected graphs)
Kruskal<char, int> kruskal(&graph);
UndirectedGraph<char, int> result = kruskal.apply();//return a tree

//2- Generates a MST graph using the Prim approach (only for undirected graphs)
Prim<char, int> prim(&graph, "A");
UndirectedGraph<char, int> result = prim.apply();//return a tree
```



## JSON file parser
* Construye un grafo a partir de una archivo JSON de aereopuertos del mundo. 


### Methods:
```cpp
void clear(); // Clears parser saved atributes

void readJSON(); // Parses JSON file and saves data into class
// NOTE: each derived class has its own readJSON method

void uGraphMake(UndirectedGraph<string, double> &tempGraph); // Adds the parsed data into the specified undirected graph

void dGraphMake(DirectedGraph<string, double> &tempGraph); // Adds the parsed data into the specified directed graph
```