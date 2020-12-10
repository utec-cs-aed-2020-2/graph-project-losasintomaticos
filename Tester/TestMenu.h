#ifndef TESTMENU_H
#define TESTMENU_H

#include "../Graph/UndirectedGraph.h"
#include "../Graph/DirectedGraph.h"
#include "../Graph/Algorithms/Kruskal.h"
#include "../Graph/Algorithms/Prim.h"
#include "../Graph/Algorithms/Floyd.h"
#include "../Graph/Algorithms/Bellman.h"
#include "../Graph/Algorithms/BFS_Y_DFS.h"
#include <iostream>
#include <string.h>
#include <stdbool.h>
#include <algorithm>
#include <unordered_map>

using namespace std;

void testDirectedGraph();
string check_answer(string answer);
void testUnDirectedGraph();
void testPrimGraph();
void testKruskalGraph();
void testFloydGraph();
void testBellmanGraph();


void testUnDirectedGraph()
{
    UnDirectedGraph<string, float> graph;
    string flag_loop="si",id_vertex,data_vertex;
    while(flag_loop=="si")
    {
        cout<<"\nIngrese datos del vertice:"<<endl;
        cout<<"ID => ";
        cin>>id_vertex;
        cout<<"Dato => ";
        cin>>data_vertex;
        graph.insertVertex(id_vertex,data_vertex);
        cout<<"\nQuiere seguir introduciendo mas vertices? (si/no)"<<endl;
        cout<<"Respuesta => ";
        cin>>flag_loop;
        flag_loop=check_answer(flag_loop);
    }
    std::cout << "\n================================================" << std::endl;
    cout<<"Quiere insertar aristas al grafo? (si/no)"<<endl;
    cin>>flag_loop;
    while(flag_loop=="si")
    {
        uint16_t peso;
        string id1,id2;
        cout<<"\nInserte Arista:"<<endl;
        cout<<"ID1 => ";
        cin>>id1;
        cout<<"ID2 => ";
        cin>>id2;
        while (graph.findById(id1) && graph.findById(id2)!=1)
        {
            cout<<"\nIDs invalidos, intente de nuevo"<<endl;
            cout<<"\nInserte Arista:"<<endl;
            cout<<"ID1 => ";
            cin>>id1;
            cout<<"ID2 => ";
            cin>>id2;
        }

        cout<<"Peso de la arista => ";
        cin>>peso;
        graph.createEdge(id1,id2,peso);
        cout<<"\nQuiere seguir insertando aristas al grafo? (si/no)"<<endl;
        cout<<"Respuesta => ";
        cin>>flag_loop;
        flag_loop=check_answer(flag_loop);
    }
    int opcion_switch;
    bool flag_function=true;
    while(flag_function)
    {
        std::cout << "\n================================================" << std::endl;
        cout<<"\nEscoja una funcion:"<<endl;
        cout<<"\n1. Eliminar un vertice"<<endl;
        cout<<"2. Eliminar una arista"<<endl;
        cout<<"3. Conocer el peso entre aristas"<<endl;
        cout<<"4. Densidad del grafo"<<endl;
        cout<<"5. Verificar si el grafo pasa la densidad minima (0.5)"<<endl;
        cout<<"6. Verificar si el grafo esta conectado"<<endl;
        cout<<"7. Verificar si el grafo esta vacio"<<endl;
        cout<<"8. Eliminar el grafo"<<endl;
        cout<<"9. Mostrar el grafo"<<endl;
        cout<<"10. Salir"<<endl;
        cout<<"\nOpcion => ";
        cin>>opcion_switch;
        std::cout << "\n================================================" << std::endl;

        switch (opcion_switch)
        {
        case 1:
            flag_loop="si";
            while (flag_loop=="si")
            {
                cout<<"\nQue vertice quiere eliminar?"<<endl;
                cout<<"ID => ";
                cin>>id_vertex;
                graph.deleteVertex(id_vertex);
                cout<<"Quiere seguir eliminando vertices? (si/no)"<<endl;
                cout<<"Respuesta => ";
                cin>>flag_loop;
                flag_loop=check_answer(flag_loop);
            }
            break;

        case 2:
            flag_loop="si";
            while (flag_loop=="si")
            {
                string id1,id2;
                cout<<"\nQue arista quiere eliminar?"<<endl;
                cout<<"ID1 => ";
                cin>>id1;
                cout<<"ID2 => ";
                cin>>id2;
                graph.deleteEdge(id1,id2);
                cout<<"Quiere seguir eliminando aristas? (si/no)"<<endl;
                cout<<"Respuesta => ";
                cin>>flag_loop;
                flag_loop=check_answer(flag_loop);
            }
            break;
        
        case 3:
            flag_loop="si";
            while (flag_loop=="si")
            {
                string id1,id2;
                cout<<"\nElija la arista"<<endl;
                cout<<"ID1 => ";
                cin>>id1;
                cout<<"ID2 => ";
                cin>>id2;
                cout<<"El peso de la arista es => "<<graph(id1,id2);
                cout<<"\nQuiere conocer otro peso? (si/no)"<<endl;
                cout<<"Respuesta => ";
                cin>>flag_loop;
                flag_loop=check_answer(flag_loop);
            }
            break;
        
        case 4:
            cout<<"\nLa densidad del grafo es: "<<graph.density()<<endl;
            break;
        
        case 5:
            cout<<"\nEl grafo tiene la  densidad minima requerida? "<<std::boolalpha<<graph.isDense()<<endl;
            break;
        
        case 6:
            cout<<"\nEl grafo es conectado? "<<std::boolalpha<<graph.isConnected()<<endl;
            break;
        
        case 7:
            cout<<"\nEl grafo es vacio? "<<std::boolalpha<<graph.empty()<<endl;
            break;

        case 8:
            graph.empty();
            cout<<"\nGrafo eliminado!"<<endl;
            break;
        case 9:
            cout<<"\nEl grafo creado es\n"<<endl;
            graph.display();
            break;

        case 10:
            cout<<"\nHa salido del menu"<<endl;
            flag_function=false;
            break;
        default:
            cout<<"\nFuncion no valida!"<<endl;
            break;
        }

        if(flag_function!=false)
        {
            cout<<"\nQuieres probar otras funciones? (si/no)"<<endl;
            cout<<"Respuesta => ";
            cin>>flag_loop;
            flag_loop=check_answer(flag_loop);
            if(flag_loop=="no")
                flag_function=false;
        }
    }
}


