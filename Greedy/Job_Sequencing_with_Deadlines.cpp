#include<bits/stdc++.h>
#define input(n) int n; cin>>n

using namespace std;

bool compare(pair<int,int> a,pair<int,int> b)
{
    return a.first>b.first;
}

int main()
{
    input(n);
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++)
    {
        input(profit);
        input(deadline);
        v.push_back(make_pair(profit,deadline));
    }
    sort(v.begin(),v.end(),compare);
    int maxsize=0;
    for(int i=0;i<n;i++)
    {
        if(v[i].second > maxsize)
            maxsize = v[i].second;
    }
    int fill[maxsize];
    for(int i=0;i<maxsize;i++)
        fill[i] = -1;

    int count=0,maxprofit=0;

    for(int i=0;i<n;i++)
    {
        int j = v[i].second-1;
        while(j>=0 && fill[j] != -1 )
            j--;

        if(j>=0 && fill[j] == -1)
        {
            fill[j] = i;
            count++;
            maxprofit += v[i].first;
        }
    }

    cout<<count<<" jobs aggregate "<<maxprofit<<" profit"<<endl;

    return 0;
}


/*

5
20 2
15 2
10 1
5 3
1 3
3 jobs aggregate 40 profit
*/