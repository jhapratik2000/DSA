#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;

};

Node* push(Node* head,int val)
{
 Node* temp=new Node();
 temp->data=val;
 temp->next=head;
 if(head!=NULL)
 {
     Node* curr=head;
     while(curr->next!=head)
     {
         curr=curr->next;

     }
     curr->next=temp;
 }
     else
     temp->next=temp;

     head=temp;

     return head;


 }

Node* del(Node* head,int val)
{
if(head==NULL)
return NULL;
if(head->next==NULL)
{
    Node* curr=head;
    head=NULL;
    delete(curr);
    return head;

}
Node* last=head;
Node* d;

if(head->data==val)
{
    while(last->next!=head);
    last=last->next;
    last->next=head->next;
    Node* curr=head;
    head=head->next;
    free(curr);
    return head;

}

while(last->next!=head&&last->next->data!=val)
{
    last=last->next;

}

if(last->next->data=val)
{
    d=last->next;
    last->next=d->next;
    free(d);

}
return head;


}



int main()
{
Node* head=NULL;
Node* first=push(head,1);
Node* second=push(first,2);
Node* third=push(second,3);
Node* curr_head=del(third,2);
Node* curr=curr_head;

cout<<curr->data<<" ";
curr=curr->next;


while(curr!=curr_head)
{
    cout<<curr->data<<" ";
    curr=curr->next;

}



}