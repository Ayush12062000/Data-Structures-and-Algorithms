#include<bits/stdc++.h>
#define input(n) int n; cin>>n
using namespace std;

void path_check(vector<int> g[],int *visited,int src,int des)
{
    visited[src]=1;
    if(src == des)
        return;
    for(int i=0;i<g[src].size();i++)
    {
        if(!visited[g[src][i]])
            path_check(g,visited,g[src][i],des);
    }
}

int main()
{
    cout<<"Enter number of vertices: ";
    input(v);
    cout<<"Enter number of edges: ";
    input(e);
    vector<int> g[v];
    int visited[v];
    for(int i=0;i<v;i++)
        visited[i] = 0;

    cout<<"Directed Graph: ";
    for(int i=0;i<e;i++)
    {
        input(s);
        input(d);
        g[s].push_back(d);
    }

    cout<<"Enter 2 vertices to know if path exist or not: ";
    input(src);
    input(des);
    path_check(g,visited,src,des);

    if(visited[des] == 1)
        cout<<"Yes Path Exists\n";
    else
        cout<<"No Such Path Exists\n";
    return 0;
}


/*
Test case #1:
Enter number of vertices: 6
Enter number of edges: 10
Directed Graph: 0 1
1 3
3 5
4 5
4 2
2 0
1 2
2 3
4 1
3 4
Enter 2 vertices to know if path exist or not: 1
5
Yes Path Exists

Test case #2:
Enter number of vertices: 6
Enter number of edges: 10
Directed Graph: 0 1
1 3
3 5
4 5
4 2
2 0
1 2
2 3
4 1
3 4
Enter 2 vertices to know if path exist or not: 5
0
No Such Path Exists
*/