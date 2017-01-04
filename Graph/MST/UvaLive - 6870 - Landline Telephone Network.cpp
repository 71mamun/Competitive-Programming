#include <sstream>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <complex>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
#include <bitset>
#include <list>
#include <string.h>
#include <assert.h>
#include <time.h>
using namespace std;
typedef long long ll;
typedef unsigned long long  ull;
#define     mem(a,b)        memset(a,b,sizeof(a))
#define     VI              vector<int>
#define     clr(a)          a.clear()
#define     pub             push_back
#define     all(a)          a.begin(),a.end()
#define     sz(a)           (int)a.size()
#define     linf            (1LL<<62)//>4e18
#define     inf             (0x7f7f7f7f)//>2e9
#define     For(i,a,b)      for(int i=a;i<=b;++i)
#define LM 2000

VI adj[LM];
VI cst[LM];
int parent[LM];
struct edge
{
    int u,v,w;
    edge(int a,int b,int c)
    {
        u = a,v = b, w = c;
    }

    bool operator<(const edge& p)const{return w<p.w;}

};

vector<edge> vc;

int deng[LM];

int find_par(int u)
{
    if(parent[u] == u) return u;
    return parent[u] = find_par(parent[u]);
}

int mst(int n)
{
    if(n==1)return 0;
    int cost = 0;
    sort(all(vc));

    for(int i=n;i>0;i--)
    {
        if(deng[i])continue;
        int loc = inf;
        For(j,0,sz(adj[i])-1)
        {
            int v = adj[i][j];
            int w = cst[i][j];
            if(deng[v])
                loc = min(loc,w);
        }
        if(loc>=inf)return -1;
        cost+=loc;
        n--;
    }

    For(i,0,sz(vc)-1)
    {
        int u = find_par(vc[i].u);
        int v = find_par(vc[i].v);
        if(u==v)continue;
        int w = vc[i].w;
        edge e = vc[i];
        if(deng[u]&&deng[v])
        {
            parent[u] = v;
            cost+=w;
            n--;
        }
        if(n==1)
        {
            return cost;
        }
    }
    return -1;
}

int main()
{
    int n,m,p;
    while(cin>>n>>m>>p)
    {
        vc.clear();
        For(i,0,n)
        {
            parent[i]=i;
            clr(adj[i]);
            clr(cst[i]);
            deng[i]=1;
        }
        For(i,0,p-1)
        {
            int x;
            cin>>x;
            deng[x]  = 0;
        }
        For(i,0,m-1)
        {
            int u,v,w;
            cin>>u>>v>>w;
            adj[u].pub(v);
            adj[v].pub(u);
            cst[u].pub(w);
            cst[v].pub(w);
            vc.pub(edge(u,v,w));
        }

        if(n==2&&p==2)
        {
            if(m==1)printf("%d\n",vc[0].w);
            else printf("impossible\n");
            continue;
        }

        int sol=mst(n);

        if(sol==-1)
        {
            printf("impossible\n");
        }
        else printf("%d\n",sol);
    }
    return 0;
}
/*
4 4 1
2
1 2 10
1 3 12
3 4 3
2 4 2
*/
