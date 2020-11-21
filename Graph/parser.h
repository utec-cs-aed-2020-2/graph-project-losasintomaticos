#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <cmath>
#include <list>
#include <vector>
#include <fstream>
#include "graph.h"
#include "UndirectedGraph.h"
#include "DirectedGraph.h"
#include "../include/rapidjson/document.h"
#include "../include/rapidjson/ostreamwrapper.h"
#include "../include/rapidjson/stringbuffer.h"
#include "../include/rapidjson/istreamwrapper.h"

using namespace std;
using namespace rapidjson;
//Metodos a implementar

template<typename TV, typename TE>
class AirportParser : public Graph<TV, TE> {
public:
    AirportParser(): Graph<TV, TE>(){}
    ~AirportParser()= default;

    string Ciudad, Nombre;
    float Longitud, Latitud;
    int Id, Adyacentes;
    ifstream peru_parse{R"(Parser\Data\pe.json)"};
    IStreamWrapper isw {peru_parse};
    Document peru_doc{};
    StringBuffer buffer{};

    void readJSON() {

        if (!peru_parse.is_open()) {
            cerr << "No se puede leer el archivo seleccionado";
            return;
        }

        if (peru_doc.HasParseError()) {
            cout << "Error : " << peru_doc.GetParseError() << '\n'
                 << "Offset: " << peru_doc.GetErrorOffset() << '\n';
            return;
        }

        peru_doc.ParseStream(isw);

        for (auto itr = peru_doc.Begin(); itr != peru_doc.End(); ++itr) {
            Ciudad = (*itr)["City"].GetString(), Nombre = (*itr)["Name"].GetString();
            Longitud = stof((*itr)["Longitude"].GetString()), Latitud = stof((*itr)["Latitude"].GetString());
            Id = stoi((*itr)["Airport Id"].GetString()), Adyacentes = stoi((*itr)["destinations"].GetString());
        }

    };// Parser JSON file and saves data into class

    void clear() {
        peru_doc.Clear();
    } //Clears parser saved values

    void uGraphMake(UnDirectedGraph<string, double> &tempGraph) {

    }

    void dGraphMake(DirectedGraph<string, double> &tempGraph) {

    }
};

#endif