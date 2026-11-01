#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {

    int n, m;
    cin >> n >> m;

    // Adjacency list: {neighbor, weight}
    vector<pair<int,int>> adj[n];

    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // Min heap: {weight, vertex}
    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;

    vector<bool> visited[n]={false};

    int totalCost = 0;

    // Start from vertex 0
    pq.push({0, 0});

    while(!pq.empty()) {

        auto [weight, node] = pq.top();
        pq.pop();

        // Skip already visited vertices
        if(visited[node])
            continue;

        visited[node] = true;

        totalCost += weight;

        // Explore all adjacent vertices
        for(auto it : adj[node]) {

            int adjNode = it.first;
            int edgeWeight = it.second;

            if(!visited[adjNode]) {
                pq.push({edgeWeight, adjNode});
            }
        }
    }

    cout << "Minimum cost: " << totalCost;

    return 0;
}
