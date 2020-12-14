#ifndef UNDIRECTEDGRAPH_H
#define UNDIRECTEDGRAPH_H

#include "../Graph/graph.h"


template<typename TV, typename TE>
class UnDirectedGraph : public Graph<TV, TE>{
    public:
        UnDirectedGraph(): Graph<TV, TE>(){}
        ~UnDirectedGraph(){}

        bool createEdge(string id1, string id2, TE w)
        {
            Vertex<TV,TE>* temp1 = this->vertexes[id1];
            Vertex<TV,TE>* temp2 = this->vertexes[id2];
            Edge<TV,TE>* edge_temp1= new Edge<TV,TE>(w,temp1,temp2);
            Edge<TV,TE>* edge_temp2= new Edge<TV,TE>(w,temp2,temp1);
            temp1->edges.push_back(edge_temp1);
            temp2->edges.push_back(edge_temp2);
        }

        int sizeEdges()
        {
            int count=0;
            unordered_map<TV,unordered_map<TV,int>> visited;
            for(auto p:this->vertexes)
            {
                list<Edge<TV, TE>*> edge_temp= p.second->edges;
                for(auto it:edge_temp)
                {
                    visited[p.second->data][it->vertexes[1]->data]=false;
                }
            }

            for(auto itr:this->vertexes)
            {
                list<Edge<TV, TE>*> edge_temp= itr.second->edges;
                for(auto it:edge_temp)
                {
                    if(!visited[itr.second->data][it->vertexes[1]->data])
                    {
                        count++;
                        visited[it->vertexes[1]->data][itr.second->data]=true;
                    }
                }
            }

            return count;
        }

        float density()
        {
            if(this->isConnected())
            {
                int countEdges = sizeEdges();
                int countVertice = this->sizeGraph();

                float densidad = (float)2*countEdges/(countVertice*(countVertice-1));
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
                cout<<vertice->data<<" = ";
                list<Edge<TV, TE>*> edge_temp = vertice->edges;
                for(auto itr:edge_temp)
                {
                    cout<<itr->vertexes[1]->data<<'('<<itr->weight<<')'<<", ";
                }
                cout<<'\n';
            }
        }

        bool isStronglyConnected() throw()
        {
            throw 0;
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
                        if(((*itri)->vertexes[0]->data == this->returnDatabyid(start) && 
                        (*itri)->vertexes[1]->data == this->returnDatabyid(end)) || 
                        ((*itri)->vertexes[0]->data == this->returnDatabyid(end) &&
                        (*itri)->vertexes[1]->data == this->returnDatabyid(start)))
                        {
                            p.second->edges.erase(itri++);
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


        void introduceGraph(TV u,UnDirectedGraph<TV, TE> &graphTemp,UnDirectedGraph<TV, TE> Padre,unordered_map<TV,TV> father,unordered_map<TV,TE> weight_edge)
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
