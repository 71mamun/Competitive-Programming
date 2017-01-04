#include<algorithm>
#include<sstream>
#include<iostream>
#include<iomanip>
#include<climits>
#include<cstring>
#include<cassert>
#include<utility>
#include<limits>
#include<cstdio>
#include<string>
#include<vector>
#include<bitset>
#include<stack>
#include<ctime>
#include<queue>
#include<cmath>
#include<map>
#include<set>
using namespace std;
typedef long long ll;
typedef unsigned long long  ull;
#define     mem(a,b)        memset(a,b,sizeof(a))
#define     mp              make_pair
#define     pii             pair<int,int>
#define     fs              first
#define     sc              second
#define     VI              vector<int>
#define     clr(a)          a.clear()
#define     pb             push_back
#define     eps             1E-5
#define     sf              scanf
#define     pf              printf
#define     all(a)          a.begin(),a.end()
#define     allr(a)         a.rbegin(),a.rend()
#define     full(a,l)       a,a+l
#define     fread(name)     freopen(name,"r",stdin)
#define     fwrite(name)    freopen(name,"w",stdout)
#define     sz(a)           a.size()
#define     count_one       __builtin_popcount
#define     count_onell     __builtin_popcountll
#define     fastIO          ios_base::sync_with_stdio(false)
#define     PI              (acos(-1.0))
#define     linf            (1ll<<62)//>4e18
#define     inf             (0x7f7f7f7f)//>2e9
#define     fore(x,i)       for(typeof((x).begin()) i=(x.begin()); i!=(x).end(); ++i)
#define     rfore(x,i)      for(typeof((x).rbegin()) i=(x.rbegin()); i!=(x).rend(); ++i)
#define     For(i,a,b)      for(int i=a;i<=b;++i)
#define     rFor(i,a,b)     for(int i=a;i>=b;--i)
///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//int X[]={1,1,2,2,-1,-1,-2,-2},Y[]={2,-2,1,-1,2,-2,1,-1};
//int X[]={0,-1,-1,-1,0,1,1,1},Y[]={-1,-1,0,1,1,1,0,-1};
//int X[]={-1,0,1,0},Y[]={0,1,0,-1};
///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//ll bigMod(ll a,ll x,ll p){ll r=1;while(x>0){if(x%2!=0){r=(r*a)%p;}a=(a*a)%p;x=(x>>1);}return r;}
//ll modInverse(ll a, ll p){return bigMod(a,p-2,p);}
//ll extGcd(ll a,ll b,ll& x,ll& y){if(b==0){x=1;y=0;return a;}else{int g=extGcd(b,a%b,y,x);y-=a/b*x;return g;}}
template<class T> T pwr(T b, T p){T r=1,x=b;while(p){if(p&1)r*=x;x*=x;p=(p>>1);}return r;}
template<class T> T lcm(T a,T b){return(a/__gcd(a,b))*b;}
template<class T> T sqr(T a){return a*a;}
template<class T> void xswap (T &x,T &y){if(x!=y){x^=y;y^=x;x^=y;}}
///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//struct tuple{double f,s,t;tuple(){}tuple(double a,double b,double c){f=a,s=b,t=c;}};
//int cross_product(tuple a,tuple b){int v=a.f*(b.s-b.t)-a.s*(b.f-b.t)+a.t*(b.f-b.s);return (v==0?0:(v>0?+1:-1));}
//tuple make_vector(tuple s,tuple e){tuple a;a.f=e.f-s.f;a.s=e.s-s.s;a.t=e.t-s.t;return a;}
///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
template<typename T> inline bool is_on(T &mask,int pos){return((mask)&(1ll<<pos));}
template<typename T> inline T setf(T mask,int pos){return mask=((mask)&(~(1ll<<pos)));}
template<typename T> inline T sett(T mask,int pos){return mask=((mask)|(1ll<<pos));}
template<typename T> inline T flip(T mask,int pos){return mask=((mask)^(1ll<<pos));}
///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//double dtor(double x){return x*PI/180.0;}
//double rtod(double x){return x*180.0/PI;}
//double pdis(pdd a,pdd b){return sqrt((double)sqr(a.fs-b.fs)+sqr(a.sc-b.sc));}
//template<class T> double rAng(T a,T b,T c){double d=(sqr(a)+sqr(b)-sqr(c))/(a*b*2);d=(d<-1?-1:(d>1?1:d));return acos(d);}
///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//template<class T> string to_string(T n){ostringstream oss;oss<<n;oss.flush();return oss.str();}
//int to_int(string s){int r=0;istringstream sin(s);sin>>r;return r;}
///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
template<class T1> void put(T1 e){cout<<e<<endl;}
template<class T1,class T2> void put(T1 e1,T2 e2){cout<<e1<<" "<<e2<<endl;}
template<class T1,class T2,class T3> void put(T1 e1,T2 e2,T3 e3){cout<<e1<<" "<<e2<<" "<<e3<<endl;}
template<class T1,class T2,class T3,class T4> void put(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;}
template<class T1,class T2,class T3,class T4,class T5> void put(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<endl;}
template<class T1> void putv(vector<T1>e1){for(int i=0;i<sz(e1);i++)(!i?cout<<e1[i]:cout<<" "<<e1[i]);cout<<endl;}
template<class T1> void puta(T1 arr[],int l){for(int i=0;i<l;i++)(!i?cout<<arr[i]:cout<<" "<<arr[i]);cout<<endl;}
///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
template<class T1> bool tk(T1 &e1){return(cin>>e1?true:false);}
template<class T1,class T2> bool tk(T1 &e1,T2 &e2){return(cin>>e1>>e2?true:false);}
template<class T1,class T2,class T3> bool tk(T1 &e1,T2 &e2,T3 &e3){return(cin>>e1>>e2>>e3?true:false);}
template<class T1,class T2,class T3,class T4> bool tk(T1 &e1,T2 &e2,T3 &e3,T4 &e4){return(cin>>e1>>e2>>e3>>e4?true:false);}
///HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH


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

