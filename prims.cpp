#include<bits/stdc++.h>
using namespace std;
int main()
{
    cout<<"enter the adjacency matrix of the graph"<<endl;
    int n;
    int cost=0;
    cin>>n;
    int adj[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>adj[i][j];
        }
    }
    int visited[n]={0};
    visited[0]=1;
    int edges=0;
    while(edges<n-1)
    {
        int min=INT_MAX;
        int u=-1;
        int v=-1;
        for(int i=0;i<n;i++)
        {
          if(visited[i])
          {
            for(int j=0;j<n;j++)
            {
              if(!visited[j] and adj[i][j]!=0)
              { 
                if(adj[i][j]<min)
                {
                  u=i;
                  v=j;
                  min=adj[i][j];
                }
              }
            }
          }
        }
        cout<<u<<"-->"<<v<<endl;
        visited[v]=1;
        edges+=1;
        cost+=min;
                
    }
    cout<<"cost:"<<cost;
    return 0;

}
