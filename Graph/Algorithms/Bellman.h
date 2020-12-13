#ifndef BELLMAN_H
#define BELLMAN_H

#include "../DirectedGraph.h"
#include "../UndirectedGraph.h"
#include <unordered_map>
using namespace std;


template<typename TV, typename TE>
class Bellman;

template<typename TV, typename TE>
struct EdgeSupport;

template<typename TV, typename TE>
struct EdgeSupport { 
    int start, end;
    TE peso; 
}; 


template<typename TV, typename TE>
class Bellman{ 
private:
    DirectedGraph<TV, TE> DbellmanVertexes;
    UnDirectedGraph<TV, TE> UbellmanVertexes;
    bool isDirected;

public:
    Bellman(DirectedGraph<TV, TE> grafito):DbellmanVertexes(grafito),isDirected(true){}
    Bellman(UnDirectedGraph<TV, TE> grafito):UbellmanVertexes(grafito),isDirected(false){}

    unordered_map<int,TE> apply(TV start)
    {

        int sizeVertex;
        int sizeEdge;
        if(isDirected)
        {
            sizeVertex = DbellmanVertexes.sizeGraph();
            sizeEdge = DbellmanVertexes.sizeEdges();
        }
        else
        {
            sizeVertex = UbellmanVertexes.sizeGraph();
            sizeEdge = UbellmanVertexes.sizeEdges();
        }
        unordered_map<int,TE> weight;
        struct EdgeSupport<TV,TE>* edge = new EdgeSupport<TV,TE>[sizeEdge];

        insertWeight(weight,sizeVertex,start);

        structSupport(edge);

        for (int i = 1; i <= sizeVertex - 1; i++) 
        { 
            for (int j = 0; j < sizeEdge; j++) 
            { 
                int u = edge[j].start; 
                int v = edge[j].end; 
                TE weights = edge[j].peso; 
                if (weight[u] != INT16_MAX && weight[u] + weights < weight[v]) 
                    weight[v] = weight[u] + weights; 
            } 
        }

        display(weight,sizeVertex);

        return weight;
    }

private:
    void insertWeight(unordered_map<int,TE> &weight,  int sizeVertex, TV start)
    {
        for (int i = 1; i <= sizeVertex; i++) 
            weight[i] = INT16_MAX; 
        weight[stoi(start)] = 0;
    }

    void structSupport(EdgeSupport<TV,TE>* &edge)
    {
        int count=0;
        if(isDirected)
        {
            for(auto itr:this->DbellmanVertexes.vertexes)
            {
                list<Edge<TV, TE>*> edge_temp= itr.second->edges;
                for(auto it:edge_temp)
                {
                    edge[count].start = stoi(it->vertexes[0]->data);
                    edge[count].end = stoi(it->vertexes[1]->data);
                    edge[count].peso =  it->weight;
                    ++count;
                }
            }
        }
        else
        {
            for(auto itr:this->UbellmanVertexes.vertexes)
            {
                list<Edge<TV, TE>*> edge_temp= itr.second->edges;
                for(auto it:edge_temp)
                {
                    edge[count].start = stoi(it->vertexes[0]->data);
                    edge[count].end = stoi(it->vertexes[1]->data);
                    edge[count].peso =  it->weight;
                    ++count;
                }
            }
        }
        
    }

    void display(unordered_map<int,TE> weight,int sizeVertex)
    {
        for (int i = 1; i <= sizeVertex; ++i) 
            cout<<"Distancia minima de 1 a "<<i<<" => "<<weight[i]<<endl;
    }

};

#endif