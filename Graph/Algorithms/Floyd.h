#ifndef FLOYD_H
#define FLOYD_H

#include "../DirectedGraph.h"
#include "../UndirectedGraph.h"
#include "../graph.h"
using namespace std;

#define INF 9999

template<typename TV, typename TE>
class Floyd;

template<typename TV, typename TE>
class Floyd{ 
private:
    DirectedGraph<TV, TE> floydVertexes;
    UnDirectedGraph<TV, TE> UfloydVertexes;
    bool isDirect;
public:

    Floyd(DirectedGraph<TV, TE> grafito):floydVertexes(grafito),isDirect(true){}
    Floyd(UnDirectedGraph<TV, TE> grafito):UfloydVertexes(grafito),isDirect(false){}

    int** getArray(int size)
    {
        int** arr = new int*[size];
        for(int i=0;i<size;i++){
            arr[i]=new int[size];
            for(int j=0;j<size;j++){
                arr[i][j]=i+j;
            }
        }
        return arr;
    }

    int** InsertElements(int size,unordered_map<int, TV> temp)
    {
        int** arr;
        arr= getArray(size); 
        int i, j;
        for (i = 0; i < size; i++)
        {
            for (j = 0; j < size; j++)
            {
                if(VerifyAdj(i,j,temp))
                {
                    arr[i][j] = weight(i,j,temp);
                }
                else
                    arr[i][j]=INF;
                if(i==j)
                {
                    arr[i][j]=0;
                }
            }   
        }  

        return arr;
    }
    
    bool VerifyAdj(int i, int j,unordered_map<int, TV> temp)
    {
        TV data1 = temp[i];
        TV data2 = temp[j];
        Vertex<TV, TE>* dataVertex1;
        if(isDirect)
            dataVertex1= floydVertexes.returnVertex(data1);
        else{
            dataVertex1= UfloydVertexes.returnVertex(data1);
        }
        for(auto itr:dataVertex1->edges)
        {
            if(itr->vertexes[1]->data == data2)
            {
                return true;
            }
        }
        return false;
    }

    TE weight(int i, int j,unordered_map<int, TV> temp)
    {
        TV data1 = temp[i];
        TV data2 = temp[j];
        Vertex<TV, TE>* dataVertex1;
        if(isDirect)
            dataVertex1= floydVertexes.returnVertex(data1);
        else
            dataVertex1= UfloydVertexes.returnVertex(data1);
        for(auto itr:dataVertex1->edges)
        {
            if(itr->vertexes[1]->data == data2)
                return itr->weight;
        }
    }

    int** apply()
    {
        unordered_map<int, TV> temp;
        int size;
        if(isDirect)
            size = floydVertexes.sizeGraph();
        else
            size = UfloydVertexes.sizeGraph();
        int** matrix;

        if(isDirect)
            for(auto itr:this->floydVertexes.vertexes)
                temp[stoi(itr.second->data)-1] = itr.second->data;
        else
            for(auto itr:this->UfloydVertexes.vertexes)
                temp[stoi(itr.second->data)-1] = itr.second->data;

        matrix = InsertElements(size,temp);

        int k,i,j;
        for (k = 0; k < size; k++)  
        {  
            for (i = 0; i < size; i++)  
            {  
                for (j = 0; j < size; j++)  
                {   
                    if (matrix[i][k] + matrix[k][j] < matrix[i][j])  
                        matrix[i][j] = matrix[i][k] + matrix[k][j];  
                }  
            }  
        }

        displayMatrix(size,matrix);

        return matrix;
    }

    void displayMatrix(int size, int** matrix)
    {
        cout<<"     1     2     3     4     5"<<endl;
        cout<<"     -     -     -     -     -"<<endl;
        for (int i = 0; i < size; i++)  
        {  
            cout<<i+1<<" => ";
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