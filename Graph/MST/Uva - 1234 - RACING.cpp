#include<bits/stdc++.h>
#define SZ 10010
using namespace std;
struct edge
{
    int u,v,w;
    bool operator < (const edge& p) const
    {
        return w>p.w;
    }
};

vector<edge>e;
int par[SZ];

int get_par(int r)
{
    return (par[r]==r?r:par[r]=get_par(par[r]));
}

int MST(int N)
{
    sort(e.begin(),e.end());
    for(int i=0; i<=N; i++)
        par[i]=i;
    int c=0,s=0;
    for(int i=0; i<e.size(); i++)
    {
        int u=get_par(e[i].u);
        int v=get_par(e[i].v);
        if(u!=v)
        {
            par[u]=v;
            c++;
        }
        else
        {
            s+=e[i].w;
        }
    }
    return s;
}

int main()
{
    int T;
    while(cin>>T&&T)
    {
        while(T--)
        {
            int N,E,x,y;
            cin>>N>>E;
            edge get;
            for(int i=0; i<E; i++)
            {
                cin>>get.u>>get.v>>get.w;
                e.push_back(get);
            }
            cout<<MST(N)<<endl;
            e.clear();
        }
    }
    return 0;
}