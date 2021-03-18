#include<iostream>
#define input(n) int n; cin>>n;
#define scan(arr,n) for(int i=0;i<n;i++) cin>>arr[i];
using namespace std;

int partition_(int *arr,int l,int r)
{
    int pivot = arr[r];
    int i=l-1,j=l;
    while(j<r)
    {
        if(arr[j] <= pivot)
        {
            i++;
            swap(arr[i],arr[j]);
        }
        j++;
    }
    swap(arr[i+1],arr[r]);
    return (i+1);
}

void quicksort(int *arr,int l,int r)
{
    if(l<r)
    {
        int p = partition_(arr,l,r);
        quicksort(arr,l,p-1);
        quicksort(arr,p+1,r);
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
    quicksort(arr,0,n-1);
    cout<<"Sorted array:\n";
    for(int i=0;i<n;i++)
            cout<<arr[i]<<" ";
    return 0;
}


/*
5
9 -1 2 6 8
Unsorted array(input array):
9 -1 2 6 8
Sorted array:
-1 2 6 8 9
*/

