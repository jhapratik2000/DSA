#include<bits/stdc++.h>
using namespace std;
class Queue
{
    public:
    int front,rear,size;
    unsigned capacity;
    int *array;


    Queue* createqueue(unsigned capacity)
{
    Queue* queue=new Queue();
    capacity=capacity;
    front=size=0;
    rear=capacity-1;
array=new int[capacity];
    return queue;



}
int isFull(Queue* queue)
{
    return (size==capacity);

}
int isEmpty(Queue* queue)
{
    return (size==0);

}
void enqueue(Queue* queue,int item)
{
    if(isFull(queue))
    return;
rear=(rear+1)%(capacity);
    array[rear]=item;
    size=size+1;
    cout<<item<<" enqueued to queue\n";
}
int dequeue(Queue* queue)
{
    if(isEmpty(queue))
    return INT_MIN;
    int item=array[front];
    front=(front+1)%capacity;
    size=size-1;
    return item;

}
int Front(Queue* queue)
{
    if(isEmpty(queue))
    return INT_MIN;
    return array[front];

}
int Rear(Queue* queue)
{
    if(isEmpty(queue))
    return INT_MIN;
    return array[rear];


}
};



int main()
{
Queue queue;
queue.createqueue(1000);
queue.enqueue(&queue,10);
queue.enqueue(&queue,20);
queue.enqueue(&queue,30);
queue.enqueue(&queue,40);
cout<<queue.dequeue(&queue)<<endl;

cout<<"FRONT ITEM IS "<<queue.Front(&queue)<<endl;
cout<<"REAR ITEM IS "<<queue.Rear(&queue)<<endl;


}