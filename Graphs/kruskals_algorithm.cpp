#include <iostream>
#include <vector>
#include <algorithm>

#define input(n) int n; cin>>n;

using namespace std;
typedef vector<pair<int, pair<int,int> > > viii;

int find(int u,int *parent)
{
    if(parent[u]<0) return u;
    return find(parent[u],parent);
}

void unionByWeight(int u,int v, int *parent)
{
    int pu = find(u,parent),pv = find(v,parent);
    if(pu!=pv)
    {
        if(parent[pu]<parent[pv])
        {
            parent[pu] += parent[pv];
            parent[pv] = pu;
        }
        else{
            parent[pv] += parent[pu];
            parent[pu] = pv;
        }
    }
}

viii kruskals(viii g,int v)
{
    viii res;
    int parent[v];
    for(int i=0;i<v;i++)
        parent[i] = -1;
    sort(g.begin(),g.end()); //sorting based on weights 
    int e = g.size();
    for(int i=0;i<e;i++)
    {
        int s = g[i].second.first;
        int d = g[i].second.second;
        if(find(s,parent) != find(d,parent))
        {
            res.push_back(g[i]);
            unionByWeight(s,d,parent);
        }
    }
    return res;
}

int main()
{
    input(v);
    input(e);
    viii graph,res;
    for(int i=0;i<e;i++)
    {
        input(s);
        input(d);
        input(w);
        graph.push_back(make_pair(w,make_pair(s,d)));
    }
    res = kruskals(graph,v);
    int sum = 0;
    for(int i=0;i<res.size();i++)
    {
        int w = res[i].first;
        cout<<res[i].second.first<<" "<<res[i].second.second<<"\n";
        sum += w;
    }
    cout<<"Sum of MST="<<sum<<"\n";
    return 0;
}


/*
Output:
6
9
0 1 1
1 2 4
2 3 8
3 4 9
4 5 6
5 0 3
1 5 2
1 4 5
2 4 7
0 1
1 5
1 2
1 4
2 3
Sum of MST=20
*/