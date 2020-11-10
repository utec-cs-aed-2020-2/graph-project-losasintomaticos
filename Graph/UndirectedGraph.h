#ifndef UNDIRECTEDGRAPH_H
#define UNDIRECTEDGRAPH_H

#include "graph.h"


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

        float density()
        {
            if(this->isConnected())
            {
                unordered_map<string,unordered_map<string,int>> visited;
                for(auto p:this->vertexes)
                {
                    list<Edge<TV, TE>*> edge_temp= p.second->edges;
                    for(auto it:edge_temp)
                    {
                        visited[p.second->data][it->vertexes[1]->data]=false;
                    }
                }

                int count_vertice=0,count_edges=0;
                for(auto it:this->vertexes)
                {
                    count_vertice++;
                    list<Edge<TV, TE>*> edge_temp= it.second->edges;
                    for(auto itr:edge_temp)
                    {
                        if(!visited[it.second->data][itr->vertexes[1]->data])
                        {
                            count_edges++;
                            visited[itr->vertexes[1]->data][it.second->data]=true;
                        }
                    }
                }

                float densidad = (float)2*count_edges/(count_vertice*(count_vertice-1));
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
                cout<<vertice->data<<": ";
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

        }
};
#endif
