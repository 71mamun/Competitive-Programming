#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long  ull;
#define     mem(a,b)        memset(a,b,sizeof(a))
#define     mp              make_pair
#define     pii             pair<ll,ll>
#define     fs              first
#define     sc              second
#define     pb              push_back
#define     eps             1E-5
#define     sf              scanf
#define     pf              printf
#define     all(a)          a.begin(),a.end()
#define     full(a,l)       a,a+l
#define     sz(a)           (int)a.size()
#define     count_onell     __builtin_popcountll
#define     PI              (acos(-1.0))
#define     INF             (1e9)
#define     For(i,a,b)      for(int i=a;i<=b;++i)
#define     rFor(i,a,b)     for(int i=a;i>=b;--i)
#define deb(a...)          {cerr<<"#"<<__LINE__<<" -> ";dbg,a; cerr<<endl;}
struct debugger { template<typename T> debugger& operator , (const T v) { cerr<<v<<" "; return *this; } } dbg;
template<class T1> void debv(vector<T1>e1){for(int i=0; i<sz(e1); i++)(!i?cout<<e1[i]:cout<<" "<<e1[i]);cout<<endl;}
template<class T1> void deba(T1 arr[],int l){for(int i=0; i<l; i++)(!i?cout<<arr[i]:cout<<" "<<arr[i]);cout<<endl;}
///HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHMAMUNHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
//template<class T> string to_string(T n){ostringstream oss;oss<<n;oss.flush();return oss.str();}
//int to_int(string s){int r=0;istringstream sin(s);sin>>r;return r;}

// Adjacency list implementation of Dinic's blocking flow algorithm.
// This is very fast in practice, and only loses to push-relabel flow.
//
// Running time:
//     O(|V|^2 |E|)
//
// INPUT:
//     - graph, constructed using add_edge()
//     - source and sink
//
// OUTPUT:
//     - maximum flow value
//     - To obtain actual flow values, look at edges with capacity > 0
//       (zero capacity edges are residual edges).

int n,m,source,sink;
#define LM 500

struct edmonds_karp
{
    vector<int>adj[LM];
    int residual[LM][LM],par[LM],N,flow;

    edmonds_karp(int n)
    {
        mem(residual,0);
        For(i,0,n)adj[i].clear();
    }

    void add_edge(int u,int v,int cap)
    {
        if(residual[u][v])
        {
            residual[u][v]+=cap;
            return;
        }
        adj[u].pb(v);
        adj[v].pb(u);
        residual[u][v] = cap;
    }


    bool augment_path(int source,int sink)
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
                if(par[v]==-1 and residual[u][v]>0)
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

    int max_flow(int source,int sink)
    {
        int tot_flow = 0;
        while(augment_path(source,sink))
        {
            flow = 1e9;
            path_update(sink,source);
            tot_flow+=flow;
        }
        return tot_flow;
    }
};

int row[LM],col[LM],ans[LM][LM];



int main()
{
    int T,t=1,rsum,csum;
    sf("%d",&T);
    while(T--)
    {
        sf("%d %d",&n,&m);

        rsum = csum = 0;
        edmonds_karp ek(n+m+5);
        source = 0;sink = n+m+1;

        mem(ans,0);

        For(i,1,n)
        {
            sf("%d",&row[i]);
            ek.add_edge(source,i,row[i]);
            rsum+=row[i];
        }
        For(j,1,m)
        {
            sf("%d",&col[j]);
            ek.add_edge(j+n,sink,col[j]);
            csum+=col[j];
        }

        rFor(i,n,1)
        {
            rFor(j,m,1)
            {
                ek.add_edge(i,j+n,1);
            }
        }

        pf("Case %d:",t++);
        if(rsum!=csum||ek.max_flow(source,sink)!=rsum)
        {
            pf(" impossible\n");
            continue;
        }

        pf("\n");

        For(u,1,n)
        {
            For(v,1+n,n+m)
            {
                if(ek.residual[u][v]==0)
                {
                    ek.residual[source][u]++;
                    ek.residual[v][sink]++;
                    ek.residual[u][v] = ek.residual[v][u] = 0;
                    int ans = ek.augment_path(source,sink);
                    if(ans)
                    {
                        ek.residual[u][v] = ek.residual[v][u] = 0;
                        ek.path_update(sink,source);
                        pf("0");
                    }
                    else
                    {
                        ek.residual[u][v] = ek.residual[v][u] = 0;
                        ek.residual[source][u]--;
                        ek.residual[v][sink]--;
                        pf("1");
                    }
                }
                else
                {
                    ek.residual[u][v] = ek.residual[v][u] = 0;
                    pf("0");
                }
            }
            pf("\n");
        }
    }
    return 0;
}

/*

5
3 3
1 1 1
1 1 1
3 3
1 1 2
2 2 1
2 3
30 30
30 20 10
2 9
5 5
1 1 2 1 1 1 1 1 1
3 3
1 2 3
3 2 1


*/
