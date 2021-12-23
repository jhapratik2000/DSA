#include<bits/stdc++.h>
using namespace std;
int  main()
{
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>>adj[n];
    for(int i=0;i<m;i++)
    {
        int a,b,wt;
        cin>>a>>b>>wt;
        adj[a].push_back({b,wt});
        adj[b].push_back({a,wt});

    }
    int parent[n];
    int key[n];
    bool mst[n];
    for(int i=0;i<n;i++)
    {
        key[i]=INT_MAX;
        mst[i]=false;
        parent[i]=-1;

    }
    key[0]=0;
    parent[0]=-1;
    for(int cnt=0;cnt<n-1;cnt++)
    {
        int mini=INT_MAX;
        int u;
        for(int v=0;v<n;v++)
        {
            if(mst[v]==false&&key[v]<mini)
            {
                mini=key[v];
                u=v;

            }
            mst[u]=true;
            for(auto it:adj[u])
            {
                int v=it.first;
                int weight=it.second;
                if(mst[v]==false&&weight<key[v])
                parent[v]=u;
                key[v]=weight;

            }
        }
    }
    
    for(int i=1;i<n;i++)
    {
        cout<<parent[i]<<" - "<<i<<"\n";
        
    }
}