int n;

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

#define LM 207
int arr[LM];

bool is_prime(int v)
{
    int sqrtv = sqrt(v)+1;
    For(i,2,sqrtv)
    {
        if(v%i==0)return false;
    }
    return true;
}

bool col[LM];

VI tG[LM];
VI ans[LM];
int idx = 0;

int dfs(int src,int par,int init)
{
    if(col[src])return 0;
    col[src] = 1;
    ans[idx].pb(src);
    bool ok = true;
    int ans = 1;
    For(i,0,sz(tG[src])-1)
    {
        int v = tG[src][i];
        if(v==par)continue;
        if(col[v])continue;
        ans+=dfs(v,src,init);
        ok = false;
    }
    if(ok)
    {
        idx++;
    }
    return ans;
}


int main()
{
    int u,v;
    while(cin>>n)
    {
        int odd,even;
        odd = even = 0;
        Dinic dnk(n+10);
        For(i,1,n)
        {
            cin>>arr[i];
            if(arr[i]%2==0)
            {
                dnk.AddEdge(0,i,2);
            }
            else
            {
                dnk.AddEdge(i,n+1,2);
            }
        }

        For(i,1,n)
        {
            For(j,i+1,n)
            {
                if(is_prime(arr[i]+arr[j]))
                {
                    if(arr[i]%2==0)
                    {
                        u = i;v = j;
                    }
                    else
                    {
                        v = i;u = j;
                    }
                    dnk.AddEdge(u,v,1);
                }
            }
        }

        if(dnk.GetMaxFlow(0,n+1)!=n)
        {
            cout<<"Impossible"<<endl;
            return 0;
        }

        For(i,1,n)
        {
            For(j,0,sz(dnk.G[i])-1)
            {
                Edge e = dnk.G[i][j];
                if(e.from==0||e.to==n+1||e.to==0||e.from==n+1)continue;
                if(e.flow==1)
                {
                    tG[i].pb(e.to);
                    tG[e.to].pb(i);
                }
            }
        }



        For(i,1,n)
        {
            dfs(i,-1,i);
        }

        cout<<idx<<endl;
        For(i,0,idx-1)
        {
            cout<<sz(ans[i])<<" ";
            For(j,0,sz(ans[i])-1)
            {
                cout<<ans[i][j]<<" ";
            }
            cout<<endl;
        }
        return 0;
    }
}
