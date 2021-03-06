#ifndef NONDIRECTEDGRAPH_H
#define NONDIRECTEDGRAPH_H

#include "../Graph/graph.h"
#include <iostream>

template<typename TV, typename TE>
class DirectedGraph : public Graph<TV, TE>{
    public:
    DirectedGraph(): Graph<TV, TE>(){}
    ~DirectedGraph()= default;

    bool createEdge(string id1, string id2, TE w)
    {
        Vertex<TV,TE>* temp1 = this->vertexes[id1];
        Vertex<TV,TE>* temp2 = this->vertexes[id2];
        Edge<TV,TE>* edge_temp1= new Edge<TV,TE>(w,temp1,temp2);
        temp1->edges.push_back(edge_temp1);
    }
    
    int sizeEdges()
    {
        int countEdges=0;
        for(auto it:this->vertexes)
        {
            list<Edge<TV, TE>*> edge_temp= it.second->edges;
            for(auto itr:edge_temp)
                countEdges++;
        }
        return countEdges;
    }

    float density()
    {
        if(this->isConnected())
        {
            int countVertice = this->sizeGraph();
            int countEdges = sizeEdges();

            float densidad = (float)countEdges/(countVertice*(countVertice-1));
            return densidad;
        }  
        else
            return 0;
    }

    bool isDense(float threshold = 0.5)
    {
        float densidad = density();
        return (densidad>threshold? 1:0);
    }

    void display()
    {
        for(auto p:this->vertexes)
        {
            Vertex<TV,TE>* vertice = p.second;
            cout<<vertice->data<<" => ";
            list<Edge<TV, TE>*> edge_temp = vertice->edges;
            for(auto itr:edge_temp)
            {
                cout<<itr->vertexes[1]->data<<'('<<itr->weight<<')'<<",";
            }
            cout<<'\n';
        }
    }

    void travelEdges(unordered_map<string,unordered_map<string,int>> &visited, Vertex<TV,TE>* vertice, string dato_vertice)
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
    }

    bool isStronglyConnected() throw()
    {
        unordered_map<string,unordered_map<string,int>> visited;
        for(auto p:this->vertexes)
        {
            for(auto it:this->vertexes)
            {
                if(p.second->data!=it.second->data)
                    visited[p.second->data][it.second->data]=false;
            }
        }

        for (auto p:this->vertexes)
        {
            travelEdges(visited,p.second,p.second->data);
            for(auto it:this->vertexes)
            {
                if(p.second->data!=it.second->data)
                {
                    if(!visited[p.second->data][it.second->data])
                        return false;
                }
            }
        }
        return true;
    }

    bool deleteEdge(string start, string end)
    {
        if(this->findById(start) && this->findById(end))
        {
            for(auto p:this->vertexes)
            {
                typename list<Edge<TV, TE>*>::iterator itri = p.second->edges.begin(); 
                while (  itri != p.second->edges.end())
                {
                    if((*itri)->vertexes[0]->data == this->returnDatabyid(start) && 
                    (*itri)->vertexes[1]->data == this->returnDatabyid(end))
                    {
                        p.second->edges.erase(itri++);
                        return 1;
                    }

                    else
                    {
                        ++itri;
                    }
                }
            }
        }
        else
            return false;

    }

    void introduceGraph(TV u,DirectedGraph<TV, TE> &graphTemp,DirectedGraph<TV, TE> Padre,unordered_map<TV,TV> father,unordered_map<TV,TE> weight_edge)
    {
        if(graphTemp.empty())
            graphTemp.insertVertex(Padre.returnID(u),u);
        else
        {
            graphTemp.insertVertex(Padre.returnID(u),u);
            graphTemp.createEdge(Padre.returnID(father[u]),Padre.returnID(u),weight_edge[u]);
        }
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

