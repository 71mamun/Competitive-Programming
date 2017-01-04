#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
#include<iostream>
using namespace std;
#define SZ 100005
#define Swap(x,y) x=x^y,y=x^y,x=x^y

int N;
int n,m;
int Table[SZ][22];
int level[SZ];
int dis[SZ];
int col[SZ];
vector<int>G[SZ];
vector<int>G2[SZ];
vector<int>cost[SZ];

void dfs(int src,int depth)
{
    level[src] = depth;
    for(int i=0; i<G[src].size(); i++)
    {
        dfs(G[src][i],depth+1);
    }
}

void dfs2(int src,int dep)
{
    dis[src] = dep;
    col[src] = 1;
    for(int i=0; i<G2[src].size(); i++)
    {
        int v = G2[src][i];
        if(col[v]==-1)
        {
            Table[v][0]=src;
            G[src].push_back(v);
            dfs2(v,dep+cost[src][i]);
        }
    }
}


void initSparseTable()
{
    for(int j = 1; (1<<j)<=N; j++)
    {
        for(int i=0; i<=N; i++)
        {
            (Table[i][j-1]==-1?:Table[i][j] = Table[Table[i][j-1]][j-1]);
        }
    }
}

int lcaQuery(int p,int q)
{
    if(level[p]<level[q])Swap(p,q);
    int h = log2(level[p]-level[q]);
    for(int i=h; i>=0; i--)
    {
        if(level[p]-(1<<i)>=level[q])
            p = Table[p][i];
    }
    if(p==q)return p;
    h = log2(level[p]);
    for(int i=h; i>=0; i--)
    {
        if(Table[p][i]!=-1&&Table[p][i]!=Table[q][i])
            p = Table[p][i],q = Table[q][i];
    }
    return Table[p][0];
}

void clear_all()
{
    memset(Table,-1,sizeof(Table));
    memset(col,-1,sizeof(col));
    for(int i=0; i<SZ; i++)
    {
        G[i].clear();
        G2[i].clear();
        cost[i].clear();
    }
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        clear_all();
        int a,b,M,w;
        cin>>N>>M;
        for(int i=0; i<N-1; i++)
        {
            cin>>a>>b>>w;
            G2[a].push_back(b);
            G2[b].push_back(a);
            cost[a].push_back(w);
            cost[b].push_back(w);
        }
        dfs2(1,0);
        initSparseTable();
        dfs(1,0);
        while(M--)
        {
            cin>>a>>b;
            int par = lcaQuery(a,b);
            cout<<dis[a]+dis[b]-2*dis[par]<<endl;
        }
    }
    return 0;
}