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



bool t[10][20];
bool subsetsum(int arr[],int n,int sum)

{
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<sum+1;j++)
        {
            if(i==0)
            t[i][j]=true;
            else if(j==0)
            t[i][j]=false;

        }
    }
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<sum+1;j++)
        {
if(arr[i-1]<=j)
t[i][j]=(t[i-1][j-arr[i-1]])||(t[i-1][j]);
else 
t[i][j]=t[i-1][j];

        }
    }
    return t[n][sum];


    

}
bool equalsumpartition(int arr[],int n)
{
    int sum=0;
    for(int i=0;i<n;i++)
    sum+=arr[i];
    if(sum%2!=0)
    return -1;
    else
    return subsetsum(arr,n,sum/2);

}

int32_t main(){
fast


// Fuck Ratings, I'm in Love with Experience.
// Once a Charas, Always a CHARAS.

int n=5;

int arr[n]={2,3,7,8,10};

if(equalsumpartition(arr,n))
cout<<"1"<<endl;
else
cout<<"0"<<endl;




}
