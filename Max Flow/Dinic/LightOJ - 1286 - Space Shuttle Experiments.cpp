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
//     - graph, constructed using AddEdge()
//     - source and sink
//
// OUTPUT:
//     - maximum flow value
//     - To obtain actual flow values, look at edges with capacity > 0
//       (zero capacity edges are residual edges).

int n,m,source,sink;

struct Edge
{
    int from, to, cap, flow, index;
    Edge(int from, int to, int cap, int flow, int index) :
        from(from), to(to), cap(cap), flow(flow), index(index) {}
    ll rcap()
    {
        return cap - flow;
    }
};

struct Dinic
{
    int N;
    vector<vector<Edge> > G;
    vector<vector<Edge *> > Lf;
    vector<int> layer;
    vector<int> Q;

    Dinic(int N) : N(N), G(N), Q(N) {}

    void AddEdge(int from, int to, int cap)
    {
        if (from == to) return;
        G[from].push_back(Edge(from, to, cap, 0, G[to].size()));
        G[to].push_back(Edge(to, from, 0, 0, G[from].size() - 1));
    }

    ll BlockingFlow(int s, int t)
    {
        layer.clear();
        layer.resize(N, -1);
        layer[s] = 0;
        Lf.clear();
        Lf.resize(N);

        int head = 0, tail = 0;
        Q[tail++] = s;
        while (head < tail)
        {
            int x = Q[head++];
            for (int i = 0; i < G[x].size(); i++)
            {
                Edge &e = G[x][i];
                if (e.rcap() <= 0) continue;
                if (layer[e.to] == -1)
                {
                    layer[e.to] = layer[e.from] + 1;
                    Q[tail++] = e.to;
                }
                if (layer[e.to] > layer[e.from])
                {
                    Lf[e.from].push_back(&e);
                }
            }
        }
        if (layer[t] == -1) return 0;

        ll totflow = 0;
        vector<Edge *> P;
        while (!Lf[s].empty())
        {
            int curr = P.empty() ? s : P.back()->to;
            if (curr == t)   // Augment
            {
                ll amt = P.front()->rcap();
                for (int i = 0; i < P.size(); ++i)
                {
                    amt = min(amt, P[i]->rcap());
                }
                totflow += amt;
                for (int i = P.size() - 1; i >= 0; --i)
                {
                    P[i]->flow += amt;
                    G[P[i]->to][P[i]->index].flow -= amt;
                    if (P[i]->rcap() <= 0)
                    {
                        Lf[P[i]->from].pop_back();
                        P.resize(i);
                    }
                }
            }
            else if (Lf[curr].empty())     // Retreat
            {
                P.pop_back();
                for (int i = 0; i < N; ++i)
                    for (int j = 0; j < Lf[i].size(); ++j)
                        if (Lf[i][j]->to == curr)
                            Lf[i].erase(Lf[i].begin() + j);
            }
            else     // Advance
            {
                P.push_back(Lf[curr].back());
            }
        }
        return totflow;
    }

    ll GetMaxFlow(int s, int t)
    {
        ll totflow = 0;
        while (ll flow = BlockingFlow(s, t))
            totflow += flow;
        return totflow;
    }
};


int main()
{
    int T,w,v,t=1,tot;
    sf("%d",&T);
    while(T--)
    {
        sf("%d %d",&m,&n);
        Dinic dk(m+n+10);
        source = 0;sink = n+m+1;tot=0;
        For(u,1,m)
        {
            sf("%d",&w);
            dk.AddEdge(source,u,w);
            tot+=w;
        }
        For(v,m+1,n+m)
        {
            sf("%d",&w);
            dk.AddEdge(v,sink,w);
        }

        int l;
        For(u,1,m)
        {
            sf("%d",&l);
            For(i,0,l-1)
            {
                sf("%d",&v);
                dk.AddEdge(u,v+m,INF);
            }
        }

        pf("Case %d: %d\n",t++,tot-dk.GetMaxFlow(source,sink));

    }
    return 0;
}

/*

1
3 5
20 30 40
1 2 30 4 50
3 1 2 3
3 2 3 4
1 5


*/
