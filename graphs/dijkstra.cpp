#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,source;
    cin>>n>>m>>source;
    vector<pair<int,int>>g[n+1];
    int a,b,wt;
    for(int i=0;i<m;i++)
    {
    cin>>a>>b>>wt;
    g[a].push_back({b,wt});
    g[b].push_back({a,wt});

    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    vector<int>distTo(n+1,INT_MAX);
distTo[source]=0;
pq.push(make_pair(0,source));
while(!pq.empty())
{
    int dist=pq.top().first;
    int prev=pq.top().second;
    pq.pop();
    vector<pair<int,int>>::iterator it;
    for(it=g[prev].begin();it!=g[prev].end();it++)
    {
        int next=it->first;
        int nextdis=it->second;
        if(distTo[next]>distTo[prev]+nextdis)
        {
            distTo[next]=distTo[prev]+nextdis;
            pq.push(make_pair(distTo[next],next));

        }
    }
}

for(int i=source;i<=n;i++)
{
    cout<<distTo[i]<<" ";

}
}