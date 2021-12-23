#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pi (3.141592653589)
#define mod 1000000007
#define int long long
#define float double
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(c) c.begin(), c.end()
#define min3(a, b, c) min(c, min(a, b))
#define min4(a, b, c, d) min(d, min(c, min(a, b)))
#define rrep(i, n) for(int i=n-1;i>=0;i--)
#define rep(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);


bool isPrime(int n){
if(n==1) return false;
if(n==2) return true;
for(int i=2;i*i<=n;i++){
if(n%i==0)return false;
}
return true;
}

void solve(){

}
int coinchange(int coin[],int n,int total)
{
    int t[n+1][total+1];
          for(int j=0;j<total+1;j++)
        t[0][j]=0;
        for(int i=1;i<n+1;i++)
        t[i][0]=1;
    for(int i=1;i<n+1;i++)

{
for(int j=1;j<total+1;j++)
{
    if(coin[i-1]<=j)
    t[i][j]=t[i][j-coin[i-1]]+t[i-1][j];
    else 
    t[i][j]=t[i-1][j];

}
}


return t[n][total];
}
int32_t main(){
fast



// Fuck Ratings, I'm in Love with Experience.
// Once a Charas, Always a CHARAS.


int coin[]={1,2,3};
int n=3;
int ans=coinchange(coin,3,5);
cout<<ans<<endl;

}
