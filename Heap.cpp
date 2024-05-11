#include<iostream>
using namespace std;
int N;

void Heapify(int arr[],int i)
{
    int smallest=i;
    int l=2*i+1;
    int r=2*i+2;
    
    if(l<N && arr[l]<arr[smallest])
    {smallest=l;}
    
    if(r<N && arr[r]<arr[smallest])
    {smallest=r;}
    
    if(smallest!=i)
    {swap(arr[i],arr[smallest]);
    Heapify(arr,i);
    }
}

void BuildHeap(int arr[])
{
    for(int i=(N/2)-1;i>=0;i--)
    {
        Heapify(arr,i);
    }
}

void print(int arr[])
{
    cout<<"Heapify arr is=>";    
    for(int i=0;i<N;i++)
    {
        cout<<arr[i]<<" ";
    }
}

int main()
{
    int arr[]={2,4,1,6,9,10,3};
    N=sizeof(arr)/sizeof(arr[0]);
    
    BuildHeap(arr);
    print(arr);
    return 0;
}