#include<bits/stdc++.h>
using namespace std;
struct Dquenode
{
    int value;
    struct Dquenode* prev;
    struct Dquenode* next;

};
class Deque
{

private:
Dquenode* head;
Dquenode* tail;
public:
Deque()
{
    head=NULL;
    tail=NULL;

}
bool isEmpty()
{
    if(head==NULL)
    return true;
    return false;

}
int size()
{
    if(!isEmpty())
    {
        int len=0;
         Dquenode* temp=head;
         while(temp!=NULL)
         {
             temp=temp->next;
             len++;

         }
         return len;


    }
    return 0;

}
void push_first(int val)
{
    Dquenode* temp=new Dquenode[sizeof(Dquenode)];
    temp->value=val;
    if(head==NULL)
    {
head=tail=temp;
temp->next=NULL;
temp->prev=NULL;
    }
    else{
    head->prev=temp;
    temp->next=head;
    temp->prev=NULL;

    head=temp;

    }

}
void push_last(int val)
{
 Dquenode* temp=new Dquenode[sizeof(Dquenode)];
  temp->value=val;
  if(head==NULL)
  {
      head=tail=temp;
      temp->next=NULL;
      temp->prev=NULL;

  }
  else
  {
      temp->prev=tail;
      tail->next=temp;
      tail=temp;
      temp->next=NULL;

  }
}

  void remove_first()
  {
       if(!isEmpty())
       {
           Dquenode* temp=head;
           head=head->next;
           if(head)
           {
               head->prev=NULL;
               delete temp;

           }
           if(head==NULL)
           tail=NULL;
           

       }
       cout<<"LIST IS EMPTY"<<endl;
      
    
  }
   void remove_last()
  {
       if(!isEmpty())
       {
           Dquenode* temp=tail;
           tail=tail->prev;
           if(tail)
           {
               tail->next=NULL;
               delete temp;

           }
           if(tail==NULL)
           head=NULL;
          

       }
       cout<<"LIST IS EMPTY"<<endl;
    
    
  }
  void display(){
      if(!isEmpty())
      {
          Dquenode* temp=head;
          while(temp!=NULL)
          {
              cout<<temp->value<<" ";
              temp=temp->next;

          }
          cout<<endl;
          return;

      }
      cout<<"list is empty"<<endl;

  }


};
class Stack:public Deque
{
public:
void pop()
{
remove_last();

}
void push(int val)
{
    push_last(val);

}
};

class Queue:public Deque
{
public:
void dequeue()
{
    remove_first();

}
void enqueue(int val)
{
    push_last(val);

}
};

int main()
{
    // object of Stack
    Stack stk;
 
    // push 7 and 8 at top of stack
    stk.push(7);
    stk.push(8);
    cout << "Stack: ";
    stk.display();
 
    // pop an element
    stk.pop();
    cout << "Stack: ";
    stk.display();
 
    // object of Queue
    Queue que;
 
    // insert 12 and 13 in queue
    que.enqueue(12);
    que.enqueue(13);
    cout << "Queue: ";
    que.display();
 
    // delete an element from queue
    que.dequeue();
    cout << "Queue: ";
    que.display();
 
    cout << "Size of Stack is " << stk.size() << endl;
    cout << "Size of Queue is " << que.size() << endl;
    return 0;
}