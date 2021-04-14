#include<iostream>
#include<vector>
#include<queue>
#define input(n) int n; cin>>n;
#define inputs(s,d) int s,d; cin>>s>>d;

enum colors{white,brown,black};

using namespace std;

void dfs_process(vector<int> graph[],int v,int src,int *parent,int *visited)
{
    visited[src] = brown;
    int n = graph[src].size();
    for(int i=0;i<n;i++)
    {
        int d = graph[src][i];
        if(!visited[d])
        {
            cout<<d<<" ";
            parent[d] = src;
            dfs_process(graph,v,d,parent,visited);
        }
    }
    visited[src] = black;
}

void depth_first_search(vector<int> graph[],int v,int src)
{
    int visited[v];
    int parent[v];
    for(int i=0;i<v;i++)
    {
        visited[i] = white;
        parent[i] = -1;
    }
    cout<<"DFS: "<<src<<" ";
    for(int i=src;i<v;i++)
    {    
        if(!visited[i])
            {
                dfs_process(graph,v,i,parent,visited);
            }
    }
    cout<<"\nParent vertex:\n";
    for(int i=0;i<v;i++)
        cout<<parent[i]<<" ";
    cout<<"\n";
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
        graph[d].push_back(s);
    }
    cout<<"select initial vertex: ";
    input(src);
    depth_first_search(graph,v,src);
    return 0;
}



/*
test case #1:
enter number of vertices: 7
enter number of edges: 9
enter source and destination of edges:
0 1
0 2
0 3
1 2
2 3
2 4
3 4
4 5
4 6
select initial vertex: 4
DFS: 4 2 0 1 3 5 6 
Parent vertex:
2 0 4 0 -1 4 4

test case #2:
enter number of vertices: 7
enter number of edges: 9
enter source and destination of edges:
0 1
0 2
0 3
1 2
2 3
2 4
3 4
4 5
4 6
select initial vertex: 6
DFS: 6 4 2 0 1 3 5 
Parent vertex:
2 0 4 0 6 4 -1
*/