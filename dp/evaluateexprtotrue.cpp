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
int evaluate(string s,int i,int j,bool isTrue)
{
    if(i>j)
    return true;
    if(i==j)
    {
    if(isTrue==true)
    {
return s[i]=='T';}
else
    return s[i]=='F';



}
int ans=0;
for(int k=i+1;k<=j-1;k+=2)
{
int lt=evaluate(s,i,k-1,true);
int lf=evaluate(s,i,k-1,false);
int rt=evaluate(s,k+1,j,true);
int rf=evaluate(s,k+1,j,false);

if(s[k]=='&'){
if(isTrue==true)
ans+=lt*rt;
else
ans+=lt*rf+lf*rt+rf*lf;}
else if(s[k]=='|')
{
if(isTrue==true)
ans+=lt*rt+lt*rf+rt*lf;
else
ans+=lf*rf;}
else if(s[k]=='^')
{
    if(isTrue==true)
    ans+=lt*rf+lf*rt;
    else
    ans+=lt*rt+lf*rf;

}
}
return ans;
}








int32_t main(){
fast


// Fuck Ratings, I'm in Love with Experience.
// Once a Charas, Always a CHARAS.


string s="T|T&F^T";
int n=s.length();
int numofways=evaluate(s,0,n-1,true);
cout<<numofways<<endl;


}
