#include<bits/stdc++.h>
using namespace std;

 long long balancedparantheses(string &str)
 {
     stack<string>s;
     int len=str.length();
     for(int i=0;i<len;i++)
        if(str[i]=='(')
        s.push("(");

        else{
            if(s.top()=="("){
            s.pop();
            s.push("1");}

            else{
                int count=0;
            while(s.top()!="(")
            {
                count+=stoi(s.top());
                s.pop();
            }
            s.pop();
            s.push(to_string(2*count));
            }
        }
        int ans=0;
        while(!s.empty())
        {
            ans+=stoi(s.top());
            s.pop();

        }
        return ans;


 }


int  main()
{
    string s1="(()(()))";
    cout<<balancedparantheses(s1)<<endl;

}
