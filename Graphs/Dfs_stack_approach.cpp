/* 
    Path Exist between SRc or Des using DFS stack approach.
*/

#include <iostream>
#include <vector>
#include <stack>

#define input(n) int n; cin>>n;
#define inputs(n,m) int n,m; cin>>n>>m;

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

void depth_first_search(vector<int> graph[],int v,int src,int des)
{
    bool visited[v];
    vector<int> processed_vertex;
    for(int i=0;i<v;i++)
        visited[i] = false;
    stack<int> st;
    st.push(src);
    visited[src] = true;
    processed_vertex.push_back(src);
    while(!st.empty())
    {
        int temp=st.top();
        st.pop();
        int n = graph[temp].size();
        for(int i=0;i<n;i++)
        {
            int d = graph[temp][i];
            if(!visited[d])
            {
                visited[d] = true;
                st.push(d);
                processed_vertex.push_back(d);
            }
        }
    }
    cout<<"\nDFS:\n";
    for(int i=0;i<v;i++)
        cout<<processed_vertex[i]<<" ";
    cout<<"\n";

    if(visited[des])
        cout<<"Path exist\n";
    else
        cout<<"Path Doesn't exist\n";

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
        //graph[d].push_back(s);
    }
    cout<<"select initial vertex: ";
    input(src);
    cout<<"select destination vertex: ";
    input(des);
    depth_first_search(graph,v,src,des);
    print(graph,v);
    return 0;
}