void testDirectedGraph()
{
    DirectedGraph<string, float> graph;
    string flag_loop="si",id_vertex,data_vertex;
    while(flag_loop=="si")
    {
        cout<<"\nIngrese datos del vertice:"<<endl;
        cout<<"ID => ";
        cin>>id_vertex;
        cout<<"Dato => ";
        cin>>data_vertex;
        graph.insertVertex(id_vertex,data_vertex);
        cout<<"\nQuiere seguir introduciendo mas vertices? (si/no)"<<endl;
        cout<<"Respuesta => ";
        cin>>flag_loop;
        flag_loop=check_answer(flag_loop);
    }
    std::cout << "\n================================================" << std::endl;
    cout<<"Quiere insertar aristas al grafo? (si/no)"<<endl;
    cin>>flag_loop;
    while(flag_loop=="si")
    {
        uint16_t peso;
        string id1,id2;
        cout<<"\nInserte Arista:"<<endl;
        cout<<"ID1 => ";
        cin>>id1;
        cout<<"ID2 => ";
        cin>>id2;
        while (graph.findById(id1) && graph.findById(id2)!=1)
        {
            cout<<"\nIDs invalidos, intente de nuevo"<<endl;
            cout<<"\nInserte Arista:"<<endl;
            cout<<"ID1 => ";
            cin>>id1;
            cout<<"ID2 => ";
            cin>>id2;
        }

        cout<<"Peso de la arista => ";
        cin>>peso;
        graph.createEdge(id1,id2,peso);
        cout<<"\nQuiere seguir insertando aristas al grafo? (si/no)"<<endl;
        cout<<"Respuesta => ";
        cin>>flag_loop;
        flag_loop=check_answer(flag_loop);
    }
    int opcion_switch;
    bool flag_function=true;
    while(flag_function)
    {
        std::cout << "\n================================================" << std::endl;
        cout<<"\nEscoja una funcion:"<<endl;
        cout<<"\n1. Eliminar un vertice"<<endl;
        cout<<"2. Eliminar una arista"<<endl;
        cout<<"3. Conocer el peso entre aristas"<<endl;
        cout<<"4. Densidad del grafo"<<endl;
        cout<<"5. Verificar si el grafo pasa la densidad minima (0.5)"<<endl;
        cout<<"6. Verificar si el grafo esta conectado"<<endl;
        cout<<"7. Verificar si el grafo esta fuertemente conectado"<<endl;
        cout<<"8. Verificar si el grafo esta vacio"<<endl;
        cout<<"9. Eliminar el grafo"<<endl;
        cout<<"10. Mostrar el grafo"<<endl;
        cout<<"11. Salir"<<endl;
        cout<<"\nOpcion => ";
        cin>>opcion_switch;
        std::cout << "\n================================================" << std::endl;

        switch (opcion_switch)
        {
        case 1:
            flag_loop="si";
            while (flag_loop=="si")
            {
                cout<<"\nQue vertice quiere eliminar?"<<endl;
                cout<<"ID => ";
                cin>>id_vertex;
                graph.deleteVertex(id_vertex);
                cout<<"Quiere seguir eliminando vertices? (si/no)"<<endl;
                cout<<"Respuesta => ";
                cin>>flag_loop;
                flag_loop=check_answer(flag_loop);
            }
            break;

        case 2:
            flag_loop="si";
            while (flag_loop=="si")
            {
                string id1,id2;
                cout<<"\nQue arista quiere eliminar?"<<endl;
                cout<<"ID1 => ";
                cin>>id1;
                cout<<"ID2 => ";
                cin>>id2;
                graph.deleteEdge(id1,id2);
                cout<<"Quiere seguir eliminando aristas? (si/No)"<<endl;
                cout<<"Respuesta => ";
                cin>>flag_loop;
                flag_loop=check_answer(flag_loop);
            }
            break;
        
        case 3:
            flag_loop="si";
            while (flag_loop=="si")
            {
                string id1,id2;
                cout<<"\nElija la arista"<<endl;
                cout<<"ID1 => ";
                cin>>id1;
                cout<<"ID2 => ";
                cin>>id2;
                cout<<"El peso de la arista es => "<<graph(id1,id2);
                cout<<"\nQuiere conocer otro peso? (si/no)"<<endl;
                cout<<"Respuesta => ";
                cin>>flag_loop;
                flag_loop=check_answer(flag_loop);
            }
            break;
        
        case 4:
            cout<<"\nLa densidad del grafo es: "<<graph.density()<<endl;
            break;
        
        case 5:
            cout<<"\nEl grafo tiene la  densidad minima requerida? "<<std::boolalpha<<graph.isDense()<<endl;
            break;
        
        case 6:
            cout<<"\nEl grafo es conectado? "<<std::boolalpha<<graph.isConnected()<<endl;
            break;
        
        case 7:
            cout<<"\nEl grafo es fuertemente conectado? "<<std::boolalpha<<graph.isStronglyConnected()<<endl;
            break;
        
        case 8:
            cout<<"\nEl grafo es vacio? "<<std::boolalpha<<graph.empty()<<endl;
            break;

        case 9:
            graph.empty();
            cout<<"\nGrafo eliminado!"<<endl;
            break;
        case 10:
            cout<<"\nEl grafo creado es\n"<<endl;
            graph.display();
            break;

        case 11:
            cout<<"\nHa salido del menu"<<endl;
            flag_function=false;
            break;
        default:
            cout<<"\nFuncion no valida!"<<endl;
            break;
        }

        if(flag_function!=false)
        {
            cout<<"\nQuieres probar otras funciones? (si/no)"<<endl;
            cout<<"Respuesta => ";
            cin>>flag_loop;
            flag_loop=check_answer(flag_loop);
            if(flag_loop=="no")
                flag_function=false;
        }
    }
}

