#include<bits/stdc++.h>
using namespace std;
#define inf (1<<28)
#define sz 512
int par[sz];
struct edge
{
    int u,v,w;
    edge(int _,int __,int ___)
    {
        u=_;
        v=__;
        w=___;
    }
};

vector<edge>e;

int get_par(int r)
{
    return (par[r]==r?r:par[r]=get_par(par[r]));
}

int MST(int N)
{
    for(int i=0; i<sz; i++)
        par[i]=i;
    int c=0;
    for(int i=0; i<e.size(); i++)
    {
        int u=get_par(e[i].u);
        int v=get_par(e[i].v);
        if(u!=v)
        {
            par[u]=v;
        }
        else
        {
            c++;
        }
    }
    return c;
}
int main()
{
    int N,E,w;
    char u,v;
    while(cin>>N>>E)
    {
        for(int i=0; i<E; i++)
        {
            cin>>u>>v;
            e.push_back(edge((int)u,(int)v,1));
        }
        cout<<MST(N)+1<<endl;
        e.clear();
    }
    return 0;
}