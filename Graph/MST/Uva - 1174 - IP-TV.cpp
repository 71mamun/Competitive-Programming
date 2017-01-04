#include<bits/stdc++.h>
#define SZ 2010
using namespace std;
struct edge
{
    int u,v,w;
    bool operator < (const edge& p) const
    {
        return w<p.w;
    }
};

vector<edge>e;
int par[SZ];

int get_par(int r)
{
    return (par[r]==r?r:par[r]=get_par(par[r]));
}

int MST(int N,int E)
{
    sort(e.begin(),e.end());
    for(int i=0;i<N;i++)
        par[i]=i;
    int c=0,s=0;
    for(int i=0;i<e.size();i++)
    {
        int u=get_par(e[i].u);
        int v=get_par(e[i].v);
        if(u!=v)
        {
            par[u]=v;
            c++;
            s+=e[i].w;
            if(c==N-1)break;
        }
    }
    return s;
}

int main()
{
    map<string,int>vos;
    string uu,vv;
    edge get;
    int T,N,E,ww;
    cin>>T;
    while(T--)
    {
        cin>>N>>E;
        vos.clear();
        int l=0;
        for(int i=0;i<E;i++)
        {
            cin>>uu>>vv>>ww;
            if(vos.find(uu)==vos.end())vos[uu]=l++;
            if(vos.find(vv)==vos.end())vos[vv]=l++;
            get.u=vos[uu];get.v=vos[vv];get.w=ww;
            e.push_back(get);
        }
        cout<<MST(N,E)<<endl;
        e.clear();
        if(T)cout<<endl;
    }
    return 0;
}