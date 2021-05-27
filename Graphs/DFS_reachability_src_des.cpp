// ERROR IN ANSWER
// NEEDS CORRECTION IN APPROACH

#include<iostream>
#include<vector>
#define input(n) int n; cin>>n;
#define inputs(n,m) int n,m; cin>>n>>m ;

enum colors{white,brown,black}; // white=0,brown=1,black=2

using namespace std;

void print(vector<int> graph[],int n)
{
    for(int i=0;i<n;i++)
    {
        int a = graph[i].size();
        for(int j=0;j<a;j++)
            cout<<graph[i][j]<<" ";
        cout<<endl;
    }
}


void dfs_process(vector<int> graph[],int s,int d,int *visited)
{
    visited[s]=brown;
    int n = graph[s].size();

    for(int i=0;i<n;i++)
    {
        int x = graph[s][i];
        if(!visited[x])
        {
            cout<<x<<" ";
            if(x!=d)
                dfs_process(graph,x,d,visited);
            else 
                break;
        }
    }
    visited[s] = black;
}


void dfs(vector<int> graph[],int v,int s,int d)

{
    int visited[v];
    for(int i=0;i<v;i++)
        visited[i] = white;
    
    cout<<"Path from src to des: "<<s<<" ";
    for(int i=s;i<=d;i++)
    {
        if(!visited[i])
        {
            dfs_process(graph,i,d,visited);
        }
    }
}

int main()
{
    cout<<"Enter number of vertices: ";
    input(v);
    cout<<"Enter number of edges: ";
    input(e);
    vector<int> graph[v];
    cout<<"Enter src and des:\n";
    for(int i=0;i<e;i++)
    {
        inputs(src,des);
        graph[src].push_back(des);
        graph[des].push_back(src);
    }
    //print(graph,v);
    cout<<"Enter Source: ";
    input(s);
    cout<<"Enter Destination: ";
    input(d);
    dfs(graph,v,s,d);
    return 0;
}