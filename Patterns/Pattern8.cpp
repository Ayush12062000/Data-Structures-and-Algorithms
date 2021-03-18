#include<iostream>
#define input(n) int n; cin>>n;
using namespace std;
int main()
{
    int i,j,k;
    input(n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i;j++)
            cout<<n-j-i;
        cout<<"\n";
    }
    return 0;
}


/*
5
54321
4321
321
21
1
*/
