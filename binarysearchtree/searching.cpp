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
Node* searchin(Node* root,int key)
{
    if(root==NULL)
    return NULL;
    if(root->data==key)
    return root;
    if(root->data>key)
    return searchin(root->left,key);
    return searchin(root->right,key);

}
Node* insert(Node* root,int val)
{
    if(root==NULL)
    return new Node(val);
    if(root->data>val)
    root->left=insert(root->left,val);
    if(root->data<val)
    root->right=insert(root->right,val);
    return root;

}
int main()
{
    Node* root=NULL;
      root=insert(root,5);
    root=insert(root,1);
    root=insert(root,3);
    root=insert(root,4);
    root=insert(root,2);
    root=insert(root,7);
    if(searchin(root,10)==NULL)

    cout<<"key doesn't exist";
    else
    cout<<"key exists";

}
