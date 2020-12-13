#ifndef GRAPH_PROJECT_LOSASINTOMATICOS_DIJSKTRA_H
#define GRAPH_PROJECT_LOSASINTOMATICOS_DIJSKTRA_H

#include "../DirectedGraph.h"
#include "../UndirectedGraph.h"
#include <string>
using namespace std;

template<typename TV, typename TE>
class Dijsktra:public Graph<TV, TE>{

private:
    DirectedGraph<TV, TE> dDij_vertexes;
    UnDirectedGraph<TV, TE> uDij_vertexes;

public:

    Dijsktra(UnDirectedGraph<TV, TE> grafito):uDij_vertexes(grafito){}
    Dijsktra(DirectedGraph<TV, TE> grafito):dDij_vertexes(grafito){}

    TV min_distance(unordered_map<TV, TE> &dist, unordered_map<TV, bool> &visited){
        int min = INT_MAX;
        TV min_index;

        for (auto itr:uDij_vertexes.vertexes){
            if (visited[itr.second-> data] == false && dist[itr.second->data] <= min){
                min = dist[itr.second-> data], min_index = itr.second-> data;
            }
        }
        return min_index;
    }

    list<Edge<TV, TE>*> return_edge(TV u){
        for (auto itr:uDij_vertexes.vertexes){
            if (itr.second->data == u){
                return itr.second->edges;
            }
        }
    }

    UnDirectedGraph<TV, TE> apply(TV src){
        UnDirectedGraph<TV, TE> uDijsktra;

        //int min=INT16_MAX;
        unordered_map<TV, bool> visited;
        unordered_map<TV, TE> dist;

        for(auto itr:uDij_vertexes.vertexes){
            visited[itr.second->data] = false;
            dist[itr.second->data] = INT16_MAX;
        }

        dist[src] = 0;

        for (auto itr:uDij_vertexes.vertexes) {
            static int count = 0;
            count++;
            TV u = min_distance(dist, visited);
            visited[u] = true;
            uDijsktra.insertVertex(to_string(count), u);
            list<Edge<TV, TE>*> adj = return_edge(u);

            for (auto it:adj){

               if(!visited[it->vertexes[1]->data] && dist[u] != INT_MAX
               && dist[u] + it->weight < dist[it->vertexes[1]->data]){
                   dist[it->vertexes[1]->data] = dist[u] + it->weight;
               }
            }
        }

    }
};

#endif //GRAPH_PROJECT_LOSASINTOMATICOS_DIJSKTRA_H
