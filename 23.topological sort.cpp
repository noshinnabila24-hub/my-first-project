#include<bits/stdc++.h>
using namespace std;
int main()
{
    int vertex, edge;
    cin >> vertex >> edge;
    int graph[100][100];
    int indegree[100] = {0};
    for(int i = 0; i < vertex; i++){
        for(int j = 0; j < vertex; j++){
            graph[i][j] = 0;
        }
    }
    for(int i = 0; i < edge; i++){
        int u, v;
        cin >> u >> v;
        graph[u][v] = 1;
        indegree[v]++;
    }

    queue<int> q;
    for (int i = 0; i < vertex; i++) {
        if (indegree[i] == 0)
            q.push(i);
    }
    cout << "Now the topological sorting order is: ";
    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout << node << " ";
        for(int j = 0; j < vertex; j++){
            if (graph[node][j] == 1){
                indegree[j]--;
                if (indegree[j] == 0){
                    q.push(j);
                }
            }
        }
    }
    return 0;
}
