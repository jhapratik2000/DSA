#include<bits/stdc++.h>
using namespace std;
      void swap(int *x, int *y)
{
int temp = *x;
*x = *y;
*y = temp;
}
void helper(vector<int>&arr,int i,int n)
{
    int largest=i;
    int l=(2*i)+1;
    int r=(2*i)+2;
    if(l<n&&arr[l]>arr[largest])
    largest=l;
    if(r<n&&arr[r]>arr[largest])
    largest=r;
    if(largest!=i)
    {
swap(arr[i],arr[largest]);




        helper(arr,largest,n);

    }
}
void heapify(vector<int>&arr,int n)
{
    int idx=(n/2)-1;
    for(int i=idx;i>=0;i--)
    helper(arr,idx,n);

}

void printify(vector<int>arr,int n)
{
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
    cout<<endl;


}
int main() {

    int n;
    cin>>n;

vector<int>arr(n);
for(int i=0;i<n;i++)
{
    cin>>arr[i];
}




heapify(arr,11);
printify(arr,11);


}

