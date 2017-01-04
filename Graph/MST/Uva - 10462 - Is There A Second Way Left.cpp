#include<bits/stdc++.h>
using namespace std;
#define SZ 110
#define edge_size 210
#define inf (1<<28)
struct edge
{
    int u,v,w;
    edge(int _,int __,int ___)
    {
        u=_;
        v=__;
        w=___;
    }
    bool operator < (const edge& p) const
    {
        return w<p.w;
    }
};
vector<edge>e;
int par[SZ];
int ecol[edge_size];

int get_par(int r)
{
    return (par[r]==r?r:par[r]=get_par(par[r]));
}

int MST(int N)
{
    for(int i=0; i<=N; i++)
        par[i]=i;
    int c=0,s=0;
    for(int i=0; i<e.size(); i++)
    {
        if(!ecol[i])
        {
            int u=get_par(e[i].u);
            int v=get_par(e[i].v);
            if(u!=v)
            {
                par[u]=v;
                c++;
                s+=e[i].w;
                ecol[i]=1;
                if(c==N-1)break;
            }
        }
    }
    if(c==N-1)return s;
    else return inf;
}

int main()
{
    int T,V,E,u,v,w,fmst[edge_size];
    cin>>T;
    for(int t=1; t<=T; t++)
    {
        cin>>V>>E;
        for(int i=0; i<E; i++)
        {
            cin>>u>>v>>w;
            e.push_back(edge(u,v,w));
            ecol[i]=fmst[i]=0;
        }
        sort(e.begin(),e.end());
        int fans  = MST(V);
        for(int i=0;i<E;i++)fmst[i]=ecol[i];
        int flag=0;
        if(fans==inf)flag = 1;
        int ans=inf;
        for(int i=0; i<E&&!flag; i++)
        {
            memset(ecol,0,sizeof(ecol));
            if(fmst[i])
            {
                ecol[i]=1;
                //cout<<MST(V)<<endl;
                ans=min(ans,MST(V));
                //cout<<"ans "<<ans<<endl;
                ecol[i]=0;
            }
        }
        //cout<<ans<<endl;
        cout<<"Case #"<<t<<" :";
        if(flag)cout<<" No way"<<endl;
        else if(ans==inf)cout<<" No second way"<<endl;
        else cout<<" "<<ans<<endl;
        e.clear();
    }
    return 0;
}
