#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val)
    {
        data=val;
        right=NULL;
        left=NULL;

    }
};
Node* buildbalancedbst(vector<int>&v,int start,int end)
{
    if(start>end)
    return NULL;
    int mid=(start+end)/2;

    Node* root=new Node(v[mid]);
    root->left=buildbalancedbst(v,start,mid-1);
    root->right=buildbalancedbst(v,mid+1,end);
    return root;


}
void normalbst(Node* root,vector<int>&v)
{
    if(root==NULL)
    return ;
    normalbst(root->left,v);
    v.push_back(root->data);
    normalbst(root->right,v);

}
void preorder(Node* root)
{
    if(root==NULL)
    return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);

}
int main()
{
    Node* root=new Node(4);
    root->left=new Node(3);
    root->left->left=new Node(2);
    root->left->left->left=new Node(1);
    vector<int>v;
    normalbst(root,v);
    int n=v.size();
    Node* head=buildbalancedbst(v,0,n-1);
    preorder(head);




}