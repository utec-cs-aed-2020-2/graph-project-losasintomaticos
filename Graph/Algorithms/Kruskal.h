#ifndef KRUSKAL_H
#define KRUSKAL_H

#include "../DirectedGraph.h"
#include "../UndirectedGraph.h"
using namespace std;

template<typename TV, typename TE>
class Kruskal;

template<typename TV, typename TE>
struct DisjointSets;

/*****************************************/

template<typename TV, typename TE>
struct DisjointSets 
{ 
    int n; 
    unordered_map<TV,TV> parent;
    unordered_map<TV,int> rnk;

    DisjointSets(int n,unordered_map<TV,unordered_map<TV,int>> vertexes) 
    { 
        this->n = n; 

        for (auto p: vertexes)
        {    
            rnk[p.first] = 0;
            parent[p.first] = p.first;
        }
    } 
  
    TV find(TV u) 
    { 
        if (u != parent[u]) 
            parent[u] = find(parent[u]); 
        return parent[u]; 
    } 
  
    TV merge(TV x, TV y) 
    { 
        x = find(x), y = find(y); 
  
        if (rnk[x] > rnk[y])
        {
            parent[y] = x;
            return x;
        }  
        else
            parent[x] = y;
  
        if (rnk[x] == rnk[y])
        {
            rnk[y]++; 
            return y;
        } 
    } 
}; 


template<typename TV, typename TE>
class Kruskal{ 
private:
    UnDirectedGraph<TV, TE> kruskal_vertexes;

public:

    Kruskal(UnDirectedGraph<TV, TE> grafito):kruskal_vertexes(grafito){}

    string id_min(TV min)
    {
        for(auto p:this->kruskal_vertexes.vertexes)
        {
            if(p.second->data==min)
            {
                return p.first;
            }
        }
    }

    DirectedGraph<string, float> apply()
    {
        DirectedGraph<string, float> kruskal;
        unordered_map<TV,unordered_map<TV,int>> visited;
        vector< pair<TE, pair<TV, TV>> > edges;

        for(auto itr:this->kruskal_vertexes.vertexes)
        {
            kruskal.insertVertex(itr.first,itr.second->data);
            list<Edge<TV, TE>*> edge_temp= itr.second->edges;
            for(auto it:edge_temp)
            {
                visited[itr.second->data][it->vertexes[1]->data]=false;
            }
        }
        
        for(auto it:this->kruskal_vertexes.vertexes)
        {
            list<Edge<TV, TE>*> edge_temp = it.second->edges;
            
            for(auto p:edge_temp)
            {
                if(!visited[it.second->data][p->vertexes[1]->data])
                {
                    edges.push_back({p->weight,{it.second->data,p->vertexes[1]->data}});
                    visited[p->vertexes[1]->data][it.second->data]=true;
                }
            } 
        }

        sort(edges.begin(), edges.end()); 

        DisjointSets<TV,TE> ds(kruskal_vertexes.sizeGraph(),visited); 

        typename vector< pair<TE, pair<TV, TV>> >::iterator it;

        for (it=edges.begin(); it!=edges.end(); it++) 
        { 
            TV u = it->second.first; 
            TV v = it->second.second; 
    
            TV set_u = ds.find(u); 
            TV set_v = ds.find(v); 
    
            if (set_u != set_v) 
            { 
                TV father = ds.merge(set_u, set_v); 
                if(father!=set_u)  
                    kruskal.createEdge(id_min(set_u),id_min(set_v),1);
                else
                    kruskal.createEdge(id_min(set_v),id_min(set_u),1);
            } 
        }
        edges.clear();
        visited.clear();
        return kruskal;
    }   

};
#endif