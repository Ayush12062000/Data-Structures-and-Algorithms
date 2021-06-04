#include<bits/stdc++.h>
#define input(n) int n; cin>>n
using namespace std;



int main()
{
    cout<<"Enter vertices: ";
    input(v);
    cout<<"Enter Edges: ";
    input(e);
    vector<int> g[v];
    int visited[v];
    for(int i=0;i<v;i++)
        visited[i] = 0;

    // undirected graph
    for(int i=0;i<e;i++)
    {
        input(s);
        input(d);
        g[s].push_back(d);
        g[d].push_back(s);
    }

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
