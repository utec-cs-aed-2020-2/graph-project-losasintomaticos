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
            TV u = min_distanceU(dist, visited);
            visited[u] = true;

            introduceGraphU(u,uDijsktra,father,weight_edge);

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
            TV u = min_distanceD(dist, visited);
            visited[u] = true;

            introduceGraphD(u,dDijsktra,father,weight_edge);

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

private:
    TV min_distanceU(unordered_map<TV, TE> &dist, unordered_map<TV, bool> &visited){
        int min = INT_MAX;
         TV min_index;

        for (auto itr:uDij_vertexes.vertexes){
            if (visited[itr.second-> data] == false && dist[itr.second->data] <= min){
                min = dist[itr.second-> data], min_index = itr.second-> data;
            }
        }
        return min_index;
    }

    TV min_distanceD(unordered_map<TV, TE> &dist, unordered_map<TV, bool> &visited){
        int min = INT_MAX;
        TV min_index;

        for (auto itr:dDij_vertexes.vertexes){
            if (visited[itr.second-> data] == false && dist[itr.second->data] <= min){
                min = dist[itr.second-> data], min_index = itr.second-> data;
            }
        }
        return min_index;
    }

    void introduceGraphU(TV u,UnDirectedGraph<TV, TE> &uDijsktra,unordered_map<TV,TV> father,unordered_map<TV,TE> weight_edge)
    {
        if(uDijsktra.empty())
            uDijsktra.insertVertex(uDij_vertexes.returnID(u),u);
        else
        {
            uDijsktra.insertVertex(uDij_vertexes.returnID(u),u);
            uDijsktra.createEdge(uDij_vertexes.returnID(u),uDij_vertexes.returnID(father[u]),weight_edge[u]);
        }
    }

    void introduceGraphD(TV u,DirectedGraph<TV, TE> &dDijsktra,unordered_map<TV,TV> father,unordered_map<TV,TE> weight_edge)
    {
        if(dDijsktra.empty())
            dDijsktra.insertVertex(dDij_vertexes.returnID(u),u);
        else
        {
            dDijsktra.insertVertex(dDij_vertexes.returnID(u),u);
            dDijsktra.createEdge(dDij_vertexes.returnID(father[u]),dDij_vertexes.returnID(u),weight_edge[u]);
        }
    }
};

#endif //GRAPH_PROJECT_LOSASINTOMATICOS_DIJSKTRA_H