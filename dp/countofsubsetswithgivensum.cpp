#include <bits/stdc++.h>
using namespace std;

#define pi (3.141592653589)
#define mod 1000000007
#define ll long long
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




int subsetwithgivensum(int arr[],int n,int sum)

{
    int t[n+1][sum+1];

    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<sum+1;j++)
        {
            if(j==0)
            t[i][j]=1;
            else if(i==0)
            t[i][j]=0;

        }
    }
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<sum+1;j++)
        {
if(arr[i-1]<=j)
t[i][j]=t[i-1][j-arr[i-1]]+t[i-1][j];
else 
t[i][j]=t[i-1][j];

        }
    }
    return t[n][sum];


    

}


int32_t main(){
fast


// Fuck Ratings, I'm in Love with Experience.
// Once a Charas, Always a CHARAS.

int n=6;

int arr[n]={2,3,5,6,8,10};
int sum=10;
int ans=subsetwithgivensum(arr,6,10);
cout<<ans<<endl;







}
