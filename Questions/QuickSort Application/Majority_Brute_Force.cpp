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

void Majority(int arr[],int n)
{
    int maxfreq = 0 , curfreq = 0 , index = -1;
    for(int i=0;i<n;i++)
    {
        curfreq = 0;
        for(int j=0;j<n;j++)
        {
            if(arr[i] == arr[j])
                curfreq++;
        }
        if(curfreq > maxfreq)
        {
            maxfreq = curfreq;
            index = i;
        }
    }
    if(maxfreq >=  (n/2))
        cout<<"Majority element = "<<arr[index]<<"\n";
    else
        cout<<"No Majority element\n";
}

int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input(n);
    int arr[n];
    scan(arr,n);
    Majority(arr,n);

	return 0;
}


/*

7
2 2 1 1 1 2 1
Majority element = 1
*/
