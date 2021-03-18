#include<iostream>
#define input(n) int n; cin>>n;
#define scan(arr,n) for(int i=0;i<n;i++) cin>>arr[i];
using namespace std;

void merge_(int *arr,int l,int m,int r)
{
    int n1=m-l+1,n2=r-m;
    int L[n1],R[n2],i=0,j=0,k=l;
    while(i<n1)
            L[i++] = arr[k++];
    while(j<n2)
            R[j++] = arr[k++];
    i=0;
    j=0;
    k=l;
    while(i<n1 && j<n2)
    {
        if(L[i]<R[j])
                arr[k++] = L[i++];
        else
                arr[k++] = R[j++];
    }
    while(i<n1)
        arr[k++] = L[i++];
    while(j<n2)
        arr[k++] = R[j++];
}


void mergesort(int *arr,int l,int r)
{
    if(l<r)
    {
        int m = (l+r)/2;  // l + (r-l)/2
        mergesort(arr,l,m);
        mergesort(arr,m+1,r);
        merge_(arr,l,m,r);
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
    mergesort(arr,0,n-1);
    cout<<"Sorted array:\n";
    for(int i=0;i<n;i++)
            cout<<arr[i]<<" ";
    return 0;
}



/*

5
4 0 -9 8 7
Unsorted array(input array):
4 0 -9 8 7
Sorted array:
-9 0 4 7 8

*/
