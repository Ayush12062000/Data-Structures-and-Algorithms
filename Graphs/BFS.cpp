#include<iostream>
#include<vector>
#include<queue>
#define input(n) int n; cin>>n;
#define inputs(s,d) int s,d; cin>>s>>d;

using namespace std;

void breadth_first_search(vector<int> graph[],int v,int src)
{
    bool visited[v];
    int parent[v];
    for(int i=0;i<v;i++)
    {
        visited[i] = false;
        parent[i] = -1;
    }
    queue<int> q;
    cout<<"BFS:\n"<<src<<" ";
    q.push(src);
    visited[src]=true;
    while(!q.empty())
    {
        int temp = q.front();
        q.pop();
        int n = graph[temp].size();
        for(int i=0;i<n;i++)
        {
            int d = graph[temp][i];
            if(!visited[d])
            {
                cout<<d<<" ";
                visited[d] = true;
                q.push(d);
                parent[d] = temp;
            }
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
    breadth_first_search(graph,v,src);
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
select initial vertex: 0
BFS:
0 1 2 3 4 5 6
Parent vertex:
-1 0 0 0 2 4 4

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
select initial vertex: 5
BFS:
5 4 2 3 6 0 1
Parent vertex:
2 2 4 4 5 -1 4
*/
