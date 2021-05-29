#include <iostream>
#include <vector>
#include <algorithm>

#define input(n) int n; cin>>n;

using namespace std;
typedef vector<pair<int, pair<int,int> > > viii;

viii kruskals(viii g,int v)
{
    int parent[v];
    for(int i=0;i<v;i++)
        parent[i] = -1;
    
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

    return 0;
}
