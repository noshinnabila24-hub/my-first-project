#include <bits/stdc++.h>

using namespace std;
int main(){
    int vertex,edge;
    cin>>vertex>>edge;
    vector<vector<pair<int, int>>> graph(vertex);
    for(int i= 0; i<edge; i++){
        int u,v,w;
        cin>>u>>v>>w;
        graph[u].push_back(make_pair(v,w));
        graph[v].push_back(make_pair(u,w));

    }
      int source= 0;
      int distance[vertex];
      bool visited[vertex];
      priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;

      for(int i = 0; i<vertex; i++){

        distance[i]= INT_MAX;
        visited[i] = false;

      }
      distance[source]= 0;
     
      pq.push(make_pair(0,source));

      while(!pq.empty()){
        int source = pq.top().first;
        int dist= pq.top().second;
        pq.pop();

        for(int i = 0; i<graph[source].size(); i++){
            int destination = graph[source][i].first;
            int cost = graph[source][i].second;

            if (distance[destination] > dist + cost) {
               distance[destination] = dist + cost;
               pq.push(make_pair(distance[destination], destination));
}

        }
      }
      cout<<"distances from source Node 0 Are: \n";
      for(int i=0; i<vertex;i++){
        cout<< "Node: "<<i<<"\t distance: "<<distance[i]<<endl;
      }
}
