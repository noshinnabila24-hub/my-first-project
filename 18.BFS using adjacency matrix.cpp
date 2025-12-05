#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n, e;
    cin >> n >> e;

    int adj[100][100];
    int dist[100];
    int vis[100];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
        dist[i] = 0;
        vis[i] = 0;
    }

    for(int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u][v] = w;
        adj[v][u] = w;
    }

    int start, end;
    cin >> start >> end;

    queue<int> q;
    q.push(start);
    vis[start] = 1;
    dist[start] = 0;

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        for(int i = 0; i < n; i++) {
            if(adj[node][i] > 0 && vis[i] == 0) {
                vis[i] = 1;
                dist[i] = dist[node] + adj[node][i];
                q.push(i);
            }
        }
    }

    cout << dist[end] << endl;

    return 0;
}

