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
struct tuple{int fs,sc,th;tuple(){}tuple(int a,int b,int c){fs=a,sc=b,th=c;}};
//int cross_product(tuple a,tuple b){int v=a.f*(b.s-b.t)-a.s*(b.f-b.t)+a.t*(b.f-b.s);return (v==0?0:(v>0?+1:-1));}
//tuple make_vector(tuple s,tuple e){tuple a;a.f=e.f-s.f;a.s=e.s-s.s;a.t=e.t-s.t;return a;}
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
template<class T1> void putv(vector<T1>e1){for(int i=0;i<sz(e1);i++)(!i?cout<<e1[i]:cout<<" "<<e1[i]);cout<<endl;}
template<class T1> void puta(T1 arr[],int l){for(int i=0;i<l;i++)(!i?cout<<arr[i]:cout<<" "<<arr[i]);cout<<endl;}
///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
template<class T1> bool tk(T1 &e1){return(cin>>e1?true:false);}
template<class T1,class T2> bool tk(T1 &e1,T2 &e2){return(cin>>e1>>e2?true:false);}
template<class T1,class T2,class T3> bool tk(T1 &e1,T2 &e2,T3 &e3){return(cin>>e1>>e2>>e3?true:false);}
template<class T1,class T2,class T3,class T4> bool tk(T1 &e1,T2 &e2,T3 &e3,T4 &e4){return(cin>>e1>>e2>>e3>>e4?true:false);}
///HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
#define LM 100010
int T,N,Q,opr,t=1;
tuple tree[4*LM];/// stores how many num has mod valu [1,2,0] with mod 3 as [fs,sc,th]
int lazy[4*LM];/// how many lime a segment flipped
bool upreq[4*LM];

tuple add(tuple a,tuple b)
{
    return tuple(a.fs+b.fs,a.sc+b.sc,a.th+b.th);
}

tuple increase(tuple a,int m)
{
    m %=3;
    return (m==1?tuple(a.sc,a.th,a.fs):(m==2?tuple(a.th,a.fs,a.sc):a));
}

void initialize(int node,int b,int e)
{
    if(b>e)return;
    if(b==e)
    {
        tree[node] = tuple(1,0,0);
        return;
    }
    initialize(node*2,b,(e+b)/2);
    initialize(node*2+1,1+(e+b)/2,e);
    tree[node] = add(tree[node*2],tree[node*2+1]);
}

void update(int node,int b,int e,int i,int j)
{
    int left = (node<<1);
    int right = (left|1);
    int mid = ((b+e)>>1);
    if(upreq[node])
    {
        tree[node] = increase(tree[node],lazy[node]);
        if(b!=e)
        {
            lazy[left] += lazy[node];
            lazy[right] += lazy[node];
            upreq[left] = upreq[right] = true;
        }
        lazy[node] = 0;
        upreq[node] = false;
    }
    if(b>e or j<b or i>e)return;
    if(b>=i and e<=j)
    {
        tree[node] = increase(tree[node],1);
        if(b!=e)
        {
            lazy[left] += 1;
            lazy[right] += 1;
            upreq[left] = upreq[right] = true;
        }
        return;
    }
    update(left,b,mid,i,j);
    update(right,mid+1,e,i,j);
    tree[node] = add(tree[left],tree[right]);
}

int query(int node,int b,int e,int i,int j)
{
    int left = (node<<1);
    int right = (left|1);
    int mid = ((b+e)>>1);
    if(upreq[node])
    {
        tree[node] = increase(tree[node],lazy[node]);
        if(b!=e)
        {
            lazy[left] += lazy[node];
            lazy[right] += lazy[node];
            upreq[left] = upreq[right] = true;
        }
        lazy[node] = 0;
        upreq[node] = false;
    }
    if(b>e or j<b or i>e)return 0;
    if(b>=i and e<=j)
    {
        return tree[node].th;
    }
    int q1 = query(left,b,mid,i,j);
    int q2 = query(right,mid+1,e,i,j);
    return q1+q2;
}

int main()
{
//    fread("in.txt");
    int s,e;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d",&N,&Q);
        For(i,0,4*N)upreq[i]=lazy[i]=false;
        initialize(1,0,N-1);
        printf("Case %d:\n",t++);
        while(Q--)
        {
            scanf("%d",&opr);
            if(opr==0)
            {
                scanf("%d %d",&s,&e);
                update(1,0,N-1,s,e);
            }
            else
            {
                scanf("%d %d",&s,&e);
                printf("%d\n",query(1,0,N-1,s,e));
            }
        }
    }
    return 0;
}
