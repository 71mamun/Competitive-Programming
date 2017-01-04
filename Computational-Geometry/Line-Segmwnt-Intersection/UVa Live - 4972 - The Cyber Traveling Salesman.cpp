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
#define     eps             (1E-7)
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
struct tuple{int f,s,t;tuple() {} tuple(int a,int b,int c){f=a,s=b,t=c;}};
int cross_product(tuple a,tuple b){int v=a.f*(b.s-b.t)-a.s*(b.f-b.t)+a.t*(b.f-b.s);return (v==0?0:(v>0?+1:-1));}
tuple make_vector(tuple s,tuple e){tuple a;a.f=e.f-s.f;a.s=e.s-s.s;a.t=e.t-s.t;return a;}
///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
template<typename T> inline bool isOn(T &mask,int pos){return((mask)&(1LL<<pos));}
template<typename T> inline T setf(T mask,int pos){return mask=((mask)&(~(1LL<<pos)));}
template<typename T> inline T sett(T mask,int pos){return mask=((mask)(1LL<<pos));}
template<typename T> inline T flip(T mask,int pos){return mask=((mask)^(1LL<<pos));}
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
template<class T1> void putv(vector<T1>e1){for(int i=0; i<sz(e1); i++)(!i?cout<<e1[i]:cout<<" "<<e1[i]);cout<<endl;}
template<class T1> void puta(T1 arr[],int l){for(int i=0; i<l; i++)(!i?cout<<arr[i]:cout<<" "<<arr[i]);cout<<endl;}
///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
template<class T1> bool tk(T1 &e1){return(cin>>e1?true:false);}
template<class T1,class T2> bool tk(T1 &e1,T2 &e2){return(cin>>e1>>e2?true:false);}
template<class T1,class T2,class T3> bool tk(T1 &e1,T2 &e2,T3 &e3){return(cin>>e1>>e2>>e3?true:false);}
template<class T1,class T2,class T3,class T4> bool tk(T1 &e1,T2 &e2,T3 &e3,T4 &e4){return(cin>>e1>>e2>>e3>>e4?true:false);}
///HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
#define LM 12

int n,c,cost[LM][LM],odr[LM],tinp;
pii city[LM];
pair< pii, pii >road[LM];
pdd intpoint[LM*LM*LM];
pdd finl[LM*LM*LM];
int frq[LM*LM*LM];

bool isEql(int a,int b)
{
    pdd aa = intpoint[a];
    pdd bb = finl[b];
    if(abs(aa.fs-bb.fs)<eps and abs(aa.sc-bb.sc)<eps)return true;
    return false;
}

bool aqul(pdd a, pdd b)
{
    if(abs(a.fs-b.fs)<eps and abs(a.sc-b.sc)<eps)return true;
    return false;
}

int orientation(pii p, pii q, pii r)
{
    int v = cross_product(make_vector(tuple(p.fs,p.sc,0),tuple(q.fs,q.sc,0)),make_vector(tuple(q.fs,q.sc,0),tuple(r.fs,r.sc,0)));
    if(v==0)return 0;
    if(v>0)return 1;
    return 2;
}

bool incision(pii p1, pii q1, pii p2, pii q2)
{
    int or1 = orientation(p1, q1, p2);
    int or2 = orientation(p1, q1, q2);
    int or3 = orientation(p2, q2, p1);
    int or4 = orientation(p2, q2, q1);
    if (or1 != or2 && or3 != or4)return true;
    return false;
}

pdd calculate_intersection(tuple e1, tuple e2)
{
    double d = (e1.f*e2.s-e2.f*e1.s);
    double x = ((-e1.t)*(e2.s)-(-e2.t)*(e1.s))/d;
    double y = ((e1.f)*(-e2.t)-(e2.f)*(-e1.t))/d;
    return mp(x,y);
}

tuple create_equation(pii p, pii q)
{
    double a = (p.sc-q.sc);
    double b = -(p.fs-q.fs);
    double c = p.sc*(p.fs-q.fs)-p.fs*(p.sc-q.sc);
    return tuple(a,b,c);
}

bool check(pdd p,pii s1,pii e1,pii s2,pii e2)
{
    bool a = aqul(p,mp((double)s1.fs,(double)s1.sc));
    bool b = aqul(p,mp((double)e1.fs,(double)e1.sc));
    bool c = aqul(p,mp((double)s2.fs,(double)s2.sc));
    bool d = aqul(p,mp((double)e2.fs,(double)e2.sc));
    if(a or b or c or d)return true;
    return false;
}

bool alu()
{
    if(odr[1] == 1 and odr[2] == 5 and odr[3] == 2 and odr[4] == 6 and odr[5] == 4 and odr[6] == 3)return true;
    return false;
}

int cal_root(int n)
{
    double x1 = (1+sqrt(1+8*n))/2;
    double x2 = (1-sqrt(1+8*n))/2;
    double x = max(x1,x2);
    return x;
}

ll solve()
{
    ll ans = 0;
    tinp = 0;
    int u,v;
    For(i,2,n)
    {
        u = odr[i-1],v = odr[i];
        ans += cost[u][v];
        road[i] = mp(city[u],city[v]);
    }
    u = odr[n],v = odr[1];
    ans += cost[u][v];
    road[1] = mp(city[u],city[v]);
    For(i,1,n)
    {
        For(j,i+2,n)
        {
            if(incision(road[i].fs,road[i].sc,road[j].fs,road[j].sc))
            {
                pii s1 = road[i].fs,e1 = road[i].sc,s2 = road[j].fs,e2 = road[j].sc;
                tuple fequ = create_equation(road[i].fs,road[i].sc);
                tuple sequ = create_equation(road[j].fs,road[j].sc);
                pdd ppp = calculate_intersection(fequ,sequ);
                if(check(ppp,s1,e1,s2,e2))continue;
                intpoint[tinp++] = ppp;
            }
        }
    }
    mem(frq,0);
    if(tinp>0)
    {
        int done = 0;
        finl[0] = intpoint[0];
        frq[0]++;
        For(i,1,tinp-1)
        {
            For(j,0,done)
            {
                if(isEql(i,j))
                {
                    frq[j]++;
                    break;
                }
                else
                {
                    done++;
                    finl[done] = intpoint[i];
                    frq[done]++;
                    break;
                }
            }
        }
        For(i,0,done)
        {
            int no_of_line = cal_root(frq[i]);
            ans += (((no_of_line*(no_of_line-1))/2)*c);
        }
    }
    else
    {
        return ans;
    }
    return ans;
}

int main()
{
//    fread("in.txt");
//    fwrite("WA.txt");
    int t = 1;
    while(tk(n,c) and n+c)
    {
        For(i,1,n)tk(city[i].fs,city[i].sc);
        For(i,1,n)For(j,1,n)tk(cost[i][j]);
        For(i,1,n)odr[i]=i;
        ll ans = linf;
        do
        {
            ans = min(ans,solve());
        }
        while(next_permutation(odr+1,odr+(n+1)));
        pf("%d. %lld\n",t++,ans);
    }
    return 0;
}
/**

6 1
-6 6
0 1
2 1
1 0
100 37
45 7
0 3 1 3 1 7
8 0 3 9 3 6
1 3 0 2 2 8
3 9 2 0 4 6
5 3 1 9 0 6
1 15 5 1 2 0

*/

/**
AC:
1. 16

WA:
1. 15

*/
