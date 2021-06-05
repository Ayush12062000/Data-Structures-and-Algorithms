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
    double value = (1.0*key/arr[index]);
    arr[index] = key;
    int block_size = ceil(sqrt(n));
    block[index/block_size] *= value; 
    cout<<"\nBlock: ";
    for(int i=0;i<block_size;i++)
        cout<<block[i]<<" ";
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

8
5 1 4 6 2 9 4 3
Array: 5 1 4 6 2 9 4 3 
Block: 20 108 12
3
1 3 10

Block: 20 180 12
2 0 7
Product = 43200
2 2 6
Product = 2880

*/