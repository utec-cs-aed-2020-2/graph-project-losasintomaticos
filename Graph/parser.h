#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <cmath>
#include <list>
#include <vector>
#include <fstream>
#include "algorithm"
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
        list<string> Nombre1, Nombre2;
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
            temp -> Nombre1.push_back(temp_nombre);
            temp -> Nombre2.push_back(temp_nombre);
            temp -> Longitud = stof((*itr)["Longitude"].GetString());
            int temp_id = stoi((*itr)["Airport ID"].GetString());
            temp -> Id.push_back(temp_id);
            temp -> Latitud = stof((*itr)["Latitude"].GetString());
            //temp -> Adyacentes = stoi((*itr)["destinations"].GetString());
            //cout << temp -> Adyacentes << endl;
            //euclid = sqrt((la2-la1)^2+(lo2-lo1)^2);
        }
        string Input1, Input2;
        cout << "Escoga el aeropuerto de partida: " << endl;
        for (auto hola = temp -> Nombre1.begin(); hola != temp -> Nombre1.end(); hola++){
                cout << " - " << *hola << " " << temp -> Longitud << " " << temp -> Latitud << endl;
        }
        cin >> Input1;
        cout << "Escoga el aeropuerto de llegada: " << endl;
        for (auto hola = temp -> Nombre2.begin(); hola != temp -> Nombre2.end(); hola++){
            cout << " - " << *hola << " " << temp -> Longitud << " " << temp -> Latitud << endl;
        }
        cin >> Input2;
        if ((std::find(temp -> Nombre1.begin(), temp -> Nombre1.end(), Input1) != temp -> Nombre1.end()) && (std::find(temp -> Nombre2.begin(), temp -> Nombre2.end(), Input2) != temp -> Nombre2.end())){
            cout << "Aeropuertos inválidos, cancelando..." << endl;
        }
        else{
            cout << "Aeropuertos válidos" << endl;
        }


    };// Parser JSON file and saves data into class

    void clear() {
        peru_doc.Swap(Value(kObjectType).Move());
        cout << "Archivo despejado exitosamente!" << endl;
    } //Clears parser saved values

    void uGraphMake(UnDirectedGraph<string, double> &tempGraph) {
        readJSON();

    }

    void dGraphMake(DirectedGraph<string, double> &tempGraph) {
        Node *temp = new Node();
        readJSON();
        //tempGraph.createEdge(Input1, Input2, Id);
    }
};

#endif