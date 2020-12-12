#ifndef GRAPH_PROJECT_LOSASINTOMATICOS_DIJSKTRA_H
#define GRAPH_PROJECT_LOSASINTOMATICOS_DIJSKTRA_H

#include "../DirectedGraph.h"
#include "../UndirectedGraph.h"
using namespace std;

template<typename TV, typename TE>
class Dijsktra:public Graph<TV, TE>{

private:
    UnDirectedGraph<TV, TE> dij_vertexes;
    TV inicio;

public:
//    algo(UnDirectedGraph<TV, TE> grafito, TV dato) : dij_vertexes(grafito),inicio(dato){}
//
//    TV minEdge(unordered_map<TV,bool> visited,unordered_map<TV,TE> weight_edge)
//    {
//        int min=INT16_MAX;
//        TV min_index;
//        for(auto p:this->dij_vertexes.vertexes)
//        {
//            if(visited[p.second->data]==false && weight_edge[p.second->data]<min)
//            {
//                min=weight_edge[p.second->data];
//                min_index=p.second->data;
//            }
//        }
//        return min_index;
//    }
//
//    list<Edge<TV, TE>*> edge_min(TV min)
//    {
//        for(auto p:this->prim_vertexes.vertexes)
//        {
//            if(p.second->data==min)
//            {
//                return p.second->edges;
//            }
//        }
//    }
//
//    string id_min(TV min)
//    {
//        for(auto p:this->prim_vertexes.vertexes)
//        {
//            if(p.second->data==min)
//            {
//                return p.first;
//            }
//        }
//    }
//
//    UnDirectedGraph<string, float> dijkstra(){
//        unordered_map<TV, bool> visited
//    }

};

#endif //GRAPH_PROJECT_LOSASINTOMATICOS_DIJSKTRA_H
