#include<iostream>
#define input(n) int n; cin>>n;
#define scan(arr,n) for(int i=0;i<n;i++) cin>>arr[i];
using namespace std;

void bubblesort(int *arr,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
            if(arr[j]>arr[j+1])
                swap(arr[j],arr[j+1]);
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
    bubblesort(arr,n);
    cout<<"Sorted array:\n";
    for(int i=0;i<n;i++)
            cout<<arr[i]<<" ";
    return 0;
}



/*
10
0 1 5 8 9 3 11 5 7 40
Unsorted array(input array):
0 1 5 8 9 3 11 5 7 40
Sorted array:
0 1 3 5 5 7 8 9 11 40
*/
