///In the name of Allah, the Most Gracious, the Most Merciful.
#include<algorithm>
#include<sstream>
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
#define     mems(a,b)       memset(a,b,sizeof(a))
#define     memc(a,b)       memcopy(a,b,sizeof(a))
#define     IT              iterator
#define     mp              make_pair
#define     pii             pair<int,int>
#define     fs              first
#define     sc              second
#define     vec             vector
#define     clr(a)          a.clear()
#define     pob             pop_back
#define     pub             push_back
#define     eps             1E-7
#define     sf              scanf
#define     pf              printf
#define     all(a)          a.begin(),a.end()
#define     allr(a)         a.rbegin(),a.rend()
#define     full(a,l)       a,a+l
#define     fread(name)     freopen(name,"r",stdin);
#define     fwrite(name)    freopen(name,"w",stdout);
#define     sz(a)           a.size()
#define     count_one       __builtin_popcount;
#define     count_onell     __builtin_popcountll;
#define     fastIO          ios_base::sync_with_stdio(false)
#define     degToRad(x)     (((1.0*(x)* PI)/180.0))
#define     radToDeg(x)     ((((x)*180.0)/(1.0 * PI)))
#define     PI              (acos(-1.0))
#define     llInf           (1LL<<62)
#define     msInf           (Ox7f7f7f7f)
#define     iInf          (1<<30)
#define     l_b(v,x)         lower_bound(v.begin(), v.end(), x)
#define     u_b(v,x)         upper_bound(v.begin(), v.end(), x)
#define     fore(x,i)       for(typeof((x).begin()) i=(x.begin()); i!=(x).end(); ++i)
#define     rfore(x,i)      for(typeof((x).rbegin()) i=(x.rbegin()); i!=(x).rend(); ++i)
#define     has(c,e)        (c.find(e) != c.end())
#define     vhas(c,e)       (find(all(c),e) != c.end())
//typedef
typedef int I;
typedef long long int ll;
typedef unsigned long long  ull;
typedef double dd;
typedef string str;
/**
//output
template<class T1> void put(T1 e){cout<<e<<endl;}
template<class T1,class T2> void put(T1 e1,T2 e2){cout<<e1<<" "<<e2<<endl;}
template<class T1,class T2,class T3> void put(T1 e1,T2 e2,T3 e3){cout<<e1<<" "<<e2<<" "<<e3<<endl;}
template<class T1,class T2,class T3,class T4> void put(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;}
template<class T1,class T2,class T3,class T4,class T5> void put(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<endl;}
template<class T1,class T2,class T3,class T4,class T5,class T6> void put(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<endl;}
template<class T1> void put(vec<T1>e1){for(int i=0; i<sz(e1); i++)(!i?cout<<e1[i]:cout<<" "<<e1[i]);cout<<endl;}
template<class T1> void put(T1 arr[],int l){for(int i=0; i<l; i++)(!i?cout<<arr[i]:cout<<" "<<arr[i]);cout<<endl;}
//user library
template<class T> T sqr(T a){return a*a;}
template<class T> dd radAng(T a,T b,T c){return acos((dd)(sqr(a)+sqr(b)-sqr(c))/(a*b*2));}
template<class T> T abs(T a){return (a<0?-a:a);}
template<class T> T lcm(T a, T b){return (a/__gcd(a,b)) * b;}
template<class T> T bigMod(T a, T x, T p){T res = 1;while(x > 0){if( x % 2 != 0){res = (res * a) % p;}a = (a * a) % p;x=(x>>1);}return res;}
template<class T> T modInverse(T a, T p){return bigMod(a, p-2, p);}
template<class T> T power(T b, T p){T res=1, x=b;while(p){if(p&1) res*=x;x*=x;p=(p>>1);}return res;}
template<class T> string toString(T n){ostringstream oss;oss<<n;oss.flush();return oss.str();}
int toInt(string s){int r=0;istringstream sin(s);sin>>r;return r;}
dd ppdis(pii a,pii b){return sqrt((dd)sqr(a.fs-b.fs)+sqr(a.sc-b.sc));}
ll extGcd(ll a, ll b, ll& x, ll& y){if (b == 0){x = 1;y = 0;return a;}else{int g = extGcd(b, a % b, y, x);y -= a / b * x;return g;}}
bool dsc(int a,int b){return a>b;}
bool asc(int a,int b){return a<b;}
//bit mask operation
template<typename T> inline bool isOn(T *mask,int pos){return ((*mask)&(1<<pos));}
template<typename T> inline void setOff(T *mask,int pos){*mask = ((*mask)&(~(1<<pos)));}
template<typename T> inline void setOn(T *mask,int pos){*mask = ((*mask)|(1<<pos));}
template<typename T> inline void toggle(T *mask,int pos){*mask = ((*mask)^(1<<pos));}
//input
void tk(I &a){cin>>a;}
void tk(I &a,I &b){cin>>a>>b;}
void tk(I &a,I&b,I &c){cin>>a>>b>>c;}
/**/
//int X[]={1,1,2,2,-1,-1,-2,-2},Y[]={2,-2,1,-1,2,-2,1,-1};//knight move
//int X[]={0,-1,-1,-1,0,1,1,1},Y[]={-1,-1,0,1,1,1,0,-1};//8 move
//int X[]={-1,0,1,0},Y[]={0,1,0,-1};//4 move
#define SZ 2005
/*__________________________________________________MAIN_CODE_____________________________________________________*/
ll n;
ll grd[SZ][SZ];
ll col[SZ];
ll par[SZ];
vec<ll>GH[SZ];
vec<ll>DI[SZ];

