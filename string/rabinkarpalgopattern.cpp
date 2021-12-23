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
#define d 256//we are taking d=256 bcuz there are 256 chars in c++ and in the hashing func the exponential factor that we are taking is 256
void search(char pat[],char txt[],int q)
{
    int N=strlen(txt);
    int M=strlen(pat);
    int i,j;
    int p=0;
    int t=0;
    int h=1;
    for(i=0;i<M-1;i++)
    {
        h=(h*d)%q;

    }
    //here we are computing the hashed value of the intial window of length M for both txt and pat
for(i=0;i<M;i++)
{
    p=(d*p+pat[i])%q;
    t=(d*t+txt[i])%q;


}
//after computing initial hashing values ,we move on to check if the hasing value of both the txt and pat staring with index i with length m has equal value
//if yes then we check them char by char and if it matches exactly then we print the staring index of the pattern

for(i=0;i<=N-M;i++)
{
    if(p==t)
    {
    
    for(j=0;j<M;j++)
    {
        if(txt[i+j]!=pat[j])
        {
    
            break;
        }


    }

    if(j==M)
    cout<<"Pattern found at index "<<i<<endl;
    }
    //if we dont find the pattern similar then we move on to the next window and compute the hash fucntion by removing the contributing value of the prev starting index and adding the new index s
    if(i<N-M)
    {
        t=((t-txt[i]*h)*d+txt[i+M])%q;//this is that hashing funcs
        if(t<0)//if the hashing func becomes -ve then we apply modular arithmetic and add it with the prime num to make +ve'
        t=t+q;

    }


}

}
void solve() {
char txt[]="GEEKS FOR GEEKS";
char pat[]="GEEK";
int q=101;
search(pat,txt,q);


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
