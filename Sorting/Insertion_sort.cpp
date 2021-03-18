#include<iostream>
#define input(n) int n; cin>>n;
#define scan(arr,n) for(int i=0;i<n;i++) cin>>arr[i];
using namespace std;

void insertionsort(int *arr,int n)
{
    for(int i=0;i<n;i++)
    {
        int j=i-1;
        int temp = arr[i];
        while(j>=0 && arr[j]>temp)
        {
            arr[j+1] =arr[j];
            j--;
        }
        arr[j+1] = temp;
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
    insertionsort(arr,n);
    cout<<"Sorted array:\n";
    for(int i=0;i<n;i++)
            cout<<arr[i]<<" ";
    return 0;
}


/*
10
9 4 0 1 3 -78 -5 3 89 12
Unsorted array(input array):
9 4 0 1 3 -78 -5 3 89 12
Sorted array:
-78 -5 0 1 3 3 4 9 12 89
*/
