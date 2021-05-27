#include <iostream>
#include <vector>
#include <stack>

#define input(n) int n; cin>>n;
#define inputs(n,m) int n,m; cin>>n>>m;
using namespace std;

void topo_process(vector<int> graph[],bool visited[],stack<int> &st,int i)
{
    visited[i] = true;
    int n = graph[i].size();
    for(int j=0;j<n;j++)
    {
        if(!visited[graph[i][j]])
            topo_process(graph,visited,st,graph[i][j]);
    }
    st.push(i);
}

void topological_sort(vector<int> graph[],int v)
{
    bool visited[v];
    for(int i=0;i<v;i++)
        visited[i] = false;
    stack<int> st;
    for(int i=0;i<v;i++)
    {
        if(!visited[i])
            topo_process(graph,visited,st,i);
    }
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
}

int main()
{
    cout<<"enter number of vertices: ";
    input(v);
    cout<<"enter number of edges: ";
    input(e);
    vector<int> graph[v];
    cout<<"enter source and destination of edges:\n";
    for(int i=0;i<e;i++)
    {
        inputs(s,d);
        graph[s].push_back(d);
    }
    topological_sort(graph,v);
    return 0;
}


/*
enter number of vertices: 
6
enter number of edges: 
6
enter source and destination of edges:
0 1
0 2
0 3
2 3
2 5
4 5
4 0 2 5 3 1

*/