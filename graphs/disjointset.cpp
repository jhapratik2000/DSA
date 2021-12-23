#include<bits/stdc++.h>
using namespace std;
int n=7;


int findPar(int node,vector<int>&parent)
{
    if(node==parent[node])
    return node;
    return parent[node]=findPar(parent[node],parent);

}

void unity(int u,int v,vector<int>&parent,vector<int>&ran)
{
    int a=findPar(u,parent);
    int b=findPar(v,parent);
    if(ran[a]<ran[b])
    {
        parent[a]=b;
    }
    else if(ran[b]<ran[a])
    {
        parent[b]=a;

    }
    else
    {
        parent[b]=a;
        ran[a]++;

    }
}
int main()
{


    vector<int>parent(100000);
vector<int>ran(100000);
int n=7;
for(int i=1;i<=n;i++)
{
    parent[i]=i;
    ran[i]=0;

}
    int m;
    cin>>m;

    
    while(m--)
    {
        int u,v;
        cin>>u>>v;
        unity(u,v,parent,ran);

    }

    for(int i=1;i<=n;i++)
    {
        cout<<ran[i]<<" ";

    }

    
}