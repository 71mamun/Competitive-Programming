#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long  ull;
#define     mem(a,b)        memset(a,b,sizeof(a))
#define     mp              make_pair
#define     pii             pair<int,int>
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
#define     inf             (0x3f3f3f3f)
#define     For(i,a,b)      for(int i=a;i<=b;++i)
#define     rFor(i,a,b)     for(int i=a;i>=b;--i)
#define deb(a...)          {cerr<<"#"<<__LINE__<<" -> ";dbg,a; cerr<<endl;}
struct debugger { template<typename T> debugger& operator , (const T v) { cerr<<v<<" "; return *this; } } dbg;
template<class T1> void debv(vector<T1>e1){for(int i=0; i<sz(e1); i++)(!i?cout<<e1[i]:cout<<" "<<e1[i]);cout<<endl;}
template<class T1> void deba(T1 arr[],int l){for(int i=0; i<l; i++)(!i?cout<<arr[i]:cout<<" "<<arr[i]);cout<<endl;}
///HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHMAMUNHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH

// Implementation of min cost max flow algorithm using adjacency
// matrix (Edmonds and Karp 1972).  This implementation keeps track of
// forward and reverse edges separately (so you can set cap[i][j] !=
// cap[j][i]).  For a regular max flow, set all edge costs to 0.
//
// Running time, O(|V|^2) cost per augmentation
//     max flow:           O(|V|^3) augmentations
//     min cost max flow:  O(|V|^4 * MAX_EDGE_COST) augmentations
//
// INPUT:
//     - graph, constructed using addEdge()
//     - source
//     - sink
//
// OUTPUT:
//     - (maximum flow value, minimum cost value)
//     - To obtain the actual flow, look at positive values only.
#define LM 120


///V*E^2 Complexity
///Base doesn't matter
///

const int MAXN = 20000;///total nodes
const int MAXM = 40000;///total edges

int edges,n,m;
///edge info
int last[MAXN];
int prev[MAXM],head[MAXM];
int Cap[MAXM];
int Cost[MAXM];

int Flow[MAXN];
int edgeNo[MAXN];
int dist[MAXN];
int par[MAXN];
bool visited[MAXN];

void init(int N)
{
    memset(last,-1,sizeof(int)*N);
    edges=0;
}

void addEdge(int u,int v,int cap,int cost)
{
    head[edges]=v;
    prev[edges]=last[u];
    Cap[edges]=cap;
    Cost[edges]=cost;
    last[u]=edges++;

    head[edges]=u;
    prev[edges]=last[v];
    Cap[edges]=0;
    Cost[edges]=-cost;
    last[v]=edges++;
}

queue<int> Q;
pair<int,int> SPFA(int S,int E,int N)
{
    int totFlow=0,totCost=0;
    while(!Q.empty()) Q.pop();
    int u,v,cap,cost;
    while(true)
    {
        Flow[S]=inf;
        memset(dist,inf,sizeof(int)*N);
        dist[S]=0;
        memset(visited,false,sizeof(bool)*N);
        visited[S]=1;
        Q.push(S);
        while(!Q.empty())
        {
            u=Q.front();Q.pop();
            visited[u]=false;
            for(int e=last[u];e>=0;e=prev[e])
            {
                v=head[e];
                cap=Cap[e];
                cost=Cost[e];
                if(cap&&dist[v]>dist[u]+cost)
                {
                    dist[v]=dist[u]+cost;
                    Flow[v]=min(Flow[u],cap);
                    edgeNo[v]=e;
                    par[v]=u;
                    if(!visited[v])
                    {
                        visited[v]=true;
                        Q.push(v);
                    }
                }
            }
        }
        if(dist[E]==inf) break;
        totCost+=dist[E]*Flow[E];
        totFlow+=Flow[E];
        for(int i=E;i!=S;i=par[i])
        {
            Cap[edgeNo[i]]-=Flow[E];
            Cap[edgeNo[i]^1]+=Flow[E];
        }
    }
    return mp(totFlow,totCost);
}

int mat[LM][LM];

pii get_node(int r,int c)
{
    if(r<0||c<0||r>=m||c>=n)return mp(-1,-1);
    int u = r*n+c;
    return mp(2*u,2*u+1);
}

int main()
{
    int T,t=1;
    sf("%d",&T);
    while(T--)
    {
        sf("%d %d",&m,&n);

        init(m*n*2+10);
        For(i,0,m-1)
        {
            For(j,0,n-1)
            {
                sf("%d",&mat[i][j]);
                int u = get_node(i,j).fs;
                if(u==-1)continue;
                addEdge(u,u+1,1,0);
            }
        }

        For(i,0,m-1)
        {
            For(j,0,n-1)
            {
                int u = get_node(i,j).sc;
                int v1 = get_node(i+1,j).fs;
                int v2 = get_node(i,j+1).fs;
                if(v1!=-1)
                {
                    addEdge(u,v1,1,-mat[i+1][j]);
                }
                if(v2!=-1)
                {
                    addEdge(u,v2,1,-mat[i][j+1]);
                }
            }
        }

        pii sink = get_node(m-1,n-1);

        pii ans = SPFA(1,get_node(m-1,n-1).fs,m*n*2);

        pf("Case %d: %d\n",t++,abs(ans.sc)+mat[0][0]-mat[m-1][n-1]);

    }
    return 0;
}
