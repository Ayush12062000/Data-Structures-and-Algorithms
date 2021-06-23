#include <bits/stdc++.h>

using namespace std;

#define input(n) int n; cin>>n;

int fibo(int n)
{
    int dp[n+1];
    dp[0]=0;
    dp[1]=1;

    for(int i=2;i<=n;i++)
        dp[i] = dp[i-1]+dp[i-2];
    
    return dp[n];
}

int main()
{
    input(n);
    cout<<fibo(n)<<endl;
    return 0;
}