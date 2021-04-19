#include<bits/stdc++.h>
#define input(n) int n; cin>>n
using namespace std;

bool has_cycle(int src,vector<vector<int>> &g,vector<int> &visited,vector<int> &recursive_stack)
{
    visited[src] = 1;
    recursive_stack[src] = 1;
    for(int i=0;i<g[src].size();i++)
    {
        if(g[src][i])
        {
            if(!visited[i] && has_cycle(i,g,visited, recursive_stack))
                return true;
            else if(recursive_stack[i] == 1)
                return true;
        }
    }
    recursive_stack[src] = 0;
    return false;
}

int main()
{
    input(v);
    vector<vector<int>> g(v,vector<int>(v,0));
    for(int i=0;i<v;i++)
        for(int j=0;j<v;j++)
            cin>>g[i][j];
    
    vector<int> recursive_stack(v,0),visited(v,0);
    
    for(int i=0;i<v;i++)
    {
        if(!visited[i] && has_cycle(i,g,visited,recursive_stack))
        {
            cout<<"Yes Cycle Exists\n";
            return 0;
        }
    }
    cout<<"No Cycle Exists\n";
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