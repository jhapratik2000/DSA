#include<bits/stdc++.h>
using namespace std;
void insertatbottom(char x,stack<char>&s)
{
    if(s.empty()){
    s.push(x);
    return;}
    else
    {
        char a=s.top();
        s.pop();
        insertatbottom(x,s);
        s.push(a);

    }

}
void Reverse(stack<char>&s)
{
    if(s.empty())
    return;
    else
    {
        char x=s.top();
        s.pop();
        Reverse(s);
        insertatbottom(x,s);


    }
}
int main ()
{
stack<char>s;
s.push('1');
s.push('2');
s.push('3');
s.push('4');
s.push('5');
Reverse(s);

while(!s.empty())
{
    cout<<s.top()<<" ";
    s.pop();
    
}

}