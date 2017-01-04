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
#define     pdd             pair<double,double>
#define     fs              first
#define     sc              second
#define     VI              vector<int>
#define     clr(a)          a.clear()
#define     pob             pop_back
#define     pub             push_back
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
#define     linf            (1LL<<62)//>4e18
#define     inf             (100000)
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
template<typename T> inline bool isOn(T &mask,int pos){return((mask)&(1LL<<pos));}
template<typename T> inline T setf(T mask,int pos){return mask=((mask)&(~(1LL<<pos)));}
template<typename T> inline T sett(T mask,int pos){return mask=((mask)|(1LL<<pos));}
template<typename T> inline T flip(T mask,int pos){return mask=((mask)^(1LL<<pos));}
///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//double dtor(double x){return x*PI/180.0;}
//double rtod(double x){return x*180.0/PI;}
double pdis(pdd a,pdd b){return sqrt((double)sqr(a.fs-b.fs)+sqr(a.sc-b.sc));}
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
#define LM 220
double mx;
struct info
{
    double x,y;
    int n,m;
    pdd coordinate()
    {
        return mp(x,y);
    }
};
info points[LM];

vector<int>G[LM];
vector<int>ansv;
int n,residual[LM][LM],org_residual[LM][LM],par[LM],source=0,drain,flow;

bool augment_path()
{
    queue<int>Q;
    Q.push(source);
    memset(par,-1,sizeof par);
    while(!Q.empty())
    {
        int u = Q.front();Q.pop();
        for(int i=0;i<G[u].size();++i)
        {
            int v = G[u][i];
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

void path_update(int v)
{
    int u = par[v];
    flow = min(flow,residual[u][v]);
    if(u!=source)path_update(u);
    residual[u][v]-=flow;
    residual[v][u]+=flow;
}

int max_flow()
{
    int tot_flow = 0;
    while(augment_path())
    {
        flow = (1<<28);
        path_update(drain);
        tot_flow+=flow;
    }
    return tot_flow;
}

int main()
{
    int T,u,v,tot_penguins,t=1;
    tk(T);
    while(T--)
    {
        ansv.clear();
        tk(n,mx);tot_penguins=0;
        For(i,0,2*(n+8))G[i].clear();
        mem(org_residual,0);
        For(i,1,n)
        {
            tk(points[i].x,points[i].y,points[i].n,points[i].m);
            tot_penguins+=points[i].n;
            v = i+n;
            u = i;
            /// unidirectional source to penguin initial position
            G[source].pub(u);
            G[u].pub(source);
            org_residual[source][u]+=points[i].n;
            /// unidirectional split position
            G[u].pub(v);
            G[v].pub(u);
            org_residual[u][v]+=points[i].m;
        }
        For(i,1,n)
        {
            For(j,1,n)
            {
                if(i==j)continue;
                if(pdis(points[i].coordinate(),points[j].coordinate())<=mx)
                {
                    u = i+n;
                    v = j;
                    /// unidirectional i to j jump is possible
                    G[u].push_back(v);
                    G[v].push_back(u);
                    org_residual[u][v]+=inf;
                }
            }
        }
        pf("Case %d: ",t++);
        For(i,1,n)
        {
            drain = i;
            For(j,0,2*n+8)
            {
                For(k,0,2*n+8)
                {
                    residual[j][k]=org_residual[j][k];
                }
            }
            int ans = max_flow();
            if(ans==tot_penguins)
            {
                ansv.pub(i-1);
            }
        }
        if(ansv.empty())put(-1);
        else putv(ansv);
    }
    return 0;
}
