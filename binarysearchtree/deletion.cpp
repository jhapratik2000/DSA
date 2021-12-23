#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
};
Node* inordersucc(Node* root)
{
    Node* curr=root;
    while(curr!=NULL&&curr->left!=NULL)
    {
        curr=curr->left;
    }
    return curr;

}
Node* deleteinbst(Node* root,int key)
{  if(!root)
            return NULL;
    if(!root->left && !root->right)
            {
                delete(root);
                return NULL;
            }    
    if(key<root->data)
    root->left=deleteinbst(root->left,key);
   else if(key>root->data)
    root->right=deleteinbst(root->right,key);
    else{
    if(root->left==NULL){
    Node* temp=root->right;
    
    free(root);
    return temp;}
    else if(root->right==NULL){
    Node* temp=root->left;
    free(root);
    return temp;}

Node* temp=inordersucc(root->right);
root->data=temp->data;
root->right=deleteinbst(root->right,temp->data);
    }
return root;

}

Node* insertBST(Node* root,int val)
{
    if(root==NULL)
    return new Node(val);
    if(root->data>val)
    root->left=insertBST(root->left,val);
    if(root->data<val)
    root->right=insertBST(root->right,val);
    return root;
}
void inorder(Node* root)
{
    if(root==NULL)
    return ;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main()
{
    Node* root=NULL;
    
    root=insertBST(root,5);
    root=insertBST(root,1);
    root=insertBST(root,3);
    root=insertBST(root,4);
    root=insertBST(root,2);
    root=insertBST(root,7);
    inorder(root);
    cout<<"\n";
     root=deleteinbst(root,3);
     inorder(root);

}