string changeUPtoLOW(string answer)
{
    std::for_each(answer.begin(), answer.end(), [](char & c) {
        c = ::tolower(c);
    });
    return answer;
}

string check_answer(string answer)
{
    answer = changeUPtoLOW(answer);
    while(answer!="si" && answer!="no")
    {
        cout<<"\nRespuesta incorrecta, por favor digite de nuevo (si/no)"<<endl;
        cout<<"Respuesta => ";
        cin>>answer;
    }
    return answer;
}

void testPrimGraph()
{
    UnDirectedGraph<string, float> graph;
    graph.insertVertex("1", "A");
    graph.insertVertex("2", "C");
    graph.insertVertex("3", "D");
    graph.insertVertex("4", "F");
    graph.insertVertex("5", "E");
    graph.insertVertex("6", "G");

    graph.createEdge("1", "2", 12);   
    graph.createEdge("2","3",2);
    graph.createEdge("2","4",4);
    graph.createEdge("3","5",7);
    graph.createEdge("5","6",15);
    graph.createEdge("4","6",10);
    graph.createEdge("4","5",1);
    std::cout << "\n\n================================================" << std::endl;
    std::cout << "                 ALGORITMO PRIM" << std::endl;
    std::cout << "================================================" << std::endl;
    cout<<"El Grafo de Ejemplo es el siguiente:"<<endl;
    graph.display();
    cout<<"\nAplicando el Algoritmo PRIM:"<<endl;
    Prim<string,float> grafito(graph,"A");
    UnDirectedGraph<string,float> grafes = grafito.apply();
    grafes.display();
    std::cout << "\n================================================" << std::endl;
}

