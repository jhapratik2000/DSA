#include<bits/stdc++.h>
using namespace std;
//in bfs we take queue data structure

vector<int>bfsofGraph(int V,vector<int>adj[])
{
    vector<int>bfs;
    vector<int>vis(V+1,0);

    for(int i=1;i<=V;i++)
    {
        if(!vis[i])
        {
            queue<int>q;
            q.push(i);
            vis[i]=1;

while(!q.empty())
{
    int node=q.front();
    q.pop();
    bfs.push_back(node);
  for(auto it:adj[node])
  {
      if(!vis[it])
      {
          q.push(it);
          vis[it]=1;

      }
  }

    }
        }
    }
    return bfs;
    
}
int main()
{
int V;
cin>>V;
vector<int>adj[V];
for(int i=0;i<V-1;i++)
{
    int u,v;
    cin>>u>>v;
    adj[u].push_back(v);

    adj[v].push_back(u);
    

}
vector<int>ans=bfsofGraph(V,adj);
for(int i=0;i<ans.size();i++)
{
    cout<<ans[i]<<" ";

}
cout<<endl;

}