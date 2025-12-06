#include <bits/stdc++.h>
using namespace std;

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    int graph[100][100]; // adjacency matrix
    int visited[100] = {0};

    // initialize matrix with 0 (no connection)
    for (int i = 1; i <= V; i++) {
        for (int j = 1; j <= V; j++) {
            graph[i][j] = 0;
        }
    }

    cout << "Enter edges (u v w):\n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w;
        graph[v][u] = w; // undirected graph
    }

    // Min-heap: (weight, vertex)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    int totalWeight = 0;
    pq.push({0, 1}); // start from vertex 1

    cout << "\nEdges in MST:\n";

    while (!pq.empty()) {
        int w = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (visited[node]) continue; // already taken

        visited[node] = 1;
        totalWeight += w;

        if (w != 0) // ignore the starting node
            cout << "Node added: " << node << " with edge weight " << w << endl;

        // check all neighbors using adjacency matrix
        for (int adj = 1; adj <= V; adj++) {
            if (graph[node][adj] != 0 && !visited[adj]) {
                pq.push({graph[node][adj], adj});
            }
        }
    }

    cout << "Total weight of MST: " << totalWeight << endl;

    return 0;
}

