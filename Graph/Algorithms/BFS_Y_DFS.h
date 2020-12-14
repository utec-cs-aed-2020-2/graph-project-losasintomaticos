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
    UnDirectedGraph<TV, TE> undirectBFS;

public:
    BFSSearch(DirectedGraph<TV, TE> grafito):bGraphSearch(grafito){}
    BFSSearch(UnDirectedGraph<TV, TE> grafo_undir):undirectBFS(grafo_undir){}

    Vertex<TV, TE> *return_vertex(TV dato){
        for(auto i:bGraphSearch.vertexes){
            if (i.second->data == dato){
                return i.second;
            }
        }
    }

    DirectedGraph<TV, TE> dBFS(TV id) {
        DirectedGraph<TV, TE> dBFS;
        unordered_map<TV, bool> visited;
        unordered_map<TV,TV> father;

        for (auto v:bGraphSearch.vertexes) {
            visited.insert({v.second->data, false});
        }

        Vertex<TV, TE> *temp = return_vertex(id);
        queue<Vertex<TV, TE>*> q;
        q.push(temp);

        dBFS.insertVertex(bGraphSearch.returnID(temp->data),temp->data);

        while (!q.empty()) {
            Vertex<TV, TE> *vertice_begin = q.front();
            q.pop();

            for (auto adj:vertice_begin->edges) {
                    if (!visited[adj->vertexes[1]->data]){
                        father[adj->vertexes[1]->data]=adj->vertexes[0]->data;
                        visited[adj->vertexes[1]->data] = true;
                        if (dBFS.empty()) {
                            dBFS.insertVertex(bGraphSearch.returnID(adj->vertexes[1]->data), adj->vertexes[1]->data);
                        }
                        else{
                            dBFS.insertVertex(bGraphSearch.returnID(adj->vertexes[1]->data),adj->vertexes[1]->data);
                            dBFS.createEdge(bGraphSearch.returnID(father[adj->vertexes[1]->data]),bGraphSearch.returnID(adj->vertexes[1]->data), adj->weight);
                        }
                        q.push(adj->vertexes[1]);
                }
            }
        }
        return dBFS;
    }

    Vertex<TV, TE> *return_vertex2(TV dato){
        for(auto i:undirectBFS.vertexes){
            if (i.second->data == dato){
                return i.second;
            }
        }
    }

    UnDirectedGraph<TV, TE> uBFS(string id) {
        UnDirectedGraph<string, float> udBFS;
        unordered_map<TV, bool> visited;
        unordered_map<TV, TV> father;

        for (auto v:undirectBFS.vertexes) {
            visited.insert({v.second->data, false});
        }

        Vertex<TV, TE> *temp = return_vertex2(id);
        queue<Vertex<TV, TE> *> q;
        q.push(temp);

        udBFS.insertVertex(undirectBFS.returnID(temp->data), temp->data);
        visited[temp->data]=true;

        while (!q.empty()) {
            Vertex<TV, TE> *vertice_begin = q.front();
            q.pop();

            for (auto adj:vertice_begin->edges) {
                if (!visited[adj->vertexes[1]->data]) {
                    father[adj->vertexes[1]->data] = adj->vertexes[0]->data;
                    visited[adj->vertexes[1]->data] = true;
                    if (udBFS.empty()) {
                        udBFS.insertVertex(undirectBFS.returnID(adj->vertexes[1]->data), adj->vertexes[1]->data);
                    } else {
                        udBFS.insertVertex(undirectBFS.returnID(adj->vertexes[1]->data), adj->vertexes[1]->data);
                        udBFS.createEdge(undirectBFS.returnID(father[adj->vertexes[1]->data]),
                                        undirectBFS.returnID(adj->vertexes[1]->data), adj->weight);
                    }
                    q.push(adj->vertexes[1]);
                }
            }
        }
        return udBFS;
    }
};



