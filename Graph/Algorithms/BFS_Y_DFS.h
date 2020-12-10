#ifndef GRAPH_PROJECT_LOSASINTOMATICOS_BFS_Y_DFS_H
#define GRAPH_PROJECT_LOSASINTOMATICOS_BFS_Y_DFS_H

#include "../DirectedGraph.h"
#include "../UndirectedGraph.h"
#include <queue>
#include <stack>
#include <unordered_map>
using namespace std;

template<typename TV, typename TE>
class BFSSearch;

template<typename TV, typename TE>
class DFSSearch;

/*****************************************/

template<typename TV, typename TE>
class BFSSearch : public Graph<TV, TE>{
private:
    DirectedGraph<TV, TE> bGraphSearch;

public:
    BFSSearch(DirectedGraph<TV, TE> grafito):bGraphSearch(grafito){}

    DirectedGraph<TV, TE> BFS(string id) {
        DirectedGraph<TV, TE> dBFS;
        unordered_map<TV, bool> visited;

        for (auto v:bGraphSearch.vertexes) {
            visited.insert({v.first, false});
        }

        Vertex<TV, TE> *temp = bGraphSearch.vertexes[id];
        queue<Vertex<TV, TE>*> q;
        q.push(temp);

        while (!q.empty()) {
            Vertex<TV, TE> *vertice_begin = q.front();
            cout << vertice_begin->data << " " << endl;
            q.pop();
            list<Edge<TV, TE> *> edge2 = vertice_begin->edges;

            for (auto &adj:vertice_begin->edges) {
                    if (!visited[adj->vertexes[1]->id]){
                        visited[adj->vertexes[1]->id] = true;
                        q.push(adj->vertexes[1]);
                }
            }
        }
    }
};

template<typename TV, typename TE>
class DFSSearch : public Graph<TV, TE>{
private:
    DirectedGraph<TV, TE> dGraphSearch;

public:
    DFSSearch(DirectedGraph<TV, TE> grafito): dGraphSearch(grafito){}

    DirectedGraph<TV, TE> DFS(string id) {
        DirectedGraph<TV, TE> dDFS;
        unordered_map<TV, bool> visited;

        for (auto v:dGraphSearch.vertexes) {
            visited.insert({v.first, false});
        }

        Vertex<TV, TE> *temp = dGraphSearch.vertexes[id];
        stack<Vertex<TV, TE>*> s;
        s.push(temp);
        while (!s.empty()) {
            Vertex<TV, TE> *vertice_begin = s.top();
            s.pop();

            if (!visited[vertice_begin->id]){
                cout << vertice_begin->data << " " << endl;
                visited[vertice_begin->id] = true;
            }

            for (auto &adj:vertice_begin->edges) {
                if (!visited[adj->vertexes[1]->id]){
                    s.push(adj->vertexes[1]);
                }
            }
        }
    }
};

template<typename TV, typename TE>
class strongConnected : public Graph<TV, TE>{
private:
    DirectedGraph<TV, TE> strong;

public:
    strongConnected(DirectedGraph<TV, TE> grafito): strong(grafito){}

    DirectedGraph<TV, TE> dstrong(){
        DirectedGraph<TV, TE> dDFS;
        unordered_map<TV, bool> visited;
        stack<Vertex<TV, TE>*> s;

        for (auto v:strong.vertexes) {
            visited.insert({v.first, false});
        }


    }

};

#endif //GRAPH_PROJECT_LOSASINTOMATICOS_BFS_Y_DFS_H