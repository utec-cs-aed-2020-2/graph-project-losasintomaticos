#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <list>
#include <vector>
#include <fstream>
#include "Graph/UndirectedGraph.h"
#include "Graph/DirectedGraph.h"

using namespace std;
//Metodos a implementar

void clear(); //Clears parser saved values

void readJSON(){
    Json::Reader reader;
    Json::Value root;

    
} //Parser JSON file and saves data into class

void uGraphMake(UndirectedGraph<string, double> &tempGraph);

void dGraphMake(DirectedGraph<string, double> &tempGraph);

#endif