//kahn's algorithm (queue is used).it is used in topological sort in bfs 

//topological sort is only used in directed acyclic graph ,so if i have to check if it is acyclic or not 
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
bool isCycle(int n,vector<int>adj[])//we are using a counter intuitive method that if the cnt of the nodes that form the part of toposort is equal to the total no of nodes then the whole graph is acyclic and it will return false 
{
    vector<int>ans;
    queue<int>q;
    vector<int>indegree(n,0);
    for(int i=0;i<n;i++)
{
    for(auto it:adj[i])

    {
        indegree[it]++;


    }
}

    for(int i=0;i<n;i++)
    {
        if(indegree[i]==0)
        q.push(i);

    }
int cnt=0;
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        cnt++;
        ans.push_back(node);
        for(auto it:adj[node])
        {
            
            indegree[it]--;
           if(indegree[it]==0)
           q.push(it);
           

        }
    }
    if(cnt==n)
    return false;
    return true;
    
    


}

void solve() {
int n,m;
cin>>n>>m;
vector<int>adj[n+1];
for(int i=0;i<m;i++)

{
    int a,b;
    cin>>a>>b;
    adj[a].push_back(b);

}
if(isCycle(n,adj))
cout<<"IT IS A DIRECTED CYCLIC GRAPH"<<endl;
else
cout<<"IT IS A DIRECTED ACYCLIC GRAPH"<<endl;


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
