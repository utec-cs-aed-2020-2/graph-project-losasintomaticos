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
class strongConnected{
private:
    DirectedGraph<TV, TE> connectVertex;

public:
    strongConnected(DirectedGraph<TV, TE> grafito): connectVertex(grafito){}

    void pushStack(Vertex<TV, TE>* vertex, unordered_map<TV,bool> &visited, stack<TV> &stack)
    {
        visited[vertex->data] = true;
        for(auto itr:vertex->edges)
        {
            if(!visited[itr->vertexes[1]->data])
                pushStack(itr->vertexes[1],visited,stack);
        }
        stack.push(vertex->data);
    }

    DirectedGraph<TV, TE> transpose()
    {
        DirectedGraph<TV,TE> temp;
        for(auto itr:connectVertex.vertexes)
            temp.insertVertex(itr.first,itr.second->data);
        
        for(auto itr:connectVertex.vertexes)
            for(auto it:itr.second->edges)
            {
                temp.createEdge(temp.returnID(it->vertexes[1]->data),temp.returnID(it->vertexes[0]->data),it->weight);   
            }

        return temp;
    }

    void apply()
    {

        stack<TV> stack;

        unordered_map<TV,bool> visited;
        for(auto itr:connectVertex.vertexes)
            visited[itr.second->data] = false;
        
        for(auto itr:connectVertex.vertexes)
            if (visited[itr.second->data] == false)
                pushStack(itr.second,visited,stack);

        
        DirectedGraph<TV, TE> GraphTranspose = transpose();

        for(auto itr:connectVertex.vertexes)
            visited[itr.second->data] = false;
        
        int count=0;

        while (stack.empty() == false) 
        {
            TV s = stack.top();
            stack.pop();

            if (visited[s] == false) {
            cout<<"SCC componente => ";
            dfsHelp(GraphTranspose.returnVertex(s), visited);
            cout << endl;
            ++count;
            }
        }
        cout<<"Se tiene "<<count<<" componentes SCC en el grafo"<<endl;
    }

    void dfsHelp(Vertex<TV, TE>* vertex, unordered_map<TV,bool> &visited)
    {
        visited[vertex->data] = true;
        cout << vertex->data << " ";
        for(auto itr:vertex->edges)
            if(!visited[itr->vertexes[1]->data])
                dfsHelp(itr->vertexes[1],visited);
    }

};

#endif //GRAPH_PROJECT_LOSASINTOMATICOS_STRONGCONNECTED_H
