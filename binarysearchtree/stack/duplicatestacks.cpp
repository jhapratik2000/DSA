#include<bits/stdc++.h>
using namespace std;
bool solve(string s)
{

    stack<char>stck;
    
    int len=s.length();
    

    for(int i=0;i<len;i++)
    {
        if(s[i]==')')
        {
            if(stck.top()=='('){
            cout<<"("<<endl;

            return true;
            }
            else
            {
                while(stck.top()!='('){
                    cout<<stck.top()<<endl;

                stck.pop();}
                cout<<stck.top()<<endl;

stck.pop();
            }


        }
        else
        stck.push(s[i]);

    }

    return false;

}
int main()
{
    string s;
    cin>>s;
    if(solve(s))
    cout<<"true"<<endl;
    else
    cout<<"false"<<endl;

}