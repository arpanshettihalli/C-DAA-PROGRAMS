#include<bits/stdc++.h>
using namespace std;
void dijsktra(vector<vector<pair<int,int>>>&adj,int src,int n)
{
    vector<int>dist(n,INT_MAX);
    dist[src]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,src});
    while(!pq.empty())
    {
        int u=pq.top().first;
        pq.pop();
        for(auto it:adj[u])
        {
            int wt=it.first;
            int u=it.second;
            if(dist[u]+wt<dist[v])
            {
                dist[v]=dist[u]+wt;
                pq.push({v,dist[v]});
            }
        }
    }
    cout<<"the shortest distance from source vertex "<<src<<" to all other vertices is:"<<endl;
    for(int v=0;v<n;v++)
    {
        cout<<v<<" "<<dist[v]<<" ";
    }
    cout<<endl;
}
int main()
{
    cout<<"enter the number of vertices and edges"<<endl;
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>>adj(n);
    for(int i=0;i<m;i++)
    {
        int u,v,wt;
        cin>>u>>v>>wt;
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }
    int src;
    cout<<"enter the source vertex"<<endl;
    cin>>src;
    dijsktra(adj,src,n);
    return 0;
}