#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
int data;
Node* next;

};

Node* push(Node* head,int data)
{
    Node* node=new Node();
    node->data=data;
    node->next=head;
    head=node;
    return head;

}

Node* movetostart(Node* head)
{

    if(!head||!head->next)
    return head;

    Node* curr=head;
    Node* prev=NULL;
    while(curr->next!=NULL)
    {
        prev=curr;
        curr=curr->next;
        

    }
    prev->next=NULL;
    curr->next=head;
    head=curr;
return head;

}
void printlist(Node* node)
{
    while(node!=NULL)
    {
        cout<<node->data<<" ";
        node=node->next;

    }
    cout<<endl;
    
}

int main()
{
Node* head=NULL;
Node* first=push(head,5);
Node* second=push(first,4);
Node* third=push(second,3);
Node* fourth=push(third,2);
Node* fifth=push(fourth,1);


printlist(fifth);
Node* curr=movetostart(fifth);
printlist(curr);



}


