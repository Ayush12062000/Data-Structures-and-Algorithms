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

double median(int arr[] ,int n)
{
    if(n&1)
        return arr[n/2];
    else
        return (arr[n/2] + arr[(n-1)/2]) / 2.0;
}

int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input(n);
    int arr[n];
    scan(arr,n);
    sort(arr,arr+n);

    double result = median(arr , n);
    cout << result << "\n";
	return 0;
}
