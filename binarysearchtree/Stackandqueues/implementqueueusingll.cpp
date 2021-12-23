#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
    Node(int val)
    {
        data=val;
        next=NULL;

    }

};
class Queue
{
Node* Front;
Node* Rear;
public:
Queue()
{
    Front=NULL;
    Rear=NULL;

}
void push(int val)
{
    Node* n=new Node(val);
    if(Front==NULL)
    {
        Rear=n;
        Front=n;
    }
    Rear->next=n;
    Rear=n;



}
void pop()
{
    if(Front==NULL){
            cout<<"Queue underflow"<<endl;
    return;}
    Node* todelete=Front;
    Front=Front->next;
delete todelete;

}
int peek()
{
    if(Front==NULL)
    {
        cout<<"No element in queue"<<endl;
        return 0;
    }
    return Front->data;
}

bool empty()
{
    if(Front==NULL)
    {
        return true;
    }
    return false;
}



};

int main()
{
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    cout<<q.peek()<<endl;
    q.pop();
    cout<<q.peek()<<endl;
    q.pop();
    cout<<q.peek()<<endl;
    q.pop();
    cout<<q.peek()<<endl;
    q.pop();


}