struct edge
{
    ll u,v,w;
    edge(ll a,ll b,ll c)
    {
        u=a,v=b,w=c;
    }
};

bool comp(const edge &a,const edge &b)
{
    return a.w<b.w;
}

vec<edge>ev;

void setPar()
{
    for(ll i=0;i<n;i++)par[i]=i;
}

I getPar(ll r)
{
    return par[r]==r?r:par[r]=getPar(par[r]);
}

bool isCon(ll a,ll b)
{
    return getPar(a)==getPar(b)?true:false;
}

void Union(ll a,ll b)
{
    ll u = getPar(a);
    ll v = getPar(b);
    par[u]=v;
}

bool check()
{
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<n;j++)
        {
            if(i==j&&grd[i][j])return true;
            if(i==j)continue;
            if(grd[i][j]!=grd[j][i]||grd[i][j]<=0)return true;
        }
    }
    return false;
}

ll res;

bool dfs(ll src,ll cdis)
{
    col[src]=0;
    bool ans = true;
    for(ll i=0;i<sz(GH[src]);i++)
    {
        ll des = GH[src][i];
        ll dis = DI[src][i];
        if(col[des]!=-1)continue;
        if(cdis+dis!=grd[res][des])return false;
        ans = dfs(des,cdis+dis)&&ans;
    }
    return ans;
}

void setEdge()
{
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<n;j++)
        {
            if(i==j)continue;
            ev.pub(edge(i,j,grd[i][j]));
        }
    }
}

void buildGraph()
{
    setEdge();
    setPar();
    sort(all(ev),comp);
    for(ll i=0;i<sz(ev);i++)
    {
        edge ne = ev[i];
        if(!isCon(ne.u,ne.v))
        {
            GH[ne.u].pub(ne.v);
            GH[ne.v].pub(ne.u);
            DI[ne.u].pub(ne.w);
            DI[ne.v].pub(ne.w);
            Union(ne.u,ne.v);
        }
    }
}

bool solve()
{
    buildGraph();
    for(ll i=0;i<n;i++)
    {
        for(I i=0;i<n;i++)col[i]=-1LL;
        res=i;
        if(!dfs(i,0))return false;
    }
    return true;
}

I main()
{
    scanf("%I64d",&n);
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<n;j++)
        {
            scanf("%I64d",&grd[i][j]);
        }
    }
    if(check())
    {
        printf("NO");
        return 0;
    }
    if(solve())printf("YES");
    else printf("NO");
    return 0;
}
