#include<iostream>
#define input(n) int n; cin>> n
#define scan(arr, n)  for(int i=0;i<n;i++) cin>>arr[i];
#define inputs(m,n) int m,n; cin>>m>>n
#define print(any)  for(auto i:any)  cout << i<<" ";

using namespace std;

void heapify(int *arr,int n,int i)
{
    int largest = i;  //root
    int l = 2 * i + 1;  //left child
    int r = 2 * i + 2;  //right child
    
    if (l < n && arr[l] > arr[largest])
        largest = l;
    
    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void build_heap(int *arr,int n)
{
    for(int i=n/2;i>=0;i--)
        heapify(arr,n,i);
}

int main()
{
    input(n);
    int arr[n];
    scan(arr,n);
    build_heap(arr,n);
    cout<<"Max Heap:\n";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    return 0;
}