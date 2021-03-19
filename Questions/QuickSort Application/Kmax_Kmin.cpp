#include <iostream>
#include<climits>
#include<ctime>
#include <bits/stdc++.h>
#include<stdlib.h> /* srand, rand */
#include<time.h>
typedef long long int ll;
#define deb(x) cout<<#x<<": "<<x<<"\n"
#define scan(arr, n)  for(int i=0;i<n;i++) cin>>arr[i];
#define input(n) ll n; cin>> n
#define inputs(m,n) ll m,n; cin>>m>>n
#define print(any)  for(auto i:any)  cout << i<<" "<<" ";
#define sz(x) (int)x.size();
using namespace std;

const int N = int(1e5+3);
#define modulo 1000000007

int partition(int *arr,int l, int r)
{
    int n = r-l+1;
    srand(time(0));
    int x = (rand()%n) +l;
    swap(arr[x],arr[r]);
    int pivot = arr[r],i=l-1,j=l;

    while(j<r)
    {
        if(arr[j]<pivot)
        {
            i++;
            swap(arr[i],arr[j]);
        }
        j++;
    }
    swap(arr[i+1],arr[r]);
    return i+1;
}


int find(int *arr,int l,int r,int k)
{
    if(l<=r)
    {
        int p = partition(arr,l,r);
        if(p == k)
            return arr[p];
        else if(p < k)
            return find(arr,p+1,r,k);
        else
            return find(arr,l,p-1,k);
    }
    return -1;
}

int kmax(int arr[],int n, int k)
{
    return find(arr,0,n-1,n-k);
    
}

int kmin(int arr[],int n, int k)
{
    return find(arr,0,n-1,k-1);
    
}

int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input(n);
    input(k);
    int arr[n];
    scan(arr,n);
    
    int result1 = kmax(arr,n,k);  //K-MAX element
    print(arr);
    cout<<"\n";
    cout<<"K-MAX = "<<result1<<"\n";
    
    int result2 = kmin(arr,n,k);  //K-MIN element
    cout<<"K-MIN = "<<result2<<"\n";
    
	return 0;
}


/*
10
5
55 87 12 0 4 6 99 26 48 36

0  4  6  12  26  36  48  55  87  99  
K-MAX = 36
K-MIN = 26

*/

