#include<bits/stdc++.h>
#define input(n) int n; cin>>n
using namespace std;

bool is_bipartite(int src,int v,vector<vector<int>> &g,vector<int> &color)
{
    queue<int> q;
    q.push(src);
    color[src]=0;
    while(!q.empty())
    {
        src = q.front();
        q.pop();
        for(int i=0;i<v;i++)
        {
            if(g[src][i] == 1)
            {
                if(color[i] == -1)
                {
                    color[i] = color[src] ^ 1;
                    q.push(i);
                }
                else if(color[i] == color[src] || i == src)
                {
                    return false;
                }
            }
        }
    }
    return true;
}

int main()
{
    input(v);
    vector<vector<int>> g(v,vector<int>(v,0));
    vector<int> color(v,-1);
    for(int i=0;i<v;i++)
        for(int j=0;j<v;j++)
            cin>>g[i][j];

    for(int i=0;i<v;i++)
    {
        if(color[i] == -1)
        {
            if(!is_bipartite(i,v,g,color))
            {
                cout<<"Not Bipartite\n";
                return 0;
            }
        }
    }
    cout<<"Yes Bipartite\n";
}


/*
Test case #1:
5
0 1 1 0 0
1 0 1 1 1
1 1 0 1 0
0 1 1 0 1
0 1 0 1 0
Not Bipartite
*/