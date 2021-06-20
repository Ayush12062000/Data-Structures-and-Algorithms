#include <bits/stdc++.h>

#define input(n) int n; cin>>n;
using namespace std;

int main()
{
    input(n);
    vector<pair<int,int> > v;
    for(int i=0;i<n;i++)
    {
        input(s);
        input(e);
        v.push_back(make_pair(e,s));
    }
    sort(v.begin(),v.end());
    int count=0,currentend=-1;
    for(int i=0;i<n;i++)
    {
        if(v[i].second > currentend)
        {
            count++;
            currentend = v[i].first;
        }
    }

    cout<<count<<endl;
    return 0;
}


/*
Output:

7
7 9
8 9
5 9
1 2
0 6
3 4
5 7
4
*/