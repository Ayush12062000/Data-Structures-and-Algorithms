#include<iostream>
#define input(n) int n; cin>>n;
using namespace std;
int main()
{
    int i,j;
    input(n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<i+1;j++)
            cout<<j+1;
        cout<<"\n";
    }
    return 0;
}


/*
5
1
12
123
1234
12345

*/
