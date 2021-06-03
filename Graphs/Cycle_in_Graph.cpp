#include<bits/stdc++.h>
#define input(n) int n; cin>>n
using namespace std;

void dfs(vector<int> g[],int u,int &flag,int visited[])
{
    if(visited[u] == -1)
    {
        flag = 1;
        return ;
    }
    visited[u]=-1;
    int n = g[u].size();
    for(int i=0;i<n;i++)
    {
        if(!visited[g[u][i]])
            dfs(g,g[u][i],flag,visited);
    }
    visited[u]=1;
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
            dfs(g,i,flag,visited);
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
Enter vertices: 5
Enter Edges: 5
0 1
1 2
2 3
3 2
4 1
No Cycle exist

Test case #2:

*/
