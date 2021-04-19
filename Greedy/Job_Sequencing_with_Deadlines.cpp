#include<bits/stdc++.h>
#define input(n) int n; cin>>n

using namespace std;

bool comparison(int )

int main()
{
    cout<<"input number of jobs: ";
    input(n);
    int arr[2][n];
    cout<<"enter profit deadline:\n";
    for(int i=0;i<n;i++)
    {
        cin>>arr[0][i]>>arr[1][i];
    }
    sort(arr,arr+n,comparison);
    cout<<"Entered Profit(0) and deadline(1):\n";
    for(int i=0;i<n;i++)
        cout<<arr[0][i]<<" "<<arr[1][i]<<endl;

    

    return 0;
}