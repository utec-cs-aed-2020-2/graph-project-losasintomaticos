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

template<typename TV, typename TE>
class Bellman;

template<typename TV, typename TE>
class BFSSearch;

template<typename TV, typename TE>
class DFSSearch;

template<typename TV, typename TE>
class strongConnected;

template<typename TV, typename TE>
class Dijsktra;
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

    bool deleteVertex(string id)
    {   
        if(this->findById(id))
        {
            for(auto itr:this->vertexes)
            {
                typename list<Edge<TV, TE>*>::iterator itri = itr.second->edges.begin(); 
                while (  itri != itr.second->edges.end())
                {
                    if ((*itri)->vertexes[1]->data == returnDatabyid(id))
                    {
                        itr.second->edges.erase(itri++);
                    }

                    else
                    {
                        ++itri;
                    }
                }
            }

            this->vertexes.erase(id);
        }
        else
            return false;
    }

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

    /************************FUNCIONES DE APOYO************************/

    Vertex<TV, TE>* returnVertex(TV dato){
        for(auto i:this->vertexes){
            if (i.second->data == dato){
                return i.second;
            }
        }
    }

    string returnID(TV dato)
    {
        for(auto p:this->vertexes)
        {
            if(p.second->data==dato)
            {
                return p.first;
            }
        }
    }

    int sizeGraph()
    {
        int count=0;
        for(auto itr:this->vertexes)
            ++count;
        return count;
    }

    list<Edge<TV, TE>*> returnEdge(TV min)
    {
        for(auto p:this->vertexes)
        {
            if(p.second->data==min)
            {
                return p.second->edges;
            }
        }
    }

    TV returnDatabyid(string id)
    {
        for(auto p:this->vertexes)
        {
            if(p.first==id)
                return p.second->data;
        }
    }

    TV minDistance(unordered_map<TV, TE> &dist, unordered_map<TV, bool> &visited){
        int min = INT16_MAX;
        TV min_index;

        for (auto itr:this->vertexes){
            if (visited[itr.second-> data] == false && dist[itr.second->data] <= min){
                min = dist[itr.second-> data], min_index = itr.second-> data;
            }
        }
        return min_index;
    }

    friend class Prim<TV, TE>;
    friend class Kruskal<TV, TE>;
    friend class Floyd<TV,TE>;
    friend class Bellman<TV,TE>;
    friend class BFSSearch<TV, TE>;
    friend class DFSSearch<TV, TE>;
    friend class strongConnected<TV, TE>;
    friend class Dijsktra<TV, TE>;
};

#endif