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
void printsubtreenodes(node* root,int k)
{
    if(root==NULL||k<0)
    return;
    if(k==0)
    {
        cout<<root->data<<" ";
        return;
    }
    printsubtreenodes(root->left,k-1);
    printsubtreenodes(root->right,k-1);
}
//case 2
int printnodesatk(node*root,node*target,int k)
{
    if(root==NULL)
    return -1;
    if(root==target){
    printsubtreenodes(root,k);
    return 0;}
    int dl=printnodesatk(root->left,target,k);
    if(dl!=-1)
    {
        if(dl+1==k)
        cout<<root->data<<" ";
        else
        printsubtreenodes(root->right,k-dl-2);
    }
    return 1+dl;
    int dr=printnodesatk(root->right,target,k);
    if(dr!=-1)
    {
        if(dr+1==k)
        {
            cout<<root->data<<" ";

        }
        else
        printsubtreenodes(root->left,k-dr-2);

    
    return 1+dr;}
    return -1;


}

int main()

{
    node* root=New_Node(1);
    root->left=New_Node(2);
    root->right=New_Node(3);
    root->left->left=New_Node(4);
    root->left->right=New_Node(5);
printnodesatk(root,root->left,1);

    return 0;


}