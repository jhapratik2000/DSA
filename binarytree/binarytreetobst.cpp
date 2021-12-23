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
    void inorder(node*root,vector<int>&v)
    {
        if(root==NULL)
        return;
        inorder(root->left,v);
        v.push_back(root->data);
        inorder(root->right,v);

    }
node* buildbalancedbst(vector<int>v,int start,int end)
{
    if(start>end)
    return NULL;
    int mid=(start+end)/2;
    node* root=new node(v[mid]);//mid of the vector is always the root of the bst
    root->left=buildbalancedbst(v,start,mid-1);//left subtree of root is created from the left of the mid of the vector
    root->right=buildbalancedbst(v,mid+1,end);//right subtree of the root is created from the right of the mid of the vector 
    return root;


    
}
   void printinorder(node*root)
   {
       if(root==NULL)
       return;
       printinorder(root->left);
       cout<<root->data<<" ";
       printinorder(root->right);

   }
int main()
{
    node* root=new node(7);
    root->left=new node(3);
    root->right=new node(2);
    root->left->left=new node(1);
    root->right->left=new node(5);
    root->right->right=new node(6);
    
    vector<int>v;
inorder(root,v);//inorder function will inorder traverse and store the elements in the vector

sort(v.begin(),v.end());//why we are sorting here is that,bcuz we want to create bst from sorted vector ..and inorder traversal of a bst is always sorted .
int n=v.size();
node* head=buildbalancedbst(v,0,n-1);//function to create bst from sorted vector


printinorder(head);

  


}