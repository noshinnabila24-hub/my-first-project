#include<bits/stdc++.h>
using namespace std;
int main()
{
    int vertex, edge;
    cin>>vertex>>edge;
    int graph[vertex][vertex];
    for(int i=0; i<vertex; i++)
    {
        for(int j=0; j<vertex; j++)
        {
            graph[i][j] = 0;
        }
    }
    for(int i=0; i<edge; i++)
    {
        int u,v;
        cin>>u>>v;
        graph[u][v]=1;
        graph[v][u]=1;
    }
    int root_node;
    cin>>root_node;
    int visited[vertex];
    for(int i=0; i<vertex; i++)
    {
        visited[i]=0;
    }
    queue<int>q;
    q.push(root_node);
    visited[root_node]=1;
    cout<<"BFS traversal is:" ;
    while(!q.empty())
    {
        int current_node=q.front();
        q.pop();
        cout<<current_node<<" ";
        for(int i=0; i<vertex; i++)
        {
            if(graph[current_node][i]==1){
                if(visited[i]==0)
                {
                    visited[i]=1;
                    q.push(i);
                }
            }
        }
    }
    return 0;
}
