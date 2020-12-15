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
    DirectedGraph<TV, TE> connectVertex;

public:
    strongConnected(DirectedGraph<TV, TE> grafito): connectVertex(grafito){}

    /* void travelEdges(unordered_map<string,unordered_map<string,int>> &visited, Vertex<TV,TE>* vertice, string dato_vertice)
    {
        if(vertice->edges.empty())
            return;
        
        list<Edge<TV, TE>*> edge_temp = vertice->edges;

        for(auto itr:edge_temp)
        {
            if(!visited[dato_vertice][itr->vertexes[1]->data])
            {
                visited[dato_vertice][itr->vertexes[1]->data]=true;
                travelEdges(visited,itr->vertexes[1],dato_vertice);
            }
        }
    } */

    void apply()
    {
        /* unordered_map<string,unordered_map<string,int>> visited;
        for(auto p:connectVertex.vertexes)
        {
            for(auto it:this->vertexes)
            {
                if(p.second->data!=it.second->data)
                    visited[p.second->data][it.second->data]=false;
            }
        }

        for (auto p:connectVertex.vertexes)
        {
            travelEdges(visited,p.second,p.second->data);
            for(auto it:this->vertexes)
            {
                if(p.second->data!=it.second->data)
                {
                    if(!visited[p.second->data][it.second->data])
                        //return false;
                }
            }
        } */
    }

};

#endif //GRAPH_PROJECT_LOSASINTOMATICOS_STRONGCONNECTED_H
