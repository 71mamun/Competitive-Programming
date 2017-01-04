///In the name of Allah, the Most Gracious, the Most Merciful.
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
typedef long long int ll;
typedef unsigned long long  ull;
typedef double dd;
typedef string str;
typedef char ch;
typedef int I;
#define     all(a)          a.begin(),a.end()
#define     allr(a)         a.rbegin(),a.rend()
#define     clr(a)          a.clear()
#define     count_one       __builtin_popcount;
#define     count_onell     __builtin_popcountll;
#define     degToRad(x)     (((1.0*(x)* PI)/180.0))
#define     eps             1E-7
#define     fastIO          ios_base::sync_with_stdio(false)
#define     fore(x,i)       for(typeof((x).begin()) i=(x.begin()); i!=(x).end(); ++i)
#define     fread(name)     freopen(name,"r",stdin);
#define     fs              first
#define     full(a,l)       a,a+l
#define     fwrite(name)    freopen(name,"w",stdout);
#define     has(c,e)        (c.find(e) != c.end())
#define     iInf            (1<<30)
#define     IT              iterator
#define     l_b(v,x)        lower_bound(v.begin(), v.end(), x)
#define     llInf           (1LL<<62)
#define     lsOne(S)        ((S)&(-(S)))
#define     max_e           max_element
#define     mems(a,b)       memset(a,b,sizeof(a))
#define     memc(a,b)       memcopy(a,b,sizeof(a))
#define     min_e           min_element
#define     MOD             (1000000007)
#define     mp              make_pair
#define     msInf           (0x7f7f7f7f)
#define     pf              printf
#define     PI              (acos(-1.0))
#define     pii             pair<I,I>
#define     pob             pop_back
#define     pof             pop_front
#define     pub             push_back
#define     puf             push_front
#define     radToDeg(x)     ((((x)*180.0)/(1.0 * PI)))
#define     rep(i,a,b)      for(I i=a; i<=b; ++i)
#define     rfore(x,i)      for(typeof((x).rbegin()) i=(x.rbegin()); i!=(x).rend(); ++i)
#define     repb(i,a)       for(I i=a;; ++i)
#define     repr(i,a,b)     for(I i=b; i>=a; --i)
#define     reprb(i,a)      for(I i=a;; --i)
#define     sc              second
#define     sf              scanf
#define     sz(a)           a.size()
#define     u_b(v,x)        upper_bound(v.begin(), v.end(), x)
#define     vec             vector
#define     vhas(c,e)       (find(all(c),e) != c.end())
///**
//output
template<class T1> void put(T1 e){cout<<e<<endl;}
template<class T1,class T2> void put(T1 e1,T2 e2){cout<<e1<<" "<<e2<<endl;}
template<class T1,class T2,class T3> void put(T1 e1,T2 e2,T3 e3){cout<<e1<<" "<<e2<<" "<<e3<<endl;}
template<class T1,class T2,class T3,class T4> void put(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;}
template<class T1,class T2,class T3,class T4,class T5> void put(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<endl;}
template<class T1,class T2,class T3,class T4,class T5,class T6> void put(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<endl;}
template<class T1> void putVec(vec<T1>e1){for(I i=0; i<sz(e1); i++)(!i?cout<<e1[i]:cout<<" "<<e1[i]);cout<<endl;}
template<class T1> void putArr(T1 arr[],I l){for(I i=0; i<l; i++)(!i?cout<<arr[i]:cout<<" "<<arr[i]);cout<<endl;}
//user library
template<class T>void xorSwap (T &x, T &y) {if (x != y) {x ^= y;y ^= x;x ^= y;}}
template<class T> T sqr(T a){return a*a;}
template<class T> dd radAng(T a,T b,T c){return acos((dd)(sqr(a)+sqr(b)-sqr(c))/(a*b*2));}
template<class T> T abs(T a){return (a<0?-a:a);}
template<class T> T lcm(T a, T b){return (a/__gcd(a,b)) * b;}
template<class T> T power(T b, T p){T res=1, x=b;while(p){if(p&1) res*=x;x*=x;p=(p>>1);}return res;}
template<class T> string toString(T n){ostringstream oss;oss<<n;oss.flush();return oss.str();}
I toInt(string s){I r=0;istringstream sin(s);sin>>r;return r;}
dd ppdis(pii a,pii b){return sqrt((dd)sqr(a.fs-b.fs)+sqr(a.sc-b.sc));}
ll extGcd(ll a, ll b, ll& x, ll& y){if (b == 0){x = 1;y = 0;return a;}else{I g = extGcd(b, a % b, y, x);y -= a / b * x;return g;}}
ll bigMod(ll a, ll x, ll p){ll res = 1;while(x > 0){if( x % 2 != 0){res = (res * a) % p;}a = (a * a) % p;x=(x>>1);}return res;}
ll modInverse(ll a, ll p){return bigMod(a, p-2, p);}
bool dsc(I a,I b){return a>b;}
//bit mask operation
template<typename T> inline bool isOn(T &mask,I pos){return ((mask)&(1<<pos));}
template<typename T> inline void setOff(T &mask,I pos){mask = ((mask)&(~(1<<pos)));}
template<typename T> inline void setOn(T &mask,I pos){mask = ((mask)(1<<pos));}
template<typename T> inline void flip(T &mask,I pos){mask = ((mask)^(1<<pos));}
//input
template<class T1> bool tk(T1 &e1){if(cin>>e1)return true;return false;}
template<class T1,class T2> bool tk(T1 &e1,T2 &e2){if(cin>>e1>>e2)return true;return false;}
template<class T1,class T2,class T3> bool tk(T1 &e1,T2 &e2,T3 &e3){if(cin>>e1>>e2>>e3)return true;return false;}
template<class T1,class T2,class T3,class T4> bool tk(T1 &e1,T2 &e2,T3 &e3,T4 &e4){if(cin>>e1>>e2>>e3>>e4)return true;return false;}

