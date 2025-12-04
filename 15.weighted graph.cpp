#include<bits/stdc++.h>
using namespace std;
int main()
{
    int vertex, edge;
    cin>>vertex>>edge;
    int graph[vertex][vertex];
    for(int i=0; i<vertex;i++){
        for(int j=0; j<vertex;j++){
            graph[i][j]=INT_MAX;
        }
    }
    for(int i=0; i<edge;i++){
        int u,v,w;
        cin>>u>>v>>w;
        graph[u][v]=w;
        graph[v][u]=w;
    }
    for(int i=0; i<vertex; i++)
    {
        for(int j=0; j<vertex; j++)
        {
            cout<<graph[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
