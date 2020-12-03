#ifndef GRAPH_H
#define GRAPH_H

#include <list>
#include <vector>
#include <unordered_map>
#include <string.h>

using namespace std;

template<typename TV, typename TE>
struct Edge;

template<typename TV, typename TE>
struct Vertex;

template<typename TV, typename TE>
class Graph;

template<typename TV, typename TE>
class Prim;

template<typename TV, typename TE>
class Kruskal;

template<typename TV, typename TE>
class Floyd;
//////////////////////////////////////////////////////

template<typename TV, typename TE>
struct Edge {
    Vertex<TV, TE>* vertexes[2];
    TE weight;
    Edge(TE w, Vertex<TV,TE>* id1, Vertex<TV,TE>* id2)
    {
        weight = w;
        vertexes[0] = id1;
        vertexes[1] = id2;
    }
};

template<typename TV, typename TE>
struct Vertex {
    TV data;
    std::list<Edge<TV, TE>*> edges;
    Vertex(TV data):data(data)
    {
        for(auto p:edges)
        {
            p->vertexes[0]=nullptr;
            p->vertexes[1]=nullptr;
        }
    }
};

template<typename TV, typename TE>
class Graph{
protected:    
    std::unordered_map<string, Vertex<TV, TE>*>  vertexes;
    
public:
    
    bool insertVertex(string id, TV vertex)
    {
        Vertex<TV,TE>* temp = new Vertex<TV,TE>(vertex);
        vertexes[id] = temp;
    }

    bool createEdge(string id1, string id2, TE w);

    bool deleteVertex(string id);

    bool deleteEdge(string start, string end);

    TE &operator()(string start, string end)
    {
        TV data_end;
        for(auto p:this->vertexes)
        {
            if(p.first==end)
                data_end = p.second->data;
        }

        for(auto p:this->vertexes)
        {
            if(p.first==start)
            {
                list<Edge<TV, TE>*> edge_temp = p.second->edges;
                for(auto itr:edge_temp)
                {
                    if(itr->vertexes[1]->data==data_end)
                        return itr->weight;
                }
                throw ("No existe esa arista");
            }
        }
    }

    float density();

    bool isDense(float threshold = 0.5);
    bool isConnected()
    {
        unordered_map<string,int> visited;
        for(auto p:vertexes)
            visited[p.second->data]=false;
          
        for(auto p:vertexes)
        {
            list<Edge<TV, TE>*> edge_temp = p.second->edges;
            for(auto itr:edge_temp)
            {
                if(!visited[itr->vertexes[1]->data])
                {
                    visited[itr->vertexes[1]->data]=true;
                    visited[itr->vertexes[0]->data]=true;
                }
            }
        }

        for(auto p:vertexes)
        {
            if(visited[p.second->data]==false)
                return false;
        }
        return true;
    }

    bool isStronglyConnected() throw();
    bool empty()
    {
        return (vertexes.empty()? 1:0);
    }
    void clear()
    {
        vertexes.clear();
    }
      
    void displayVertex(string id)
    {
        Vertex<TV,TE>* temp1 = vertexes[id];
        cout<<temp1->data<<'\n';
    }
    bool findById(string id)
    {
        for(auto it = vertexes.begin();it != vertexes.end() ;it++)
        {
            if(it->first==id)
                return true;
        }
        return false;
    }

    void display();

    friend class Prim<TV, TE>;
    friend class Kruskal<TV, TE>;
    friend class Floyd<TV,TE>;
};

#endif