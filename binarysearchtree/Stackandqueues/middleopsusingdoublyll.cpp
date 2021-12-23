#include<bits/stdc++.h>
using namespace std;
class Dll
{
    public:
    int data;
    Dll* prev;
    Dll* next;

};

class mystack{
    public:
    Dll* head;
    int count;
    Dll* mid;
    mystack()
    {
count=0;

    }



}
;

void push(mystack* ms,int data)
{
    Dll* node=new Dll();
    node->prev=NULL;
    node->next=ms->head;
    ms->count+=1;
    if(ms->count==1)
    ms->mid=node;
    else
    {
    if(!(ms->count&1))
    ms->mid=ms->mid->prev;
    ms->head->prev=node;
    ms->head=node;
    
    }

}
int pop(mystack* ms)
{
    if(ms->count==0){
    cout<<"Stack is empty\n";
    return-1;
    }
    Dll* head=ms->head;
    int item=head->data;
    ms->head=head->next;
    if(ms->head!=NULL)
    ms->head->prev=NULL;
    ms->count--;
    if((ms->count)&1)
    ms->mid=ms->mid->next;
    free(head);
    return item;


}
int findmiddle(mystack* ms)
{
    if(ms->count==0){
    cout<<"Stack is empty\n";
    return -1;
    }
    return ms->mid->data;


}
int deletemiddle(mystack* ms)
{
    if(ms->count==0)
    {
        cout<<"Stack is empty\n";
        return -1;

    }
    Dll *mid=ms->mid;
    int item=mid->data;
    ms->count--;
    if(ms->count==1)
    {
        ms->head=ms->head->next;
        ms->mid=ms->head;

    }
    else if(ms->count>0)
    {
        ms->mid->prev->next=ms->mid->next;
        ms->mid->next->prev=ms->mid->prev;
        if(ms->count&1)
        ms->mid=ms->mid->next;
        else
        ms->mid=ms->mid->prev;


    }
    free(mid);
    return item;


}
int main()
{
    mystack* ms=new mystack();
       push(ms, 11);
    push(ms, 22);
    push(ms, 33);
    push(ms, 44);
    push(ms, 55);
    push(ms, 66);
    push(ms, 77);
 
    cout << "Item popped is " << pop(ms) << endl;
    cout << "Item popped is " << pop(ms) << endl;
    cout << "Item popped is " << pop(ms) << endl;
    cout << "Middle Element is " << findmiddle(ms) << endl;
    cout << "Deleted Middle Element is "<<deletemiddle(ms)<<endl;
    cout << "Middle Element is " << findmiddle(ms) << endl;
    return 0;
}
