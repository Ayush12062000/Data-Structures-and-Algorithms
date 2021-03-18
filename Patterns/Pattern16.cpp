#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define input(n) long long int n; cin>> n

int main()
{
    input(n);
    int i,j,k,a=n;

    for(i=1;i<=n;i++)
    {
        for(k=i;k<n;k++)
            cout<<" ";
        for(j=1;j<=i;j++)
            cout<<j<<"";
        for(j=i-1;j>0;j--)
            cout<<j<<"";

        cout<<"\n";

    }

    int b=n-2;
    for(i=1;i<=n;i++)
    {
        for(k=1;k<=i;k++)
            cout<<" ";
        for(j=1;j<a;j++){
            cout<<j<<"";
        }
        a--;

        for(k=b;k>0;k--){
            cout<<k<<"";
        }
        b--;
        cout<<"\n";
    }

    return 0;
}


/*
Enter a number:
5
    1
   121
  12321
 1234321
123454321
 1234321
  12321
   121
    1

*/
