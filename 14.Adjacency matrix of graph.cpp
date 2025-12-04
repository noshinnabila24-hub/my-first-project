#include<iostream>
using namespace std;
int main()
{
    int vertex, edge;
    cin>>vertex>>edge;
    //adjacency matrix representation
    int graph[vertex][vertex];
    for(int i=0; i<vertex; i++)
    {
        for(int j=0; j<vertex;j++)
        {
            graph[i][j]=0;
        }
    }
    for(int i=0; i<edge; i++){
        int u,v;
        cin>>u>>v;
        graph[u][v]=1;
        graph[u][v]=1;
    }
    for(int i=0; i<vertex; i++){
        for(int j=0; j<vertex; i++){
            cout<<graph[i][j]<<" ";
        }
        cout<<"/n";
    }
}
