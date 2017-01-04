#include<bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define For(i,a,b) for(int i=a;i<=b;++i)
#define clr(a) a.clear()
#define sz(a) (int)a.size()
#define pb push_back
#define pf printf
#define sf scanf
#define inf (1e5+1)
#define LM 203
#define deb(a...)          {cerr<<"#"<<__LINE__<<" -> ";dbg,a; cerr<<endl;}
struct debugger
{
    template<typename T> debugger& operator , (const T v)
    {
        cerr<<v<<" ";
        return *this;
    }
} dbg;
int n,m;

struct edmonds_karp
{
    vector<int>adj[LM];
    int residual[LM][LM],org[LM][LM],danger[LM][LM],par[LM],N,flow;

    edmonds_karp(int n)
    {
        mem(residual,0);
        For(i,0,n)clr(adj[i]);
    }

    void clear(int n)
    {
        N = n;
        mem(residual,0);
        For(i,0,n)clr(adj[i]);
    }

    void create_org()
    {

        For(i,0,N)
        {
            For(j,0,N)
            {
                org[i][j] = residual[i][j];
            }
        }
    }

    void reset_residual()
    {
        For(i,0,N)
        {
            For(j,0,N)
            {
                residual[i][j] = org[i][j];
            }
        }
    }

    void add_edge(int u,int v,int cap,int dd)
    {
        if(residual[u][v])
        {
            residual[u][v]+=cap;
            return;
        }
        adj[u].pb(v);
        adj[v].pb(u);
        residual[u][v] = cap;
        danger[u][v] = dd;
        danger[v][u] = dd;
    }


    bool augment_path(int source,int sink,int dd)
    {
        queue<int>Q;
        Q.push(source);
        mem(par,-1);
        while(!Q.empty())
        {
            int u = Q.front();
            Q.pop();
            For(i,0,sz(adj[u])-1)
            {
                int v = adj[u][i];
                if(par[v]==-1 and residual[u][v]>0 and danger[u][v]<=dd)/// and u<v condition silo. flow cancel hoitesilo na.
                {
                    par[v]=u;
                    Q.push(v);
                    if(v==sink)return true;
                }
            }
        }
        return false;
    }

    void path_update(int v,int source)
    {
        int u = par[v];
        flow = min(flow,residual[u][v]);
        if(u!=source)path_update(u,source);
        residual[u][v]-=flow;
        residual[v][u]+=flow;
    }

    int max_flow(int source,int sink,int dd)
    {
        int tot_flow = 0;
        while(augment_path(source,sink,dd))
        {
            flow = 1e9;
            path_update(sink,source);
            tot_flow+=flow;
        }
        return tot_flow;
    }
};

int main()
{
    int T,u,v,dd,t=1,k;
    edmonds_karp ek(LM);
    sf("%d",&T);
    while(T--)
    {
        sf("%d %d",&n,&m);
        ek.clear(2*n+1);
        For(i,0,m-1)
        {
            sf("%d %d %d",&u,&v,&dd);
            if(u>v)swap(u,v);
            u = 2*u;
            v = 2*v-1;
            ek.add_edge(u,v,1,dd);
        }

        sf("%d",&k);

        For(i,1,n)
        {
            u = i*2-1;
            v = u+1;
            ek.add_edge(u,v,1,0);
        }

        ek.create_org();

        int hi = inf,lo = 0,mid,ans = inf;
        while(lo<=hi)
        {
            ek.reset_residual();
            mid = (hi+lo)/2;
            int flow = ek.max_flow(0,2*n+1,mid);
            if(flow>=k)
            {
                ans = mid;
                hi = mid-1;
            }
            else
            {
                lo = mid+1;
            }
        }

        pf("Case %d: ",t++);
        if(ans<inf)pf("%d\n",ans);
        else pf("no solution\n");
    }
    return 0;
}

/**

1
5
9
0 1 1
1 3 1
3 6 1
0 2 1
1 4 1
1 5 1
2 3 1
4 6 1
5 6 1
2

WA:
Case 1: no solution
AC:
Case 1: 1

*/
