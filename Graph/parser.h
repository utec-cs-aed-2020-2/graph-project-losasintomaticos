#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <list>
#include <vector>
#include <fstream>
#include "UndirectedGraph.h"
#include "DirectedGraph.h"
#include "rapidjson/document.h"
#include "rapidjson/ostreamwrapper.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/istreamwrapper.h"

using namespace std;
using namespace rapidjson;
//Metodos a implementar

void clear(){

} //Clears parser saved values

void readJSON(){
    ifstream peru_parse {R"(pe.json)"};
    if (!peru_parse.is_open()){
        cerr << "No se puede leer el archivo seleccionado";
        return;
    }

    IStreamWrapper isw { peru_parse };
    Document peru_doc {};
    peru_doc.ParseStream(isw);
    StringBuffer buffer {};

    if (peru_doc.HasParseError()){
        cout << "Error : " << peru_doc.GetParseError() << '\n'
             << "Offset: " << peru_doc.GetErrorOffset() << '\n';
        return;
    }

    for (auto itr = peru_doc.Begin(); itr != peru_doc.End(); ++itr){
        string Ciudad = (*itr)["City"].GetString(), Nombre = (*itr)["Name"].GetString();
        float Longitud = stof((*itr)["Longitude"].GetString()), Latitud = stof((*itr)["Latitude"].GetString());
        int Id = stoi((*itr)["Airport Id"].GetString()), Adyacentes = stoi((*itr)["destinations"].GetString());
    }
} //Parser JSON file and saves data into class

void uGraphMake(UnDirectedGraph<string, double> &tempGraph){

}

void dGraphMake(DirectedGraph<string, double> &tempGraph){

}

#endif