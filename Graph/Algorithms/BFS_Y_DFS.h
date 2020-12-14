#ifndef GRAPH_PROJECT_LOSASINTOMATICOS_BFS_Y_DFS_H
#define GRAPH_PROJECT_LOSASINTOMATICOS_BFS_Y_DFS_H

#include "../DirectedGraph.h"
#include "../UndirectedGraph.h"
#include <string>
#include <queue>
#include <stack>
#include <unordered_map>
using namespace std;

template<typename TV, typename TE>
class BFSSearch;

template<typename TV, typename TE>
class DFSSearch;

/*****************************************/

template<typename TV, typename TE>
class BFSSearch : public Graph<TV, TE>{
private:
    DirectedGraph<TV, TE> bGraphSearch;
    UnDirectedGraph<TV, TE> undirectBFS;

public:
    BFSSearch(DirectedGraph<TV, TE> grafito):bGraphSearch(grafito){}
    BFSSearch(UnDirectedGraph<TV, TE> grafo_undir):undirectBFS(grafo_undir){}

    DirectedGraph<TV, TE> dBFS(TV id) {
        DirectedGraph<TV, TE> dBFS;
        unordered_map<TV, bool> visited;
        unordered_map<TV,TV> father;
        unordered_map<TV,TE> weight_edge;

        for (auto v:bGraphSearch.vertexes)
            visited.insert({v.second->data, false});

        Vertex<TV, TE> *temp = bGraphSearch.returnVertex(id);
        queue<Vertex<TV, TE>*> q;
        q.push(temp);

        dBFS.insertVertex(bGraphSearch.returnID(temp->data),temp->data);

        while (!q.empty()) {
            Vertex<TV, TE> *vertice_begin = q.front();
            q.pop();

            for (auto adj:vertice_begin->edges) {
                    if (!visited[adj->vertexes[1]->data]){
                        father[adj->vertexes[1]->data]=adj->vertexes[0]->data;
                        visited[adj->vertexes[1]->data] = true;
                        weight_edge[adj->vertexes[1]->data] = adj->weight;
                        dBFS.introduceGraph(adj->vertexes[1]->data,dBFS,bGraphSearch,father,weight_edge);
                        q.push(adj->vertexes[1]);
                }
            }
        }
        return dBFS;
    }

    UnDirectedGraph<TV, TE> uBFS(string id) {
        UnDirectedGraph<string, float> udBFS;
        unordered_map<TV, bool> visited;
        unordered_map<TV, TV> father;
        unordered_map<TV,TE> weight_edge;

        for (auto v:undirectBFS.vertexes) {
            visited.insert({v.second->data, false});
        }

        Vertex<TV, TE> *temp = undirectBFS.returnVertex(id);
        queue<Vertex<TV, TE> *> q;
        q.push(temp);

        udBFS.insertVertex(undirectBFS.returnID(temp->data), temp->data);
        visited[temp->data]=true;

        while (!q.empty()) {
            Vertex<TV, TE> *vertice_begin = q.front();
            q.pop();

            for (auto adj:vertice_begin->edges) {
                if (!visited[adj->vertexes[1]->data]) {
                    father[adj->vertexes[1]->data] = adj->vertexes[0]->data;
                    visited[adj->vertexes[1]->data] = true;
                    weight_edge[adj->vertexes[1]->data] = adj->weight;
                    udBFS.introduceGraph(adj->vertexes[1]->data,udBFS,undirectBFS,father,weight_edge);
                    q.push(adj->vertexes[1]);
                }
            }
        }
        return udBFS;
    }
};



template<typename TV, typename TE>
class DFSSearch : public Graph<TV, TE>{
private:
    DirectedGraph<TV, TE> dGraphSearch;
    UnDirectedGraph<TV,TE> undirectDFS;

public:
    DFSSearch(DirectedGraph<TV, TE> grafito): dGraphSearch(grafito){}
    DFSSearch(UnDirectedGraph<TV, TE> grafo_undir):undirectDFS(grafo_undir){}

    DirectedGraph<TV, TE> dDFS(TV id) {
        DirectedGraph<TV, TE> dDFS;
        unordered_map<TV, bool> visited;
        unordered_map<TV, TV> father;
        unordered_map<TV, TE> weight;

        for (auto v:dGraphSearch.vertexes) {
            visited.insert({v.first, false});
        }

        Vertex<TV, TE> *temp = dGraphSearch.returnVertex(id);
        stack<Vertex<TV, TE>*> s;
        s.push(temp);
        while (!s.empty()) {
            Vertex<TV, TE> *vertice_begin = s.top();
            s.pop();

            if (!visited[vertice_begin->data]){
                visited[vertice_begin->data] = true;
                dDFS.introduceGraph(vertice_begin->data,dDFS,dGraphSearch,father,weight);
            }

            for (auto adj:vertice_begin->edges) {
                if (!visited[adj->vertexes[1]->data]){
                    father[adj->vertexes[1]->data]=adj->vertexes[0]->data;
                    weight[adj->vertexes[1]->data]=adj->weight;
                    s.push(adj->vertexes[1]);
                }
            }
        }
        return dDFS;
    }

    UnDirectedGraph<TV, TE> dfs_help(UnDirectedGraph<TV, TE> &dfs,Vertex<TV,TE>* vertice,unordered_map<TV,int> &visited)
    {
        static int count=0;
        visited[vertice->data]=true;
        static unordered_map<TV,string> temporal;
        temporal[vertice->data] = to_string(count);

        list<Edge<TV, TE>*> edge_temp = vertice->edges;    

        for(auto itr:edge_temp)
        {
            if(!visited[itr->vertexes[1]->data])
            {
                count++;
                dfs.insertVertex(to_string(count),itr->vertexes[1]->data); 
                dfs.createEdge(temporal[vertice->data],to_string(count),itr->weight);
                dfs_help(dfs,itr->vertexes[1],visited);
            }
        }

        return dfs;
    }

    UnDirectedGraph<TV, TE> uDFS(string id) {
        UnDirectedGraph<TV, TE> dfs;
        unordered_map<TV,int> visited;
        for(auto p:this->undirectDFS.vertexes)
            visited[p.second->data]=false;

        Vertex<TV,TE>* temp= undirectDFS.vertexes["0"];
        dfs.insertVertex("0",temp->data);
        dfs = dfs_help(dfs,undirectDFS.vertexes["0"],visited);
        return dfs;
    }
};

#endif //GRAPH_PROJECT_LOSASINTOMATICOS_BFS_Y_DFS_H