#include<bits/stdc++.h>
using namespace std;
#define sf scanf
#define pf printf
#define pb push_back

#define LM 100007
int n,m,somoy = 0,sn;
int node_col[LM],start[LM],finish[LM],col[LM],res[LM],frq[LM],csum[LM];
vector<int>G[LM];

void dfs(int u,int p)
{
    start[u] = ++somoy;
    col[somoy] = node_col[u];
    for(int i=0;i<G[u].size();++i)
    {
        int v = G[u][i];
        if(v==p)continue;
        dfs(v,u);
    }
    finish[u] = somoy;
}

struct info
{
    int u,v,k,idx;
};

bool cmp(info a,info b)
{
    if(a.u/sn!=b.u/sn)
        return a.u/sn<b.u/sn;
    return a.v<b.v;
}

info qrs[LM];

void add(int v)
{
    frq[v]++;
    csum[frq[v]]++;
}

void eject(int v)
{
    csum[frq[v]]--;
    frq[v]--;
}

int main()
{
    int i,u,v;
    sf("%d %d",&n,&m);

    for(i=1;i<=n;++i)
    {
        sf("%d",node_col+i);
    }

    for(i=1;i<n;++i)
    {
        sf("%d %d",&u,&v);
        G[u].pb(v);
        G[v].pb(u);
    }

    dfs(1,-1);

    for(i=0;i<m;++i)
    {
        sf("%d %d",&u,&v);
        qrs[i] = {start[u],finish[u],v,i};
    }

    sn = sqrt(n);
    sort(qrs,qrs+m,cmp);
    int cl=0,cr=-1;

    for(i=0;i<m;++i)
    {
        info a = qrs[i];
        while(cl<a.u)
            eject(col[cl++]);
        while(cl>a.u)
            add(col[--cl]);
        while(cr<a.v)
            add(col[++cr]);
        while(cr>a.v)
            eject(col[cr--]);
        res[a.idx] = csum[a.k];
    }

    for(i=0;i<m;++i)
    {
        pf("%d\n",res[i]);
    }

    return 0;
}
