#include<iostream>
#define input(n) int n; cin>>n;
#define scan(arr,n) for(int i=0;i<n;i++) cin>>arr[i];
using namespace std;

void selectionsort(int *arr,int n)
{
    int min_ele,pos;
    for(int i=0;i<n-1 ;i++)
    {
        min_ele = arr[i];
        pos = i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<min_ele){
                min_ele = arr[j];
                pos = j;
            }
        }
        if(i!= pos)
            swap(arr[i],arr[pos]);
    }
}


int main()
{
    input(n);   //number of elements
    int arr[n];
    scan(arr,n);  // input elements
    cout<<"Unsorted array(input array):\n";
    for(int i=0;i<n;i++)
            cout<<arr[i]<<" ";
    cout<<"\n";
    selectionsort(arr,n);
    cout<<"Sorted array:\n";
    for(int i=0;i<n;i++)
            cout<<arr[i]<<" ";
    return 0;
}


/*
10
5 1 2 0 -7 8 -12 99 3 -1
Unsorted array(input array):
5 1 2 0 -7 8 -12 99 3 -1
Sorted array:
-12 -7 -1 0 1 2 3 5 8 99
*/
