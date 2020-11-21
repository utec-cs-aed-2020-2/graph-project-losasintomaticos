#include <iostream>
#include <string.h>

//#include "Tester/tester.h"
//#include "Parser/parser.h"
#include "Graph/Undirectedgraph.h"
#include "Graph/Directedgraph.h"

using namespace std;

void testDirectedGraph();
void testUnDirectedGraph();

int main(int argc, char *argv[]) {
    uint8_t option_graph;
    std::cout << "================================================" << std::endl;
    std::cout << "MENU GRAPH TESTER" << std::endl;
    std::cout << "================================================" << std::endl;
    cout<<"Escoja una opcion"<<endl;
    cout<<"1. Grafo Dirigido"<<endl;
    cout<<"2. Grafo No Dirigido"<<endl;
    //Falta poner aca el execute examples y el executeparser
    cin>>option_graph;
    std::cout << "================================================" << std::endl;
    if(option_graph)
        testDirectedGraph();
    else
        testUnDirectedGraph();

    //Tester::executeExamples();
    //Tester::executeParser();    
    return EXIT_SUCCESS;
}

void testDirectedGraph()
{
    DirectedGraph<string, float> graph;
    string flag_loop="si",id_vertex,data_vertex;
    uint8_t opcion;
    while(flag_loop=="si")
    {
        cout<<"\nIngrese datos del vertice:"<<endl;
        cout<<"ID => ";
        cin>>id_vertex;
        cout<<"Dato => ";
        cin>>data_vertex;
        graph.insertVertex(id_vertex,data_vertex);
        cout<<"Quiere seguir introduciendo mas vertices? (si/no)"<<endl;
        cin>>flag_loop;
    }
    std::cout << "================================================" << std::endl;
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
        cout<<"Quiere seguir insertando aristas al grafo? (si/no)"<<endl;
        cin>>flag_loop;
    }
    int opcion_switch;
    std::cout << "================================================" << std::endl;
    cout<<"Escoja una funcion:"<<endl;
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
    cin>>opcion_switch;
    std::cout << "================================================" << std::endl;
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
            cin>>flag_loop;
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
            cin>>flag_loop;
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
            cout<<"Quiere conocer otro peso? (si/no)"<<endl;
            cin>>flag_loop;
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
        cout<<"\nEl grafo creado es"<<endl;
        graph.display();
        break;

    default:
        break;
    }

}

void testUnDirectedGraph()
{
    UnDirectedGraph<string, float> graph;
}