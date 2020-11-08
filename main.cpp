#include <iostream>
#include <string.h>

//#include "Tester/tester.h"
//#include "Parser/parser.h"
#include "Graph/Undirectedgraph.h"

using namespace std;

int main(int argc, char *argv[]) {
    //std::cout << "================================================" << std::endl;
    //std::cout << "MENU GRAPH TESTER" << std::endl;
    //std::cout << "================================================" << std::endl;
    
    //Tester::executeExamples();
    //Tester::executeParser();
    UnDirectedGraph<string, float> graph;
    graph.insertVertex("sds","Peru");
    graph.insertVertex("ssd","Bolivia");
    graph.createEdge("sds","ssd",2);
    graph.display();
    //graph.deleteVertex("sds");
    
    return EXIT_SUCCESS;
}