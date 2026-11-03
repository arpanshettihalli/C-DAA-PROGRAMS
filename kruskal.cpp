#include<bits/stdc++.h>
using namespace std;
int findparent(int node,vector<int>&parent)
{
  if(parent[node]==node)
  {
    return node;
  }
  return parent[node]=findparent(parent[node],parent);
}
void unionset(int u,int v,vector<int>&parent)
{
  int p_u=findparent(u,parent);
  int p_v=findparent(v,parent);
  if(p_u!=p_v)
  {
    parent[p_v]=p_u;
  }
}
int main()
{
  cout<<"enter the no of edges"<<endl;
  int m;
  cin>>m;
  cout<<"enter the number of vertices"<<endl;
  int n;
  cin>>n;
  vector<pair<int,pair<int,int>>edges;
  int u,v,wt;
  int cost=0;
  for(int i=0;i<m;i++)
  {
    cin>>wt>>u>>v;
    edges.push_back({wt,{u,v}});
  }
  vector<int>parent(n);
  sort(edges.begin(),edges.end());
  int count=0;
  for(int i=0;i<n;i++)
  {
    parent[i]=i;
  }
  for(int i=0;i<m;i++)
  {
    u=edges[i].second.first;
    v=edges[i].second.second;
    wt=edges[i].first;
    int p_u=findparent(u,parent);
    int p_v=findparent(v,parent);
    if(p_u!=p_v)
    {
      cout<<u<<"-->"<<v<<endl;
      cost+=wt;
      unionset(u,v,parent);
      count++;
    }
    if(count==m-1)
    {
      break;
    }
  }
  cout << "Minimum cost: " << cost << endl; 
  return 0;
}
