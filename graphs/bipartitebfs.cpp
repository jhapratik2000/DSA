#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(int i=0;i<n;i++)
#define Fo(i,k,n) for(int i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long
#define si(x)	scanf("%d",&x)
#define sl(x)	scanf("%lld",&x)
#define ss(s)	scanf("%s",s)
#define pi(x)	printf("%d\n",x)
#define pl(x)	printf("%lld\n",x)
#define ps(s)	printf("%s\n",s)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair

#define min3(a, b, c) min(c, min(a, b))
#define min4(a, b, c, d) min(d, min(c, min(a, b)))
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pl;
typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
typedef vector<vi>		vvi;
typedef vector<vl>		vvl;

#define min3(a, b, c) min(c, min(a, b))
#define min4(a, b, c, d) min(d, min(c, min(a, b)))

bool isPrime(int n){
if(n==1) return false;
if(n==2) return true;
for(int i=2;i*i<=n;i++){
if(n%i==0)return false;
}
return true;
}


mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}
int mpow(int base, int exp); 
void ipgraph(int n, int m);
void dfs(int u, int par);

const int mod = 1'000'000'007;
const int N = 3e5, M = N;
//=======================

vi g[N];
int a[N];
bool checkbipartite(int src,vector<int>adj[],int color[])
{
queue<int>q;//we will take queue and push the src node and color it with a particular color(color=1) and then we will use bfs traversal to traverse all the adj nodes and if they aren't colored then we will color it with opp of node's color and
//push it to queue ,if the adj node is already colored then we will check if it is equal to parent node color.if yes then not bipartite if yes then continue
q.push(src);
color[src]=1;
while(!q.empty())
{
    int node=q.front();
    q.pop();
    for(auto it:adj[node])
    {
        if(color[it]==-1)
        {
            color[it]=1-color[node];
            q.push(it);

        }
        else if(color[it]==color[node])
        return false;

    }
}
    return true;

}

bool bipartite(int V,vector<int>adj[])
{
    int color[V];
    memset(color,-1,sizeof(color));
for(int i=0;i<V;i++)
{
    if(color[i]==-1)
    if(!checkbipartite(i,adj,color));//if any of the component is not bipartite then the graph is not bipartite 
    return false;

}
return true;

}
void solve() {

int V;
cin>>V;
vector<int>adj[V+1];
for(int i=0;i<V-1;i++)
{
    int a,b;
    cin>>a>>b;
    adj[a].push_back(b);
    adj[b].push_back(a);

}
if(bipartite(V,adj))
cout<<"IT IS A BIPARTITE GRAPH"<<endl;
else
cout<<"IT IS NOT A BIPARTITE GRAPH"<<endl;

}

 

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    int t = 1;
    cin >> t;
    while(t--) {
      solve();
    }

    return 0;
}

int mpow(int base, int exp) {
  base %= mod;
  int result = 1;
  while (exp > 0) {
    if (exp & 1) result = ((ll)result * base) % mod;
    base = ((ll)base * base) % mod;
    exp >>= 1;
  }
  return result;
}

void ipgraph(int n, int m){
	int i, u, v;
	while(m--){
		cin>>u>>v;
    u--, v--;
		g[u].pb(v);
		g[v].pb(u);
	}
}

void dfs(int u, int par){
	for(int v:g[u]){
		if (v == par) continue;
		dfs(v, u);
	}
}
