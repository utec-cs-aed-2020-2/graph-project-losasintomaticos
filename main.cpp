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
        cout<<"4. Grafo Prim"<<endl;
        cout<<"5. Grafo Kruskal"<<endl;
        cout<<"6. Salir"<<endl;
        cout<<"\nOpcion => ";
        cin>>option_graph;
        while(option_graph>6 || option_graph<1)
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
        else
            flag_all="No";
        
        if(flag_all!="No")
        {
            cout<<"\nQuieres probar otras opciones? (Si/No)"<<endl;
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

/* void testDirectedGraph()
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
    cout<<"Quiere insertar aristas al grafo? (Si/No)"<<endl;
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
} */

/* void testUnDirectedGraph()
{
    UnDirectedGraph<string, float> graph;
} */

/* string check_answer(string answer)
{
    while(answer!="si" && answer!="no")
    {
        cout<<"\nRespuesta incorrecta, por favor digite de nuevo (si/no)"<<endl;
        cout<<"Respuesta => ";
        cin>>answer;
    }
    return answer;
} */



/* void testPrimGraph()
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
} */