void testKruskalGraph()
{
    UnDirectedGraph<string, float> graph;
    graph.insertVertex("1", "A");
    graph.insertVertex("2", "C");
    graph.insertVertex("3", "D");
    graph.insertVertex("4", "F");
    graph.insertVertex("5", "E");
    graph.insertVertex("6", "G");

    graph.createEdge("1", "2", 12);   
    graph.createEdge("2","3",2);
    graph.createEdge("2","4",4);
    graph.createEdge("3","5",7);
    graph.createEdge("5","6",15);
    graph.createEdge("4","6",10);
    graph.createEdge("4","5",1);
    std::cout << "\n\n================================================" << std::endl;
    std::cout << "               ALGORITMO KRUSKAL" << std::endl;
    std::cout << "================================================" << std::endl;
    cout<<"El Grafo de Ejemplo es el siguiente:"<<endl;
    graph.display();
    cout<<"\nAplicando el Algoritmo Kruskal:"<<endl;
    Kruskal<string,float> grafito(graph);
    DirectedGraph<string,float> grafes = grafito.apply();
    grafes.display();
    std::cout << "\n================================================" << std::endl;
}

void testFloydGraph()
{
    DirectedGraph<string, float> graph;
    graph.insertVertex("1","1");
    graph.insertVertex("2","2");
    graph.insertVertex("3","3");
    graph.insertVertex("4","4");
    graph.insertVertex("5","5");

    graph.createEdge("1","3",6);
    graph.createEdge("1","4",3);
    graph.createEdge("2","1",3);
    graph.createEdge("3","4",2);
    graph.createEdge("4","2",1);
    graph.createEdge("4","3",1);
    graph.createEdge("5","2",4);
    graph.createEdge("5","4",2);

    std::cout << "\n\n================================================" << std::endl;
    std::cout << "            ALGORITMO Floyd Warshall" << std::endl;
    std::cout << "================================================" << std::endl;
    cout<<"El Grafo de Ejemplo es el siguiente:"<<endl;
    graph.display();
    cout<<"\nAplicando el Algoritmo Kruskal:\n"<<endl;
    Floyd<string,float> grafito(graph);
    int** floyd;
    floyd = grafito.apply();

    //grafes.display();
    std::cout << "\n================================================" << std::endl;
}


