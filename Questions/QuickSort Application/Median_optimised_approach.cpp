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
#define print(any)  for(auto i:any)  cout << i<<" "<<"\n";
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

double median(int arr[],int n)
{
    if(n&1)
        return find(arr,0,n-1,n/2);
    else
        return (find(arr,0,n-1,(n)/2)+find(arr,0,n-1,(n-1)/2)) /2.0 ;
}

int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input(n);
    int arr[n];
    scan(arr,n);

    double result = median(arr,n);
    cout<<result<<"\n";

	return 0;
}



/*
9
25 68 99 10 3 4 70 21 11
21
*/
