#include<bits/stdc++.h>
#define input(n) int n; cin>>n
using namespace std;

void path_check(vector<vector<int>> &g,vector<int> &visited,int src,int des)
{
    visited[src]=1;
    if(src == des)
        return;
    for(int i=0;i<g[src].size();i++)
    {
        if(g[src][i]==1 && visited[i]==0)
            path_check(g,visited,i,des);
    }
}

int main()
{
    //cout<<"Enter number of vertices: ";
    input(v);
    vector<vector<int>> g(v,vector<int>(v,0));
    vector<int> visited(v,0);
    //cout<<"Enter the matrix:\n";
    for(int i=0;i<v;i++)
        for(int j=0;j<v;j++)
            cin>>g[i][j];

    int src,des;
    //cout<<"Enter 2 vertices to know if path exist or not: ";
    cin>>src>>des;
    path_check(g,visited,src-1,des-1);

    if(visited[des-1])
    {
        cout<<"Yes Path Exists\n";
    }
    else
        cout<<"No Such Path Exists\n";
    return 0;
}


/*
Test case #1:
5
0 1 1 0 0
1 0 1 1 1
1 1 0 1 0
0 1 1 0 1
0 1 0 1 0
1 5
Yes Path Exists

Test case #2:
5
0 1 1 0 0
1 0 1 1 1
1 1 0 1 0
0 1 1 0 1
0 1 0 1 0
2 4
Yes Path Exists*/