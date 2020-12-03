#ifndef FLOYD_H
#define FLOYD_H

#include "../DirectedGraph.h"
#include "../UndirectedGraph.h"
using namespace std;

#define INF 9999

template<typename TV, typename TE>
class Floyd;

template<typename TV, typename TE>
class Floyd{ 
private:
    DirectedGraph<TV, TE> floydVertexes;
public:

    Floyd(DirectedGraph<TV, TE> grafito):floydVertexes(grafito){}

    int InsertElements(int size,unordered_map<int, TV> temp)
    {
        int arr[size][size]; 
        int i, j;
        for (i = 0; i < size; i++)
        {
            for (j = 0; j < size; j++)
            {
                //cout<<i<<" "<<j<<endl;
                /* if(i==j)
                {
                    arr[i][j]=0;
                //    cout<<arr[i][j];
                } */
                if(VerifyAdj(i,j,temp))
                    arr[i][j] = weight(i,j,temp);
                else
                    arr[i][j]=INF;
                if(i==j)
                {
                    arr[i][j]=0;
                //    cout<<arr[i][j];
                }
            }   
        }  

        for (int i = 0; i < size; i++)  
        {  
            for (int j = 0; j < size; j++)  
            {  
                if (arr[i][j] == INF)  
                    cout<<"INF"<<"     ";  
                else
                    cout<<arr[i][j]<<"     ";  
            }  
            cout<<endl;  
        }  

        return arr[size][size];
    }

    int sizeGraph(DirectedGraph<TV, TE> grafo)
    {
        int count=0;
        for(auto itr:grafo.vertexes)
            ++count;
        return count;
    }

    Vertex<TV, TE>* returnVertex(TV data)
    {
        for(auto itr:this->floydVertexes.vertexes)
        {
            if(itr.second->data==data)
                return itr.second;
        }
    }
    
    bool VerifyAdj(int i, int j,unordered_map<int, TV> temp)
    {
        TV data1 = temp[i];
        TV data2 = temp[j];
        Vertex<TV, TE>* dataVertex1 = returnVertex(data1);
        for(auto itr:dataVertex1->edges)
        {
            if(itr->vertexes[1]->data == data2)
                return true;
        }
        return false;
    }

    TE weight(int i, int j,unordered_map<int, TV> temp)
    {
        TV data1 = temp[i];
        TV data2 = temp[j];
        Vertex<TV, TE>* dataVertex1 = returnVertex(data1);
        for(auto itr:dataVertex1->edges)
        {
            if(itr->vertexes[1]->data == data2)
                return itr->weight;
        }
    }

    void apply()
    {
        unordered_map<int, TV> temp;
        int size = sizeGraph(floydVertexes);
        int matrix[size][size];
        //matrix = new TE[sizeGraph(floydVertexes)][sizeGraph(floydVertexes)];
        int count=0;
        for(auto itr:this->floydVertexes.vertexes)
        {
            temp[count] = itr.second->data;
            ++count; 
        }

        for(auto itr:temp)
        {
            cout<<"ID: "<<itr.first<<" "<<"data: "<<itr.second<<endl;
        }

        cout<<size<<endl;

        matrix[size][size] = InsertElements(size,temp);

        for (int i = 0; i < size; i++)  
        {  
            for (int j = 0; j < size; j++)  
            {  
                if (matrix[i][j] == INF)  
                    cout<<"INF"<<"     ";  
                else
                    cout<<matrix[i][j]<<"     ";  
            }  
            cout<<endl;  
        }  
    }

};

#endif