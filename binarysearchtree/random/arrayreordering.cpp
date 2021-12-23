
/*wrong ans
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        cin>>arr[i];
        int even=0;
        for(int i=0;i<n;i++){
        if(arr[i]%2==0)
        even++;
        }
        int odd=n-even;
        
        vector<int>v;
        
        for(int i=0;i<n;i++){
        if(arr[i]%2==0){
    
        v.push_back(arr[i]);}}

        for(int i=0;i<n;i++){
        if(arr[i]%2!=0)
        v.push_back(arr[i]);}

int ans=0;
bool f=1;
if(even==1){
ans=odd;
f=0;}
else
ans=even*(even-1)/2;
if(f)
ans+=even*odd;

int start=v[even];
int count=1;
bool flag=0;
sort(v.begin()+even,v.end());
for(int i=even+1;i<n;i++)
{
    if(flag)
    count=1;
    if(v[i]%start==0&&start!=1)
    {
        count++;
        ans+=count*(count-1)/2;

    }
    else{
    start=v[i];
    flag=1;
    }


}


      cout<<ans<<endl;  
}
}*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        cin>>arr[i];
        int ans=0;
        for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
                    if(__gcd(arr[i],2*arr[j])>1||__gcd(arr[j],2*arr[i])>1)
                    ans++;
    }}
    cout<<ans<<"\n";
}
}