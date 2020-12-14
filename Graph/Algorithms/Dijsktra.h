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

    UnDirectedGraph<TV, TE> applyU(TV src){
        UnDirectedGraph<TV, TE> uDijsktra;
        unordered_map<TV, bool> visited;
        unordered_map<TV,TE> weight_edge;
        unordered_map<TV,TV> father;
        unordered_map<TV, TE> dist;

        for(auto itr:uDij_vertexes.vertexes){
            visited[itr.second->data] = false;
            dist[itr.second->data] = INT16_MAX;
        }

        dist[src] = 0;

        for (auto itr:uDij_vertexes.vertexes) {
            TV u = dDij_vertexes.minDistance(dist, visited);
            visited[u] = true;

            uDijsktra.introduceGraph(u,uDijsktra,uDij_vertexes,father,weight_edge);

            list<Edge<TV, TE>*> adj = uDij_vertexes.returnEdge(u);

            for (auto it:adj){

               if(!visited[it->vertexes[1]->data] && dist[u] != INT_MAX
               && dist[u] + it->weight < dist[it->vertexes[1]->data])
               {
                   dist[it->vertexes[1]->data] = dist[u] + it->weight;
                   father[it->vertexes[1]->data]=it->vertexes[0]->data;
                   weight_edge[it->vertexes[1]->data] = it->weight;
               }
            }
        }
        return uDijsktra;
    }

    DirectedGraph<TV, TE> applyD(TV src){
        DirectedGraph<TV, TE> dDijsktra;
        unordered_map<TV, bool> visited;
        unordered_map<TV,TE> weight_edge;
        unordered_map<TV,TV> father;
        unordered_map<TV, TE> dist;

        for(auto itr:dDij_vertexes.vertexes){
            visited[itr.second->data] = false;
            dist[itr.second->data] = INT16_MAX;
        }

        dist[src] = 0;

        for (auto itr:dDij_vertexes.vertexes) {
            TV u = dDij_vertexes.minDistance(dist, visited);
            visited[u] = true;

            dDijsktra.introduceGraph(u,dDijsktra,dDij_vertexes,father,weight_edge);

            list<Edge<TV, TE>*> adj = dDij_vertexes.returnEdge(u);

            for (auto it:adj){

               if(!visited[it->vertexes[1]->data] && dist[u] != INT_MAX
               && dist[u] + it->weight < dist[it->vertexes[1]->data])
               {
                   dist[it->vertexes[1]->data] = dist[u] + it->weight;
                   father[it->vertexes[1]->data]=it->vertexes[0]->data;
                   weight_edge[it->vertexes[1]->data] = it->weight;
               }
            }
        }
        return dDijsktra;
    }
};

#endif //GRAPH_PROJECT_LOSASINTOMATICOS_DIJSKTRA_H