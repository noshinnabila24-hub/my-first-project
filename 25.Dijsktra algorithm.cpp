#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

int main()
{
    int vertex, edge;
    cin >> vertex >> edge;

    // Graph represent korar jonno adjacency list use kortesi
    vector<vector<pair<int,int>>> graph(vertex);

    for(int i=0; i<edge; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(v,w));
        graph[v].push_back(make_pair(u,w)); // undirected dhore
    }

    int source = 0; // source node ke 0 dhore nicchi
    vector<int> distance(vertex, INT_MAX); // distance initially infinity
    vector<bool> visited(vertex, false); // visited array

    // priority queue te pair (distance, node)
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    distance[source] = 0;
    pq.push(make_pair(0, source)); // distance, node

    while(!pq.empty())
    {
        int dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if(visited[node] == true) continue; // jodi already visited hoy, skip
        visited[node] = true;

        for(int i=0; i<graph[node].size(); i++)
        {
            int adjNode = graph[node][i].first;
            int cost = graph[node][i].second;

            if(distance[adjNode] > distance[node] + cost)
            {
                distance[adjNode] = distance[node] + cost;
                pq.push(make_pair(distance[adjNode], adjNode));
            }
        }
    }

    cout << "Distances from source node " << source << ":\n";
    for(int i=0; i<vertex; i++)
    {
        cout << "Node: " << i << "\tDistance: " << distance[i] << endl;
    }

    return 0;
}
