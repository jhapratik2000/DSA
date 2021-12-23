#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
int data;
Node* next;
Node* prev;

};

void pairsum(Node* head,int x)
{
    Node* first=head;
    Node* second=head;
    while(second->next!=NULL)
    {
        second=second->next;

    }
    bool found=false;
    while(first!=second&&second->next!=first)
    {
        if(first->data+second->data==x)
        {
            found=true;
            cout<<first->data<<" "<<second->data<<endl;
            first=first->next;
            second=second->prev;

        }
        else

        {
            if(first->data+second->data<x)
            {
                first=first->next;

            }
            else
            second=second->prev;

        }

    }
if(found==false)
cout<<"NO PAIR FOUND"<<endl;
}

void insert(Node** head,int data)
{
    Node* temp=new Node;
    temp->data=data;
    temp->next=temp->prev=NULL;
    if(!*(head))
    {
        *head=temp;

    }
    else
    {
        temp->next=*head;
        (*head)->prev=temp;
       *head=temp;

    }
}

int main()
{
    Node* head=NULL;
    insert(&head,9);
    insert(&head, 9);
    insert(&head, 8);
    insert(&head, 6);
    insert(&head, 5);
    insert(&head, 4);
    insert(&head, 2);
    insert(&head, 1);
    int x = 7;
 
pairsum(head, x);


}