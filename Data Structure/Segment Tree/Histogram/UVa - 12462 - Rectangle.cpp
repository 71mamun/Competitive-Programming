#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long  ull;
#define     mem(a,b)        memset(a,b,sizeof(a))
#define     mp              make_pair
#define     pii             pair<ll,ll>
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
#define     sz(a)           (int)a.size()
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
ll bigMod(ll a,ll x,ll p){ll r=1;while(x>0){if(x%2!=0){r=(r*a)%p;}a=(a*a)%p;x=(x>>1);}return r;}
//ll modInverse(ll a, ll p){return bigMod(a,p-2,p);}
//ll extGcd(ll a,ll b,ll& x,ll& y){if(b==0){x=1;y=0;return a;}else{int g=extGcd(b,a%b,y,x);y-=a/b*x;return g;}}
template<class T> T pwr(T b, T p){T r=1,x=b;while(p){if(p&1)r*=x;x*=x;p=(p>>1);}return r;}
template<class T> T lcm(T a,T b){return(a/__gcd(a,b))*b;}
template<class T> T sqr(T a){return a*a;}
template<class T> void xswap (T &x,T &y){if(x!=y){x^=y;y^=x;x^=y;}}
///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
struct triple{double f,s,t;triple(){}triple(double a,double b,double c){f=a,s=b,t=c;}};
//int cross_product(triple a,triple b){int v=a.f*(b.s-b.t)-a.s*(b.f-b.t)+a.t*(b.f-b.s);return (v==0?0:(v>0?+1:-1));}
//triple make_vector(triple s,triple e){triple a;a.f=e.f-s.f;a.s=e.s-s.s;a.t=e.t-s.t;return a;}
///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
template<typename T> inline bool isOn(T &mask,int pos){return((mask)&(1LL<<pos));}
template<typename T> inline T setf(T mask,int pos){return mask=((mask)&(~(1LL<<pos)));}
template<typename T> inline T sett(T mask,int pos){return mask=((mask)|(1LL<<pos));}
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
template<class T1> void putv(vector<T1>e1){for(int i=0;i<sz(e1);i++)(!i?cout<<e1[i]:cout<<" "<<e1[i]);cout<<endl;}
template<class T1> void puta(T1 arr[],int l){for(int i=0;i<l;i++)(!i?cout<<arr[i]:cout<<" "<<arr[i]);cout<<endl;}
///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
template<class T1> bool tk(T1 &e1){return(cin>>e1?true:false);}
template<class T1,class T2> bool tk(T1 &e1,T2 &e2){return(cin>>e1>>e2?true:false);}
template<class T1,class T2,class T3> bool tk(T1 &e1,T2 &e2,T3 &e3){return(cin>>e1>>e2>>e3?true:false);}
template<class T1,class T2,class T3,class T4> bool tk(T1 &e1,T2 &e2,T3 &e3,T4 &e4){return(cin>>e1>>e2>>e3>>e4?true:false);}
///HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
#define LM 100007
ll T,n,m,t=1,ary[LM],clr[LM];
pii ary_tree[4*LM];
ll clr_tree[4*LM];

void initialize_ary(ll node,ll b,ll e)
{
    if(b==e)
    {
        ary_tree[node] = mp(ary[b],b);
        return;
    }
    ll left = node*2;
    ll right = left+1;
    ll mid = (b+e)/2;
    initialize_ary(left,b,mid);
    initialize_ary(right,mid+1,e);
    ary_tree[node].fs = min(ary_tree[left].fs,ary_tree[right].fs);
    ary_tree[node].sc = (ary_tree[node].fs==ary_tree[left].fs?ary_tree[left].sc:ary_tree[right].sc);
}

void initialize_clr(ll node,ll b,ll e)
{
    if(b==e)
    {
        clr_tree[node] = sett(0,clr[b]);
        return;
    }
    ll left = node*2;
    ll right = left+1;
    ll mid = (b+e)/2;
    initialize_clr(left,b,mid);
    initialize_clr(right,mid+1,e);
    clr_tree[node] = (clr_tree[left]|clr_tree[right]);
}

pii ary_query(ll node,ll b,ll e,ll i,ll j)
{
    if(i>e||j<b)return mp(inf,inf);
    if(b>=i&&e<=j)return ary_tree[node];
    ll left = node*2;
    ll right = left+1;
    ll mid = (b+e)/2;
    pii leftr = ary_query(left,b,mid,i,j);
    pii rightr = ary_query(right,mid+1,e,i,j);
    ll val = min(leftr.fs,rightr.fs);
    ll idx = (val==leftr.fs?leftr.sc:rightr.sc);
    return mp(val,idx);
}

ll clr_query(ll node,ll b,ll e,ll i,ll j)
{
    if(i>e||j<b)return 0;
    if(b>=i&&e<=j)return clr_tree[node];
    ll left = node*2;
    ll right = left+1;
    ll mid = (b+e)/2;
    return (clr_query(left,b,mid,i,j)|clr_query(right,mid+1,e,i,j));
}

ll calculate(ll b,ll e)
{
    if(e<0||b>n-1)return 0;
    if(b>e)return 0;
    pii res = ary_query(1,0,n-1,b,e);
    ll count = count_onell(clr_query(1,0,n-1,b,e));
    if(count!=m)return 0;
    /// only ekta bar er jonne count check korte silam na.
    /// ei if block er pore count check kortesilam
    if(b==e)
    {
        if(res.sc<inf)return res.fs;
        else return 0;
    }
    ///l count = count_onell(clr_query(1,0,n-1,b,e)); *#*#given WA for this in here.
    if(res.sc>=inf)return 0;
    ll ans = (e-b+1)*(ll)res.fs;
    ll lres = calculate(b,res.sc-1);
    ll rres = calculate(res.sc+1,e);
    ans = max(lres,max(ans,rres));
    return ans;
}

int main()
{
//    fread("in.txt");
    while(sf("%lld %lld",&n,&m)==2&&n+m)
    {
        For(i,0,n-1)
        {
            sf("%lld",ary+i);
        }
        For(i,0,n-1)
        {
            sf("%lld",clr+i);
        }
        initialize_ary(1,0,n-1);
        initialize_clr(1,0,n-1);
        pf("%lld\n",calculate(0,n-1));
    }
    return 0;
}
