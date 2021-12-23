#include<bits/stdc++.h>
using namespace std;
class node
{
    /* data */
    public:
    int data;
    node* left;
node* right;
    node(int val)
    {
        data=val;
        left=NULL;
        right=NULL;

    }

};

node* mirror(node * root)
{
    if(!root)
    return NULL;
 
    
root->left=mirror(root->left);

root->right=mirror(root->right);

node* temp;
    temp=root->left;
    root->left=root->right;
    root->right=temp;
return root;
}
void inorder(struct node* root)
{
    if(root==NULL)
    return ;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);

}
int main()
{
   node* root=new node(12);
    root->left=new node(1);
    root->right=new node(8);
    root->left->left=new node(12);
    root->right->right=new node(9);
    
  node* head=  mirror(root);
    inorder(root);
    
}