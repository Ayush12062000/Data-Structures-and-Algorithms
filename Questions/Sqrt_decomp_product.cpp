#include <iostream>
#include <cmath>
#include <vector>

#define input(n) int n; cin>>n;
#define scan(arr,n) for(int i=0;i<n;i++) cin>>arr[i];

using namespace std;

vector<int> sqrtdecomp(int *arr,int n)
{
    int block_size = ceil(sqrt(n));
    vector<int> block(block_size,1); // by default initialized to 0

    for(int i=0;i<n;i++)
    {
        block[i/block_size] *= arr[i]; 
    }
    return block;
}

void update(int *arr,vector<int> &block,int n, int index, int key)
{
    double value = (key/1.0* arr[index]);
    arr[index] = key;
    int block_size = ceil(sqrt(n));
    block[index/block_size] *= value; 
}

int calprod(int *arr,vector<int> &block,int n, int l, int r)
{
    int block_size = ceil(sqrt(n));
    int prod = 1;
    int start = l/block_size , end = r/block_size ;

    for(int i=start+1;i<end;i++)
        prod *= block[i] ;
    int i = l;
    while((i/block_size) == start)
    {
        prod *= arr[i++];
    }

    i = r;
    while((i/block_size) == end)
    {
        prod *= arr[i--];
    }
    return prod;
}

int main()
{
    input(n);
    int *arr = new int[n]; 
    scan(arr,n);
    cout<<"Array: ";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    vector<int> block = sqrtdecomp(arr,n);
    int block_size = ceil(sqrt(n));
    cout<<"\nBlock: ";
    for(int i=0;i<block_size;i++)
        cout<<block[i]<<" ";
    input(q);
    while(q--)
    {
        input(type);
        switch(type)
        {
            case 1: input(index);
                    input(key); 
                    update(arr,block,n,index,key);
                break;
            case 2: input(l);
                    input(r);
                    cout<<"Product = "<<calprod(arr,block,n,l,r)<<"\n";
                break;
        }
    }
    return 0;
}


/*
OutPut:

10 
9 10 3 1 8 7 2 6 4 3
Array: 9 10 3 1 8 7 2 6 4 3 Block: 23 23 7 0 
3
2 0 9
Sum = 53
1 2 10
2 0 9
Sum = 60
*/