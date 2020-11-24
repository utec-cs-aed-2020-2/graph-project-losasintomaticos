#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <cmath>
#include <array>
#include <list>
#include <vector>
#include <fstream>
#include <unordered_map>
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
class AirportParser;

template<typename TV, typename TE>
struct Node;

template<typename TV, typename TE>
struct Node{
    vector<string> Adyacentes;
    string Nombre;
    unordered_map<string, float> euclid_sucio;
    float Longitud = 0, Latitud = 0;
    Node(string name, float lo, float la, vector<string> adya){
        this -> Nombre = name;
        this -> Longitud = lo;
        this -> Latitud = la;
        this -> Adyacentes = adya;
    }
};

template<typename TV, typename TE>
class AirportParser : public Graph<TV, TE> {
private:
    unordered_map<string, Node<TV,TE>*> map_general;

public:
    AirportParser(): Graph<TV, TE>(){}
    ~AirportParser()= default;


    ifstream peru_parse{R"(../Parser/Data/pe_deleted.json)"};
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

        for (auto itr = peru_doc.Begin(); itr != peru_doc.End(); itr++){

            string temp_nombre = ((*itr)["Name"].GetString());
            float Longitud = stof((*itr)["Longitude"].GetString());
            string temp_id = ((*itr)["Airport ID"].GetString());
            float Latitud = stof((*itr)["Latitude"].GetString());
            const Value& destinations = (*itr)["destinations"];
            vector<string> Adyacentes = Get_ID(destinations);
            auto *temp = new Node<TV, TE>(temp_nombre, Longitud, Latitud, Adyacentes);
            map_general[temp_id] = temp;
//            for (auto it = temp -> Adyacentes.begin(); it != temp -> Adyacentes.end(); it++){
//                cout << "\n" << *it;
//            }
        }
        cout << "ra" << endl;
        euclid(map_general);
        cout << "ra1" << endl;
        for (auto p:map_general){
            cout << p.first << " => " << p.second -> Nombre << endl;
            for(auto o:p.second -> euclid_sucio){
                cout << o.first << " => " << p.second << endl;
            }
        }

//        string Input1, Input2;
//        cout << "\nEscoga el aeropuerto de partida: " << endl;
//        for (auto hola = temp -> Nombre1.begin(); hola != temp -> Nombre1.end(); hola++){
//                cout << " - " << *hola << endl;
//        }
//
//        cout << "\nOpcion => ";
//        cin >> Input1;
//        cout << "Escoga el aeropuerto de llegada: " << endl;
//        for (auto hola = temp -> Nombre2.begin(); hola != temp -> Nombre2.end(); hola++){
//            cout << " - " << *hola << endl;
//        }
//
//        cout << "\nOpcion => ";
//        cin >> Input2;
//        if ((std::find(temp -> Nombre1.begin(), temp -> Nombre1.end(), Input1) != temp -> Nombre1.end()) && (std::find(temp -> Nombre2.begin(), temp -> Nombre2.end(), Input2) != temp -> Nombre2.end())){
//            cout << "Aeropuertos inválidos, cancelando..." << endl;
//        }
//        else{
//            cout << "Aeropuertos válidos" << endl;
//        }


    };// Parser JSON file and saves data into class

    void clear_parser() {
        peru_doc.Swap(Value(kObjectType).Move());
        cout << "Archivo despejado exitosamente!" << endl;
    } //Clears parser saved values

    void uGraphMake(UnDirectedGraph<string, double> &tempGraph) {
        readJSON();

    }

    void dGraphMake(DirectedGraph<string, double> &tempGraph) {
        //Node *temp = new Node();
        readJSON();
        //tempGraph.createEdge(Input1, Input2, Id);
    }

    vector<string> Get_ID(const Value& adyacentes){
        vector<string> temp_id;
        for (int i = 0; i < adyacentes.Size(); i++){
            string temp = adyacentes[i].GetString();
            temp_id.push_back(temp);
        }
        return temp_id;
    }

    void euclid(unordered_map<string, Node<TV,TE>*> map_general){
        for (auto p:map_general) {
            cout << p.second -> Nombre << endl;
            vector<string> temp = p.second -> Adyacentes;
            for (auto i = temp.begin(); i != temp.end() ; ++i) {
                cout << *i << endl;
                float la2 = get_la(*i);
                cout << la2 << endl;
                float lo2 = get_lo(*i);
                cout << lo2 << endl;
                float euclid = sqrt(powf((la2 - p.second -> Latitud), 2) + powf((lo2 - p.second -> Longitud),2));
                p.second -> euclid_sucio[*i] = euclid;
            }
        }
    }

    float get_la(string id){
        auto *temp = map_general[id];
        return temp -> Latitud;
    }

    float get_lo(string id){
        auto *temp = map_general[id];
        return temp -> Longitud;
    }
};
#endif