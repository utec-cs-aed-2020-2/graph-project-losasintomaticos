#include <iostream>
#include <string.h>

//#include "Tester/tester.h"
//#include "Parser/parser.h"
#include "Graph/Undirectedgraph.h"
#include "Graph/Directedgraph.h"

using namespace std;

int main(int argc, char *argv[]) {
    //std::cout << "================================================" << std::endl;
    //std::cout << "MENU GRAPH TESTER" << std::endl;
    //std::cout << "================================================" << std::endl;
    
    //Tester::executeExamples();
    //Tester::executeParser();
    DirectedGraph<string, float> graph;
    graph.insertVertex("sds","Peru");
    graph.insertVertex("ssd","Bolivia");
    graph.insertVertex("a","Chile");
    graph.createEdge("sds","ssd",2);
    graph.createEdge("ssd","a",3);
    graph.createEdge("a","sds",4);
    graph.display();
    cout<<"\nDensity: "<<graph.density()<<endl;
    cout << "\nisDense(): " << std::boolalpha << graph.isDense() << endl;
    graph.deleteEdge("a","sds");
    graph.display();
    cout << "\nisStronglyConnected(): " << std::boolalpha << graph.isStronglyConnected() << endl;
    //graph.deleteVertex("sds");
    
    return EXIT_SUCCESS;
}