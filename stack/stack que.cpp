#include<bits/stdc++.h>
using namespace std;

void findtotalsum(vector<string>&ops)
{
    if(ops.empty()){
        cout<<"0";
}
    stack<int>b;
    int ans=0;
    for(int i=0;i<ops.size();i++){
        if(ops[i]=="C"){
            ans-=b.top();
        b.pop();}
    else if(ops[i]=="D")
    {
        b.push(2*b.top());
        ans+=b.top();



    }
    else if(ops[i]=="+")
    {
        int first=b.top();
        b.pop();
        int second=b.top();
        b.push(first);
        int third=second+first;
        b.push(third);
        ans+=second+first;

    }

    else
    {
        int n=stoi(ops[i]);
        ans+=n;
        b.push(n);

    }
    }

    cout<<ans;
    }






int main()
{
    vector<string>arr={"5","-2","C","D","+"};
    findtotalsum(arr);

}
