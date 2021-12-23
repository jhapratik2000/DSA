#include<bits/stdc++.h>
using namespace std;
class node
{
    public:
    int data;
    node* next;
    node(int val)
    {
        data=val;
        next=NULL;

    }
   /* node* newNode(int x);
    int pop();
    int peek();
    bool isEmpty();
*/

};
/* node* newNode(int data)
{
    node* newnode = new node();
    newnode->data=data;
    newnode->next=NULL;
    return newnode;


} */
void push(node** root,int data)//initially root==NULL and in the func we are passing pointer to pointer that means *root here will give me the address of NULL..which is NULL
{
    node* newnode=new node(data);
    newnode->next=*root;//initially let's say we push 2 then we will make the next pointer of 2 point to NULL and hence we'll dereference the root pointer
    *root=newnode;//in the dereferenced root pointer we will store the address of 2
    cout<<data<<" pushed to stack\n";

}

bool isEmpty(node* root)
{
    return !root;
}
int pop(node** root)
{
    if(isEmpty(*root))
    return -1;
    else
    {
        node* temp;
        temp=*root;
        int popped=temp->data;
        *root=(*root)->next;
        free(temp);
        return popped;
    }
}

int top(node* root)
{
    if(isEmpty(root))
    return -1;
    else
    {
        
        return root->data;
    }
}
int main()
{
    node* root=NULL;
    push(&root,10);
    push(&root,20);
    push(&root,30);


    cout<<" the popped element is : "<<pop(&root)<<endl;
    cout<<"Top element is : "<<top(root)<<endl;
    cout<<"Elements present in  a stack : "<<endl;

    while(!isEmpty(root))
    {
        cout<<top(root)<<endl;
        pop(&root);

    }


}


