#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
#include<iostream>
using namespace std;
#define sf scanf
#define pf printf
#define PrintCase printf("Case %d:\n",t++)
#define ms(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define SZ 100005
#define Swap(x,y) x=x^y,y=x^y,x=x^y

int N;
int Table[SZ][22];
int valu[SZ];
int level[SZ];
vector<int>G[SZ];

void dfs(int src,int depth)
{
    level[src] = depth;
    for(int i=0; i<G[src].size(); i++)
    {
        dfs(G[src][i],depth+1);
    }
}

void initSparseTable()
{
    for(int j=1; (1<<j)<N; j++)
    {
        for(int i=0; i<N; i++)
        {
            (Table[i][j-1]==-1?:Table[i][j] = Table[Table[i][j-1]][j-1]);
        }
    }
}

int lcaQuery(int p,int v)
{
    int h = log2(level[p]);
    for(int i=h; i>=0; i--)
    {
        if(valu[Table[p][i]]>=v)
            p = Table[p][i];
    }
    return p;
}

int main()
{
    int T,t=1,M,a,b;
    sf("%d",&T);
    while(T--)
    {
        ms(Table,-1);
        ms(valu,0);
        sf("%d %d",&N,&M);
        for(int i=1; i<N; i++)
        {
            sf("%d %d",&a,&b);
            Table[i][0]=a;
            valu[i]=b;
            G[a].pb(i);
        }
        valu[0]=1;
        initSparseTable();
        dfs(0,0);
        PrintCase;
        while(M--)
        {
            sf("%d %d",&a,&b);
            pf("%d\n",lcaQuery(a,b));
        }
        for(int i=0;i<N;i++)G[i].clear();
    }
    return 0;
}

