#ifndef GRAPH_PROJECT_LOSASINTOMATICOS_BFS_Y_DFS_H
#define GRAPH_PROJECT_LOSASINTOMATICOS_BFS_Y_DFS_H

#include "../DirectedGraph.h"
#include "../UndirectedGraph.h"
#include <queue>
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

    DirectedGraph<TV, TE> BFS(){
        DirectedGraph<TV, TE> dBFS;
        unordered_map<TV,unordered_map<TV,int>> visited;

        for (auto i:bGraphSearch.vertexes -> data) {
            queue<Vertex<TV,TE>*> q;
            q.push(i);
            visited[i] = false;

            while (!q.empty()){
                Vertex<TV,TE>* vertice = q.front();
                q.pop();
                cout << i << " " << endl;
                list<Edge<TV, TE>*> edge = vertice -> edges;

                for (auto itr:edge) {
                    if (!visited[itr.second -> data][itr -> vertexes[1]] -> data){
                        q.push(itr -> vertexes[1]);
                        visited[itr -> vertexes[1] -> data][itr.second -> data] = true;
                    }
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

    DirectedGraph<TV, TE> dfs_prev(DirectedGraph<TV, TE> &grafito, Vertex<TV, TE>*vertice, unordered_map<string, int> &visited){
        string id1;
        visited[vertice -> data] = true;
        cout << vertice -> data << " " << endl;

        list<Edge<TV, TE>*> edge = vertice -> edges;

        for (auto p:edge) {
            if (!visited[p.second -> data][p -> vertexes[1]] -> data) {
                dfs_prev(grafito, p -> vertexes[1] -> data, visited);
            }
        }
    }

    DirectedGraph<TV, TE> DFS(){
        DirectedGraph<TV, TE> dDFS;
        unordered_map<TV,unordered_map<TV,int>> visited;
        for(auto p:this -> vertexes){
            Vertex<TV, TE>* temp = p.second;
            visited[temp -> data] = false;
        }

        //Vertex<TV, TE>* temp = this -> vertexes[1];
        //dDFS.insertVertex(1, temp -> data);
        dDFS = dfs_prev(dDFS, this -> vertexes[1], visited);
        return dDFS;
    }
};

#endif //GRAPH_PROJECT_LOSASINTOMATICOS_BFS_Y_DFS_H