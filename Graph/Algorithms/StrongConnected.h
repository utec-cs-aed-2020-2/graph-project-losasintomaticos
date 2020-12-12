#ifndef GRAPH_PROJECT_LOSASINTOMATICOS_STRONGCONNECTED_H
#define GRAPH_PROJECT_LOSASINTOMATICOS_STRONGCONNECTED_H

#include "../DirectedGraph.h"
#include "../UndirectedGraph.h"
#include <queue>
#include <stack>
#include <unordered_map>
using namespace std;

template<typename TV, typename TE>
class strongConnected;

template<typename TV, typename TE>
class strongConnected : public Graph<TV, TE>{
private:
    DirectedGraph<TV, TE> dstrong;

public:
    strongConnected(DirectedGraph<TV, TE> grafito): dstrong(grafito){}

//    DirectedGraph<TV, TE> getTranspose() {
//        DirectedGraph<TV, TE> transpose;
//        Vertex<TV, TE> *vertice_begin2 = dstrong.vertexes[0];
//        for (auto &trans:vertice_begin2->edges) {
//                transpose.createEdge(trans->vertexes[2]->id,trans->vertexes[1]->id,trans->weight);
//            }
//        return transpose;
//    }

//    DirectedGraph<TV, TE> SCC(string id) {
//        //DirectedGraph<TV, TE> dDFS;
//        unordered_map<TV, bool> visited;
//
//        for (auto v:dstrong.vertexes) {
//            visited.insert({v.first, false});
//        }
//
//        Vertex<TV, TE> *temp = dstrong.vertexes[id];
//        stack<Vertex<TV, TE>*> s;
//        s.push(temp);
//        while (!s.empty()) {
//            Vertex<TV, TE> *vertice_begin = s.top();
//            s.pop();
//
//            if (!visited[vertice_begin->id]){
//                //cout << vertice_begin->data << " " << endl;
//                visited[vertice_begin->id] = true;
//            }
//
//            for (auto &adj:vertice_begin->edges) {
//                if (!visited[adj->vertexes[1]->id]){
//                    s.push(adj->vertexes[1]);
//                }
//            }
//        }
//
//        DirectedGraph<TV, TE> grafo2;
//        grafo2.display();
//        DirectedGraph<TV, TE> transpose;
//        //Vertex<TV, TE> *vertice_begin2 = dstrong.vertexes[0];
//        for (auto vert:dstrong.vertexes) {
//            Vertex<TV,TE>* vertice = vert.second;
//            transpose.insertVertex(vertice->id, vertice->data);
//            list<Edge<TV, TE>*> edge_temp = vertice->edges;
//
//            for(auto itr:edge_temp)
//            {
//                cout<<"kaka"<<endl;
//                transpose.createEdge(itr->vertexes[1]->data, itr->vertexes[0]->data, itr->weight);
//            }
//            cout<<"kaka2"<<endl;
//        }
//
//
//
//        for (auto &trans:vertice_begin2->edges) {
//                transpose.createEdge(trans->vertexes[2]->id,trans->vertexes[1]->id,trans->weight);
//            }
//        transpose.display();
//        unordered_map<TV, bool> visited2;
//
//        for (auto v:grafo2.vertexes) {
//            visited2.insert({v.first, false});
//        }
//        for (auto i:visited) {
//            if (i.second == true){
//                Vertex<TV, TE> *temp1 = grafo2.vertexes[i.first];
//                stack<Vertex<TV, TE>*> s1;
//                s1.push(temp1);
//                while (!s1.empty()) {
//                    Vertex<TV, TE> *vertice_begin = s1.top();
//                    s1.pop();
//
//                    if (!visited2[vertice_begin->id]){
//                        cout << vertice_begin->data << " " << endl;
//                        visited2[vertice_begin->id] = true;
//                        if (vertice_begin->id == id){
//                            cout << vertice_begin->id << " " << endl;
//                            break;
//
//                        }
//                    }
//
//                    for (auto &adj:vertice_begin->edges) {
//                        if (!visited2[adj->vertexes[1]->id]){
//                            s1.push(adj->vertexes[1]);
//                        }
//                    }
//                }
//            }
//        }
//    }
//
//        Vertex<TV, TE> *vertice_begin1 = strong.vertexes[id];
//
//        for (auto fill:strong.vertexes) {
//            if (!visited[vertice_begin1->id]){
//                relleno(id, visited, s, vertice_begin1);
//            }
//        }
//
//        DirectedGraph<TV, TE> grafoso = getTranspose();
//
//        for (auto v:strong.vertexes) {
//            visited.insert({v.first, false});
//        }
//
//
//    }
//
//    void relleno(string id, unordered_map<TV, bool> visited, stack<Vertex<TV, TE>*> s, Vertex<TV, TE> *vertice_begin){
//        visited[vertice_begin->id] = true;
//        //cout << vertice_begin->data << " " << endl; imprimir el nodo
//        for (auto &adj:vertice_begin->edges) {
//            if (!visited[adj->vertexes[1]->id]){
//                relleno(id, visited, s, vertice_begin);
//            }
//        }
//        s.push(vertice_begin->data);
//    }
//
//    DirectedGraph<TV, TE> getTranspose() {
//        DirectedGraph<TV, TE> transpose;
//        Vertex<TV, TE> *vertice_begin2;
//        for (auto &trans:vertice_begin2->edges) {
//            transpose.vertexes->push_back(trans);
//        }
//        return transpose;
//    }
//
//    void DFS(string id, unordered_map<TV, bool> visited, Vertex<TV, TE> *vertice_begin){
//        visited[vertice_begin->id] = true;
//        for (auto &adj:vertice_begin->edges) {
//            if (!visited[adj->vertexes[1]->id]){
//                DFS(adj, visited, vertice_begin);
//            }
//        }
//    }

};

#endif //GRAPH_PROJECT_LOSASINTOMATICOS_STRONGCONNECTED_H
