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
vector<int> nearestgreatertoright(int arr[],int n)
{
    stack<int>s;
    s.push(arr[n-1]);
    vector<int>v;
    v.push_back(-1);
    for(int i=n-2;i>=0;i--)
    {
       

        while(!s.empty())
        {
            if(arr[i]<s.top())
            break;
            else
            s.pop();

        }
        if(s.empty())
        v.push_back(-1);
        else
        v.push_back(s.top());

        s.push(arr[i]);
        



    }
    return v;
}

void solve(){

}
int32_t main(){
fast


// Fuck Ratings, I'm in Love with Experience.
// Once a Charas, Always a CHARAS.

int arr[4]={1,3,2,4};
int n=4;
vector<int>ans;
 ans=nearestgreatertoright(arr,n);
rep(i,n)
{
    cout<<ans[i]<<endl;

}

}
