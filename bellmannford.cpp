#include<bits/stdc++.h>
using namespace std;
void bellmanford(vector<pair<int,pair<int,int>>>&edges,int v,int src)
{
    vector<int>dist(v,INT_MAX);
    dist[src]=0;
    for(int i=0;i<v-1;i++)
    {
        for(auto it:edges)
        {
            int u=it.first;
            int v=it.second.first;
            int wt=it.second.second;
            if(dist[u]!=INT_MAX && dist[u]+wt<dist[v])
            {
                dist[v]=dist[u]+wt;
            }
        }
    }
    for(auto it:edges)
    {
        int u=it.first;
        int v=it.second.first;
        int wt=it.second.second;
        if(dist[u]!=INT_MAX && dist[u]+wt<dist[v])
        {
            cout<<"negative weight cycle detected"<<endl;
            return;
        }
    }
    cout<<"the shortest distance from source vertex "<<src<<" to all other vertices is:"<<endl;
    for(int i=0;i<v;i++)
    {
        cout<<i<<" "<<dist[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    int v=6;
    vector<pair<int,pair<int,int>> edges;
    edges.push_back({0,{1,2}});
    edges.push_back({0,{2,4}});
    edges.push_back({1,{2,1}});
    edges.push_back({1,{3,7}});
    edges.push_back({2,{4,-3}});
    edges.push_back({3,{4,1}});
    bellmanford(edges,v,0);
    return 0;



}