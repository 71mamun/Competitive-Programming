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
typedef int I;
#define     mems(a,b)       memset(a,b,sizeof(a))
#define     memc(a,b)       memcopy(a,b,sizeof(a))
#define     IT              iterator
#define     mp              make_pair
#define     pii             pair<I,I>
#define     fs              first
#define     sc              second
#define     vec             vector
#define     clr(a)          a.clear()
#define     pob             pop_back
#define     pof             pop_front
#define     pub             push_back
#define     puf             push_front
#define     eps             1E-8
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
#define     MOD             (1000000007)
#define     llInf           (1LL<<62)
#define     msInf           (0x7f7f7f7f)
#define     iInf            (1<<30)
#define     l_b(v,x)        lower_bound(v.begin(), v.end(), x)
#define     u_b(v,x)        upper_bound(v.begin(), v.end(), x)
#define     min_e           min_element
#define     max_e           max_element
#define     fore(x,i)       for(typeof((x).begin()) i=(x.begin()); i!=(x).end(); ++i)
#define     rfore(x,i)      for(typeof((x).rbegin()) i=(x.rbegin()); i!=(x).rend(); ++i)
#define     has(c,e)        (c.find(e) != c.end())
#define     vhas(c,e)       (find(all(c),e) != c.end())
#define     lsOne(S)        ((S)&(-(S)))
#define     rep(i,a,b)      for(I i=a; i<=b; ++i)
#define     repb(i,a)       for(I i=a;; ++i)
#define     repr(i,a,b)     for(I i=b; i>=a; --i)
#define     reprb(i,a)      for(I i=a;; --i)
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

struct tpl
{
    dd x,y,z;
    tpl()
    {

    }
    tpl(dd a,dd b,dd c)
    {
        x=a,y=b,z=c;
    }
};

dd tplDis(tpl a, tpl b)
{
    return sqrt(sqr(a.x-b.x)+sqr(a.y-b.y)+sqr(a.z-b.z));
}

dd ternarySearch(tpl l,tpl r,tpl p)
{
    tpl lm = tpl((2*l.x+r.x)/3,(2*l.y+r.y)/3,(2*l.z+r.z)/3);
    tpl rm = tpl((l.x+2*r.x)/3,(l.y+2*r.y)/3,(l.z+2*r.z)/3);
    dd dlm = tplDis(lm,p);
    dd drm = tplDis(rm,p);
    if(abs(dlm-drm)<eps) return tplDis(tpl((lm.x+rm.x)/2,(lm.y+rm.y)/2,(lm.z+rm.z)/2),p);
    if(dlm<drm) return ternarySearch(l,rm,p);
    else return ternarySearch(lm,r,p);
}

I main()
{
    tpl a,b,c;
    I T,t=0;
    tk(T);
    while(T--)
    {
        tk(a.x,a.y,a.z);
        tk(b.x,b.y,b.z);
        tk(c.x,c.y,c.z);
        pf("Case %d: %.12lf\n",++t,ternarySearch(a,b,c));
    }
    return 0;
}
