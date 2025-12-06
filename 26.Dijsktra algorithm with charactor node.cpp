#include<iostream>
#include<vector>
#include <queue>
#include<map>
using namespace std;
typedef pair<int, int> Pair;
int main()
{
    int vertex, edge;
    cin>>vertex>>edge;
    vector<pair <int, int>> graph[vertex];
    map<char, int> mp;
    int idx = 0;
    for(int i=0; i<edge; i++)
    {
        char u, v;
        int w;
        cin>>u>>v>>w;
        if (mp.find(u) == mp.end()) {
            mp[u] = idx++;
        }
        if (mp.find(v) == mp.end()) {
            mp[v] = idx++;
        }
        int u_idx = mp[u];
        int v_idx = mp[v];
        graph[u_idx].push_back(make_pair(v_idx, w));
        graph[v_idx].push_back(make_pair(u_idx, w));
    }
    int start_vertex = 0;
    int distances[vertex];
    bool visited[vertex];
    for(int i=0; i<vertex; i++)
    {
        distances[i] = INT_MAX;
        visited[i] = false;
    }
    priority_queue<Pair, vector<Pair>, greater<Pair>> Q;
    distances[start_vertex] = 0;
    Q.push(make_pair(0, start_vertex));
    while(!Q.empty())
    {
        int u = Q.top().second;
        Q.pop();

        for(int i=0; i<graph[u].size(); i++)
        {
            int v = graph[u][i].first;
            int w = graph[u][i].second;

            if(distances[v] > distances[u]+ w){
                distances[v] = distances[u] + w;
                Q.push(make_pair(distances[v], v));
            }
        }
    }
    cout<<"Distances from Source"<<endl;
    for (const auto& pair : mp) {
        char key = pair.first;
        int index = pair.second;
cout << key << " \t " << distances[index] << endl;
}
}