void testBellmanGraph() {
    DirectedGraph<string, float> graph;
    graph.insertVertex("1", "1");
    graph.insertVertex("2", "2");
    graph.insertVertex("3", "3");
    graph.insertVertex("4", "4");
    graph.insertVertex("5", "5");
    graph.insertVertex("6", "6");

    graph.createEdge("1", "2", 1);
    graph.createEdge("1", "3", 2);
    graph.createEdge("1", "4", 8);
    graph.createEdge("3", "4", 5);
    graph.createEdge("2", "5", 3);
    graph.createEdge("3", "5", 3);
    graph.createEdge("5", "6", 4);
    graph.createEdge("3", "6", 8);
    graph.createEdge("4", "6", 12);
    std::cout << "\n\n================================================" << std::endl;
    std::cout << "            ALGORITMO Bellman Ford" << std::endl;
    std::cout << "================================================" << std::endl;
    cout << "El Grafo de Ejemplo es el siguiente:" << endl;
    graph.display();
    cout << "\nAplicando el Algoritmo Bellman Ford:\n" << endl;
    Bellman<string, float> grafito(graph);
    unordered_map<int, float> bellmanMap = grafito.apply("1");
    std::cout << "\n================================================" << std::endl;
}

void testBFSGraph()
{
    DirectedGraph<string, float> graph;
    graph.insertVertex("0", "A");
    graph.insertVertex("1", "B");
    graph.insertVertex("2", "C");
    graph.insertVertex("3", "D");
    graph.insertVertex("4", "E");
    graph.insertVertex("5", "F");

    graph.createEdge("0", "1", 12);
    graph.createEdge("0", "2", 2);
    graph.createEdge("1", "2", 4);
    graph.createEdge("2", "0", 7);
    graph.createEdge("2", "3", 15);
    graph.createEdge("3", "3", 10);
    graph.createEdge("4", "5", 1);


    std::cout << "\n\n================================================" << std::endl;
    std::cout << "            ALGORITMO Breath First Search" << std::endl;
    std::cout << "================================================" << std::endl;
    cout << "El Grafo de Ejemplo es el siguiente:" << endl;
    graph.display();
    cout << "\nAplicando el Algoritmo BFS:\n" << endl;
    BFSSearch<string, float> grafito(graph);
    DirectedGraph<string, float> grafes = grafito.BFS("3");
    grafes.display();
    std::cout << "\n================================================" << std::endl;
}

void testDFSGraph()
{
    DirectedGraph<string, float> graph;
    graph.insertVertex("0", "A");
    graph.insertVertex("1", "B");
    graph.insertVertex("2", "C");
    graph.insertVertex("3", "D");
    graph.insertVertex("4", "E");
    graph.insertVertex("5", "F");

    graph.createEdge("0", "1", 12);
    graph.createEdge("0", "2", 2);
    graph.createEdge("1", "2", 4);
    graph.createEdge("2", "0", 7);
    graph.createEdge("2", "3", 15);
    graph.createEdge("3", "3", 10);
    graph.createEdge("4", "5", 1);

    std::cout << "\n\n================================================" << std::endl;
    std::cout << "            ALGORITMO Depth First Search" << std::endl;
    std::cout << "================================================" << std::endl;
    cout << "El Grafo de Ejemplo es el siguiente:" << endl;
    graph.display();
    cout << "\nAplicando el Algoritmo BFS:\n" << endl;
    DFSSearch<string, float> grafito(graph);

    DirectedGraph<string, float> grafes = grafito.DFS("0");

    grafes.display();
    std::cout << "\n================================================" << std::endl;
}

#endif