template<typename TV, typename TE>
class DFSSearch : public Graph<TV, TE>{
private:
    DirectedGraph<TV, TE> dGraphSearch;
    UnDirectedGraph<string , float> undirectDFS;
    TV inicio;

public:
    DFSSearch(DirectedGraph<TV, TE> grafito): dGraphSearch(grafito){}
    DFSSearch(UnDirectedGraph<TV, TE> grafo_undir):undirectDFS(grafo_undir){}

    Vertex<TV, TE> *return_vertex(TV dato){
        for(auto i:dGraphSearch.vertexes){
            if (i.second->data == dato){
                return i.second;
            }
        }
    }

    DirectedGraph<TV, TE> dDFS(TV id) {
        DirectedGraph<TV, TE> dDFS;
        unordered_map<TV, bool> visited;
        unordered_map<TV, TV> father;
        unordered_map<TV, TE> weight;

        for (auto v:dGraphSearch.vertexes) {
            visited.insert({v.first, false});
        }

        Vertex<TV, TE> *temp = return_vertex(id);
        stack<Vertex<TV, TE>*> s;
        s.push(temp);
        while (!s.empty()) {
            Vertex<TV, TE> *vertice_begin = s.top();
            s.pop();

            if (!visited[vertice_begin->data]){
                visited[vertice_begin->data] = true;
                if (dDFS.empty()) {
                    dDFS.insertVertex(dGraphSearch.returnID(vertice_begin->data), vertice_begin->data);
                }
                else{
                    dDFS.insertVertex(dGraphSearch.returnID(vertice_begin->data),vertice_begin->data);
                    dDFS.createEdge(dGraphSearch.returnID(father[vertice_begin->data]),dGraphSearch.returnID(vertice_begin->data),weight[vertice_begin->data]);
                }
            }

            for (auto adj:vertice_begin->edges) {
                if (!visited[adj->vertexes[1]->data]){
                    father[adj->vertexes[1]->data]=adj->vertexes[0]->data;
                    weight[adj->vertexes[1]->data]=adj->weight;
                    s.push(adj->vertexes[1]);
                }
            }
        }
        return dDFS;
    }

    Vertex<TV, TE> *return_vertex2(TV dato){
        for(auto i:dGraphSearch.vertexes){
            if (i.second->data == dato){
                return i.second;
            }
        }
    }

    UnDirectedGraph<TV, TE> uDFS(string id) {
        UnDirectedGraph<TV, TE> dDFS;
        unordered_map<TV, bool> visited;
        unordered_map<TV, TV> father;
        unordered_map<TV, TE> weight;

        for (auto v:undirectDFS.vertexes) {
            visited.insert({v.first, false});
        }

        Vertex<TV, TE> *temp = return_vertex2(id);
        stack<Vertex<TV, TE>*> s;
        s.push(temp);
        while (!s.empty()) {
            Vertex<TV, TE> *vertice_begin = s.top();
            s.pop();

            if (!visited[vertice_begin->data]){
                visited[vertice_begin->data] = true;
                if (dDFS.empty()) {
                    dDFS.insertVertex(undirectDFS.returnID(vertice_begin->data), vertice_begin->data);
                }
                else{
                    dDFS.insertVertex(undirectDFS.returnID(vertice_begin->data),vertice_begin->data);
                    dDFS.createEdge(undirectDFS.returnID(father[vertice_begin->data]),undirectDFS.returnID(vertice_begin->data),weight[vertice_begin->data]);
                }
            }

            for (auto adj:vertice_begin->edges) {
                if (!visited[adj->vertexes[1]->data]){
                    father[adj->vertexes[1]->data]=adj->vertexes[0]->data;
                    weight[adj->vertexes[1]->data]=adj->weight;
                    s.push(adj->vertexes[1]);
                }
            }
        }
        return dDFS;
    }
};

#endif //GRAPH_PROJECT_LOSASINTOMATICOS_BFS_Y_DFS_H