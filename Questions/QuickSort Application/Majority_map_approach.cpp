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


int majority(int arr[],int n)
{
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++)
        mp[arr[i]]++;

    int max=0,result=0;
    for(auto x:mp)
    {
        if(x.second > max)
        {
            max = x.second;
            result = x.first;
        }
    }
    if(max > (n/2))
        return result;
    else
        return 0;
}

int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input(n);
    int arr[n];
    scan(arr,n);

    int result = majority(arr,n);
    if(result)
        cout<<"Majority = "<<result<<"\n";
    else
        cout<<"No Majority\n";
	return 0;
}


/*
8
3 2 3 4 3 6 3 3
Majority = 3
*/
