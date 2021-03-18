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
            cout<<j+1;
        cout<<"\n";
    }
    return 0;
}

/*
5
12345
1234
123
12
1
*/
