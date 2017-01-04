#include<bits/stdc++.h>
using namespace std;
#define     mem(a,b)        memset(a,b,sizeof(a))
#define     For(i,a,b)      for(int i=a;i<=b;++i)
#define     rFor(i,a,b)     for(int i=a;i>=b;--i)
#define     sz(a)           (int)a.size()
#define     inf             (0x7f7f7f7f)
#define     pob             pop_back
#define     pub             push_back
#define     clr(a)          a.clear()
#define     sf              scanf
#define     pf              printf
///HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
#define LM 300
struct info
{
    int d;char sZ;
    info(){}
    info(int d, char sZ):d(d),sZ(sZ){}
};
info stone[LM];
vector<int>adj[LM];
int residual[LM][LM],par[LM],N,source=1,drain,flow;
inline bool augment_path()
{
    queue<int>Q;
    Q.push(source);
    mem(par,-1);
    while(!Q.empty())
    {
        int u = Q.front();Q.pop();
        For(i,0,sz(adj[u])-1)
        {
            int v = adj[u][i];
            if(par[v]==-1 and residual[u][v]>0)
            {
                par[v]=u;
                Q.push(v);
                if(v==drain)return true;
            }
        }
    }
    return false;
}

inline void path_update(int v)
{
    int u = par[v];
    flow = min(flow,residual[u][v]);
    if(u!=source)path_update(u);
    residual[u][v]-=flow;
    residual[v][u]+=flow;
}

inline int max_flow()
{
    int tot_flow = 0;
    while(augment_path())
    {
        flow = inf;
        path_update(drain);
        tot_flow+=flow;
    }
    return tot_flow;
}

inline void add_edge(int u,int v,int cost)
{
    if(residual[u][v])
    {
        residual[u][v]+=cost;
        return;
    }
    adj[u].pub(v);
    residual[u][v] = cost;
}

inline bool calculate(int max_leap)
{
    mem(residual,0);
    For(i,1,2*N)clr(adj[i]);
    For(i,1,N)
    {
        if(stone[i].sZ=='S')
        {
            add_edge(i,i+N,1);
            add_edge(i+N,i,0);
        }
        else
        {
            add_edge(i,i+N,inf);
            add_edge(i+N,i,0);
        }
    }
    For(i,1,N)
    {
        For(j,1,N)
        {
            if(i==j)continue;
            if(abs(stone[i].d-stone[j].d)<=max_leap)
            {
                add_edge(i+N,j,inf);
                add_edge(j,i+N,0);
            }
        }
    }
    if(max_flow()>=2)return true;
    return false;
}

int main()
{
    int T,D,mx,mn,mid,ans,t=1;
    char ch;
    sf("%d",&T);
    while(T--)
    {
        sf("%d %d",&N,&D);
        N+=2;
        drain = 2*N;
        For(i,2,N-1)
        {
            sf(" %c-%d",&stone[i].sZ,&stone[i].d);
        }
        stone[1].sZ = stone[N].sZ = 'B';
        stone[1].d=0;
        stone[N].d=D;
        mn=0;mx=D;
        while(true)
        {
            mid = (mx+mn)/2;
            if(mx<mn)break;
            if(calculate(mid))
            {
                ans = mid;
                mx=mid-1;
            }
            else
            {
                mn=mid+1;
            }
        }
        pf("Case %d: %d\n",t++,ans);
    }
    return 0;
}

