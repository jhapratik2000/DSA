#include<bits/stdc++.h>
using namespace std;

void dfs(int node,vector<int>&vis,vector<int>&storedfs,vector<int>adj[])
{
    storedfs.push_back(node);
    vis[node]=1;
    for(auto it:adj[node])
    {
        if(!vis[it])
        {
            dfs(it,vis,storedfs,adj);

        }
    }
}
vector<int>dfsofGraph(int V,vector<int>adj[])
{
    vector<int>vis(V+1,0);
    vector<int>storedfs;
    for(int i=1;i<=V;i++)
    {
        if(!vis[i])
        dfs(i,vis,storedfs,adj);

    }
    return storedfs;

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
vector<int>ans=dfsofGraph(V,adj);
for(int i=0;i<ans.size();i++)
{
    cout<<ans[i]<<" ";

}
cout<<endl;

}