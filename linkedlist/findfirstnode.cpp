#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int key;
    Node* next;

};
Node* newNode(int key)
{
Node* temp=new Node();
temp->key=key;
temp->next=NULL;
return temp;

}
Node* detectandremove(Node* head)
{
    if(!head||!head->next)
    {
        return NULL;

    }
    Node* fast=head;
    Node* slow=head;
    slow=slow->next;
    fast=fast->next->next;
    while(fast!=NULL&&fast->next!=NULL)
    {
        if(slow==fast)
        break;
        slow=slow->next;
        fast=fast->next->next;

    }
    if(slow!=fast)
    return NULL;
    slow=head;
    while(slow!=head)
    {
        slow=slow->next;
        fast=fast->next;

    }
    return slow;
    

}
int main()
{
 Node* head = newNode(50);
    head->next = newNode(20);
    head->next->next = newNode(15);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(10);
 
    /* Create a loop for testing */
    head->next->next->next->next->next = head->next->next;
    Node* res = detectandremove(head);
    if (res == NULL)
        cout << "Loop does not exist";
    else
        cout << "Loop starting node is " << res->key;
 
    return 0;

}