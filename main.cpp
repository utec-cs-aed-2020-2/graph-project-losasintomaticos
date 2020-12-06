#include <iostream>
#include <cstring>
#include "stdint.h"
#include "Tester/TestMenu.h"
#include "Graph/parser.h"
#include "Graph/UndirectedGraph.h"
#include "Graph/DirectedGraph.h"
#include "Graph/Algorithms/Prim.h"
#include "Graph/Algorithms/Kruskal.h"


using namespace std;

void testDirectedGraph();
void testUnDirectedGraph();
void testPrimGraph();    
void testKruskalGraph();  
string check_answer(string answer);
void testAirportParser();

int main(int argc, char *argv[]) {
    int option_graph;
    string flag_all ="si";
    while(flag_all=="si")
    {
        std::cout << "================================================" << std::endl;
        std::cout << "              MENU GRAPH TESTER" << std::endl;
        std::cout << "================================================" << std::endl;
        cout<<"\nEscoja una opcion"<<endl;
        cout<<"1. Grafo Dirigido"<<endl;
        cout<<"2. Grafo No Dirigido"<<endl;
        cout<<"3. Grafo a base de documento JSON"<<endl;
        cout<<"4. Algoritmo Prim"<<endl;
        cout<<"5. Algoritmo Kruskal"<<endl;
        cout<<"6. Algoritmo Floyd Warshall"<<endl;
        cout<<"7. Algoritmo Bellman Ford"<<endl;
        cout<<"8. Algoritmo BFS"<<endl;
        cout<<"9. Salir"<<endl;
        cout<<"\nOpcion => ";
        cin>>option_graph;
        while(option_graph>8 || option_graph<1)
        {
            cout<<"\nOpcion incorrecta, por favor digita una correcta opcion";
            cout<<"\nOpcion => ";
            cin>>option_graph;
        }
        std::cout << "\n================================================" << std::endl;
        if(option_graph==1)
            testDirectedGraph();
        else if(option_graph==2)
            testUnDirectedGraph();

        else if (option_graph == 3)
            testAirportParser();

        else if(option_graph==4)
            testPrimGraph();
        else if(option_graph==5)
            testKruskalGraph();
        else if(option_graph==6)
            testFloydGraph();
        else if(option_graph==7)
            testBellmanGraph();
        else if (option_graph==8)
            testBFSGraph();
        else
            flag_all="no";
        
        if(flag_all!="no")
        {
            cout<<"\nQuieres probar otras opciones? (si/no)"<<endl;
            cout<<"Respuesta => ";
            cin>>flag_all;
            flag_all=check_answer(flag_all);
        }
        cout<<"\n\n";
    }   
    return EXIT_SUCCESS;
}

void testAirportParser() {
    AirportParser<string, float> graph_parse;
    int opcion;
    cout << "Elija la opcion para que sea un grafo dirigido o no dirigido a base de un archivo JSON: " << endl;
    cout << "1. Grafo no dirigido a base  aeropuertos del Peru" << endl;
    cout << "2. Grafo dirigido a base de aeropuertos del Peru" << endl;
    cout << "\nOpcion => ";
    cin >> opcion;
    if (opcion == 1){
        UnDirectedGraph<string, float> undirectedjson;
        graph_parse.uGraphMake(undirectedjson);
        undirectedjson.display();
    }
    else if(opcion == 2){
        DirectedGraph<string, float> directedjson;
        graph_parse.dGraphMake(directedjson);
        directedjson.display();
    }
}