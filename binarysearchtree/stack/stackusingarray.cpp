#include<iostream>
#include<string>
using namespace std;
class Stack{
private:
    int top;
    int arr[5];
public:
    Stack()
    {

        top=-1;
        for(int i=0;i<4;i++){
            arr[i]=0;

    }}
    bool isFull()
    {

        if(top==4)
            return true;
        else
            return false;

    }
    bool isEmpty()
    {
        if(top==-1)
        return true;
        else
            return false;

    }
    void push(int val)
    {

        if(isFull())
            cout<<"stack overflow"<<endl;
        else
        {
            top++;
            arr[top]=val;

        }
    }
    int pop()
    {
        if(isEmpty())
        {
            cout<<"stack underflow"<<endl;
            return 0;

        }
        else
        {
            int popvalue=arr[top];
            arr[top]=0;
            top--;
            return popvalue;
        }
    }
    int count()
    {
        return (top+1);
    }
    int peek(int pos)
    {
        if(isEmpty())
        {
            cout<<"stack underflow"<<endl;
            return 0;

        }
        else
            return arr[pos];
    }
    void change(int pos,int val)
    {

        arr[pos]=val;
        cout<<"value changed at location"<<pos<<endl;
    }
    void display()
    {

        cout<<"All the values in the stack are :"<<endl;
        for(int i=3;i>=0;i--)
        {
            cout<<arr[i]<<endl;

        }
    }};
    int main()
    {
        Stack s1;
        int option,position,value;
        do{
            cout<<"What operation do you want to perform?Select option number.Enter 0 to exit!"<<endl;
            cout<<"1. Push()"<<endl;
            cout<<"2. Pop()"<<endl;
            cout<<"3. isEmpty()"<<endl;
            cout<<"4. isFull()"<<endl;
            cout<<"5. peek()"<<endl;
            cout<<"6. count()"<<endl;
            cout<<"7. change()"<<endl;
            cout<<"8. display()"<<endl;
            cout<<"9. Clear Screen"<<endl;
            cin>>option;
            switch(option)
            {
            case 1:
                cout<<"Enter an item to push in the stack"<<endl;
                cin>>value;
                s1.push(value);
                break;


            case 2:
                cout<<"Popped operation,Popped value:"<<s1.pop()<<endl;
                break;
            case 3:
                if(s1.isEmpty())
                    cout<<"Stack is empty"<<endl;
                else
                    cout<<"Stack is not empty"<<endl;
                    break;
            case 4:
                if(s1.isFull())
                    cout<<"Stack is Full"<<endl;

                else
                    cout<<"Stack is not Full"<<endl;
                    break;
            case 5:
                cout<<"Enter the position that you want to peek"<<endl;
                cin>>position;
                cout<<"The value at peeked position is :"<<s1.peek(position)<<endl;
                break;

            case 6:
                cout<<"The no.of elements in the stack are :"<<s1.count()<<endl;
                break;

            case 7:
                cout<<"Enter the position and value that you want to change respectively"<<endl;
                cin>>position>>value;
                s1.change(position,value);
                break;

            case 8:
                cout<<"Elements in the stack are:"<<endl;
                s1.display();
                break;

            case 9:
                system("cls");
                break;
            default:
                cout<<"Enter Proper option Number:"<<endl;


        }}
        while(option!=0);

    }



