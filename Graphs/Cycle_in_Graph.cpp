#include<bits/stdc++.h>
#define input(n) int n; cin>>n
using namespace std;

void dfs(vector<int> g[],int i,int v,int visited[])
{

}


int main()
{
    cout<<"Enter vertices: ";
    input(v);
    cout<<"Enter Edges: ";
    input(e);
    vector<int> g[v];
    int flag = 0;
    int visited[v];
    for(int i=0;i<v;i++)
        visited[i] = 0;

    for(int i=0;i<e;i++)
    {
        input(s);
        input(d);
        g[s].push_back(d);
        g[d].push_back(s);
    }

    for(int i=0;i<v;i++)
    {
        if(!visited[i])
            dfs(g,i,v,visited);
        if(flag==1)
            break;
    }
    if(flag)
        cout<<"Cycle exist\n";
    else
        cout<<"No Cycle exist\n";
    return 0;
}


/*
Test case #1:
5
0 1 1 0 0
0 0 0 1 1
0 1 0 1 0
0 0 0 0 1
0 0 0 0 0
No Cycle Exists
*/
