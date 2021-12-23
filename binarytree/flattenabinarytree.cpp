#include<bits/stdc++.h>
using namespace std;
class node
{
    public:
    int data;
    node* left,*right;
   
};


node* New_Node(int data)
{
    node* Newnode=new node();
    Newnode->data=data;
    Newnode->left=NULL;
    Newnode->right=NULL;
    return Newnode;
}

void flatten(node* root)
{
    if(root==NULL||(root->left==NULL&&root->right==NULL))
    return;
    if(root->left!=NULL)
    {
        flatten(root->left);

    
    node* temp=root->right;
    root->right=root->left;
    root->left=NULL;
    node* t=root->right;
    while(t->right!=NULL)
    t=t->right;
    t->right=temp;

}
flatten(root->right);
}
void inorder(node* root)
{
    if(root==NULL)
    return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
    
}


int main()

{
    node* root=New_Node(1);
    root->left=New_Node(2);
    root->right=New_Node(3);
    root->left->left=New_Node(4);
    root->left->right=New_Node(5);
flatten(root);
inorder(root);
    return 0;


}