#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <list>
#include <vector>
#include <fstream>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "UndirectedGraph.h"
#include "DirectedGraph.h"

using namespace std;
using namespace rapidjson;
//Metodos a implementar

void clear(){

} //Clears parser saved values

void readJSON(){
    Document mundo_parse;
    Document peru_parse;
    peru_parse.Parse("./pe.json");
    mundo_parse.Parse("./airports.json");
} //Parser JSON file and saves data into class

void uGraphMake(UnDirectedGraph<string, double> &tempGraph){

}

void dGraphMake(DirectedGraph<string, double> &tempGraph){

}

#endif