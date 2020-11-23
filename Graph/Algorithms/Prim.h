#ifndef PRIM_H
#define PRIM_H

#include <list>
#include <vector>
#include <unordered_map>
#include <string.h>
#include<iostream>

#include "../graph.h"
using namespace std;

template<typename TV, typename TE>
class Prim{ 

public:

    TV minEdge(unordered_map<TV,int> visited,unordered_map<TV,TE> weight_edge)
    {
        int min=INT16_MAX;
        TV min_index;
        for(auto p:this->vertexes)
        {
            if(visited[p.second->data]==false && weight_edge[p.second->data]<min)
            {
                min=weight_edge[p.second->data];
                min_index=p.second->data;
            }
        }
        return min_index;
    }

    list<Edge<TV, TE>*> edge_min(TV min)
    {
        for(auto p:this->vertexes)
        {
            if(p.second->data==min)
            {
                return p.second->edges;
            }
        }
    }
    
    string id_min(TV min)
    {
        for(auto p:this->vertexes)
        {
            if(p.second->data==min)
            {
                return p.first;
            }
        }
    }

    DirectedGraph<char, float> prim(TV dato)
    {
        unordered_map<TV,int> visited;
        unordered_map<TV,TE> weight_edge;
        unordered_map<TV,TV> father;
        DirectedGraph<char, float> return_grafo;

        for(auto p:this->vertexes)
        {
            visited[p.second->data]=false;
            weight_edge[p.second->data]=INT16_MAX;
            father[p.second->data] = p.second->data;
        }
        weight_edge[dato]=0;
        

        for(auto p:this->vertexes)
        {
            TV min=minEdge(visited,weight_edge);
            visited[min]=true;
            string id=id_min(min);
            if(return_grafo.empty())
                return_grafo.insertVertex(id,min);
            else
            {
                return_grafo.insertVertex(id,min);
                return_grafo.createEdge(id,id_min(father[min]),weight_edge[min]);
            }
            list<Edge<TV, TE>*> edge_temp= edge_min(min);
            for(auto it:edge_temp)
            {
                if(visited[it->vertexes[1]->data]==false && it->weight<weight_edge[it->vertexes[1]->data])
                {
                    weight_edge[it->vertexes[1]->data] = it->weight;    
                    father[it->vertexes[1]->data]=it->vertexes[0]->data;
                }
            }
        }

        return return_grafo;

    }

};
#endif