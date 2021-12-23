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
bool isBST(Node* root,Node* min,Node* max)
{
    if(root==NULL)
    return true;
    if(min!=NULL&&root->data<=min->data)
    return false;
    if(max!=NULL&&root->data>=max->data)
    return false;
    bool isLeftValid=isBST(root->left,min,root);
    bool isRightValid=isBST(root->right,root,max);
    return isLeftValid&&isRightValid;
}



int main()
{
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    if(isBST(root,NULL,NULL))
    cout<<"IT IS A BST";
    else
    cout<<"IT IS NOT A BST";
    
}