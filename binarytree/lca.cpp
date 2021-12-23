#include<bits/stdc++.h>
using namespace std;
class node
{
    public:
    int data;
    node* left,*right;
    node(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
   
};
bool getpath(node*root,int n,vector<int>&path)
{
    if(root==NULL)
        return false;
    path.push_back(root->data);
    if(root->data==n)
    return true;
    if(getpath(root->left,n,path)||getpath(root->right,n,path))
    return true;
    path.pop_back();
    return false;

}
int lca(node*root,int n1,int n2)
{
    vector<int>path1,path2;
    if(!getpath(root,n1,path1)||!getpath(root,n2,path2))
    return -1;

    int pc=0;
    for(;pc<path1.size()&&path2.size();pc++)
    {
        if(path1[pc]!=path2[pc])
        break;

    }
    return path1[pc-1];

}
int main()
{
    node* root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->right->left=new node(5);
    root->right->right=new node(6);
    root->right->left->left=new node(7);
    int n1=7;
    int n2=6;

    int LCA=lca(root,n1,n2);
    cout<<LCA;
}