/**/
//I X[]={1,1,2,2,-1,-1,-2,-2},Y[]={2,-2,1,-1,2,-2,1,-1};//knight move
//I X[]={0,-1,-1,-1,0,1,1,1},Y[]={-1,-1,0,1,1,1,0,-1};//8 move
//I X[]={-1,0,1,0},Y[]={0,1,0,-1};//4 move
/*___________________________________________________________________________________________________________________________*/
#define SZ 110
vec<I>G[SZ];
set<str>ap;
vec<pii>b;
I n,c[SZ],l[SZ],t[SZ],d;
map<str,I>ci;
str cn[SZ];

void dfs(I u,I p,I r)
{
    c[u]=0;
    I cnt =0;
    l[u]=t[u]=++d;
    I m = sz(G[u]);
    for(I i=0;i<m;i++)
    {
        I v = G[u][i];
        if(v==p)continue;
        if(c[v]==-1)
        {
            cnt++;
            dfs(v,u,r);
            l[u]=min(l[u],l[v]);
            if(l[v]>=t[u]&&u!=r)ap.insert(cn[u]);
            if(l[v]>t[u])b.pub(mp(min(u,v),max(u,v)));
        }
        else
        {
            l[u]=min(l[u],t[v]);
        }
    }
    if(u==r&&cnt>1)ap.insert(cn[u]);
}

pii capb()
{
    for(I i=0;i<=n;i++)c[i]=-1;
    ap.clear();
    b.clear();
    d=-1;
    for(I i=1;i<=n;i++)
    {
        if(c[i]==-1)dfs(i,-1,i);
    }
    return mp(sz(ap),sz(b));
}

I main()
{
    //fread("in.txt");
    //fwrite("out.txt");
    I m,t=0;
    str s1,s2;
    while(tk(n)&&n)
    {
        if(t)put("");
        clr(ci);
        for(I i=0; i<n; i++)clr(G[i]);
        d=-1;
        for(I i=0; i<n; i++)
        {
            tk(cn[i]);
            ci[cn[i]] = i;
        }
        tk(m);
        while(m--)
        {
            tk(s1,s2);
            I u = ci[s1],v = ci[s2];
            G[u].pub(v),G[v].pub(u);
        }
        pii ans = capb();
        pf("City map #%d: %d camera(s) found\n",++t,ans.fs);
        fore(ap,it)put(*it);
    }
    return 0;
}
