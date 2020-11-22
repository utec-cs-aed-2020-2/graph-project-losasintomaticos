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

    struct Node{
        list<int> Id;
        list<string> Nombre;
        float Longitud{}, Latitud{}, euclid{};
    };

    ifstream peru_parse{R"(../Parser/Data/pe.json)"};
    IStreamWrapper isw {peru_parse};
    Document peru_doc{};
    StringBuffer buffer{};

//    template <typename T>
    void readJSON() {
        Node *temp = new Node();

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

        for (auto itr = peru_doc.Begin(); itr != peru_doc.End(); itr++){

            string temp_nombre = (*itr)["Name"].GetString();
            temp -> Nombre.push_back(temp_nombre);
            temp -> Longitud = stof((*itr)["Longitude"].GetString());
            int temp_id = stoi((*itr)["Airport ID"].GetString());
            temp -> Id.push_back(temp_id);
            temp -> Latitud = stof((*itr)["Latitude"].GetString());
            //temp -> Adyacentes = stoi((*itr)["destinations"].GetString());
            //cout << temp -> Adyacentes << endl;
            //euclid = sqrt((la2-la1)^2+(lo2-lo1)^2);
        }

        cout << "Los aeropuertos disponibles son los siguientes: " << endl;
        for (auto hola = temp -> Nombre.begin(); hola != temp -> Nombre.end(); hola++){
                cout << " - " << *hola << endl;
        }
    };// Parser JSON file and saves data into class

    void clear() {
        peru_doc.Swap(Value(kObjectType).Move());
        cout << "Archivo borrado exitosamente!" << endl;
    } //Clears parser saved values

    void uGraphMake(UnDirectedGraph<string, double> &tempGraph) {
    }

    void dGraphMake(DirectedGraph<string, double> &tempGraph) {
    }
};

#endif