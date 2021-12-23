#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
class node
{
      int top;

    public:
  
    
    int a[MAX];
    node()
    {
        top=-1;

    }
   bool push(int x);
    int pop();
    int peek();
    bool isEmpty();



};

bool node:: push(int x)
{
    if(top>=MAX-1){
    cout<<"OVERFLOW"<<endl;
    return 0;}
    else
    {
        a[++top]=x;
        cout<<x<<" pushed into stack\n";
        return true;

    }



}
int node::pop()
{
    if(top<0)
    {
        cout<<"Stack Underflow";
        return 0;
    }
    else
    {
        int x=a[top--];
        return x;
    }
}
int node::peek()
{
    if(top<0)
    {
        cout<<"Stack is empty";
        return 0;
    }
    else{
        int x=a[top];
        return x;

    }
}
bool node::isEmpty()
{
    return top<0;

}
int main()
{
  class  node s;
  s.push(10);
  s.push(20);
  s.push(30);
  
  cout << s.pop() << " Popped from stack\n";
    //print all elements in stack :
    cout<<"Elements present in stack : ";
    while(!s.isEmpty())
    {
        // print top element in stack
        cout<<s.peek()<<" ";
        // remove top element in stack
        s.pop();
    }
 
    return 0;



}