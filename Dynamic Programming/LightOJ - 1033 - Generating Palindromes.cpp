#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long  ull;
#define     mems(a,b)       memset(a,b,sizeof(a))
#define     mp              make_pair
#define     pii             pair<int,int>
#define     fs              first
#define     sc              second
#define     VI              vector<int>
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
#define     PI              (acos(-1.0))
#define     MOD             (1000000007)
#define     linf            (1LL<<62)
#define     inf             (0x7f7f7f7f)
#define     fore(x,i)       for(typeof((x).begin()) i=(x.begin()); i!=(x).end(); ++i)
#define     rfore(x,i)      for(typeof((x).rbegin()) i=(x.rbegin()); i!=(x).rend(); ++i)
#define     For(i,a,b)      for(int i=a;i<=b;++i)
#define     rFor(i,a,b)     for(int i=a;i>=b;--i)
///*
template<class T1> void put(T1 e){cout<<e<<endl;}
template<class T1,class T2> void put(T1 e1,T2 e2){cout<<e1<<" "<<e2<<endl;}
template<class T1,class T2,class T3> void put(T1 e1,T2 e2,T3 e3){cout<<e1<<" "<<e2<<" "<<e3<<endl;}
template<class T1,class T2,class T3,class T4> void put(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;}
template<class T1> void putv(vector<T1>e1){for(int i=0;i<sz(e1);i++)(!i?cout<<e1[i]:cout<<" "<<e1[i]);cout<<endl;}
template<class T1> void puta(T1 arr[],int l){for(int i=0;i<l;i++)(!i?cout<<arr[i]:cout<<" "<<arr[i]);cout<<endl;}
template<class T> void xSwap (T &x,T &y){if(x!=y){x^=y;y^=x;x^=y;}}
template<class T> T sqr(T a){return a*a;}
template<class T> T pwr(T b, T p){T res=1,x=b;while(p){if(p&1)res*=x;x*=x;p=(p>>1);}return res;}
ll bigMod(ll a,ll x,ll p){ll res=1;while(x>0){if(x%2!=0){res=(res*a)%p;}a=(a*a)%p;x=(x>>1);}return res;}
ll modInverse(ll a, ll p){return bigMod(a,p-2,p);}
double dtor(double x){return x*PI/180.0;}
double rtod(double x){return x*180.0/PI;}
template<class T> double rAng(T a,T b,T c){return acos((double)(sqr(a)+sqr(b)-sqr(c))/(a*b*2));}
template<class T> T lcm(T a,T b){return(a/__gcd(a,b))*b;}
ll extGcd(ll a,ll b,ll& x,ll& y){if(b==0){x=1;y=0;return a;}else{int g=extGcd(b,a%b,y,x);y-=a/b*x;return g;}}
double pdis(pii a,pii b){return sqrt((double)sqr(a.fs-b.fs)+sqr(a.sc-b.sc));}
template<class T> string toString(T n){ostringstream oss;oss<<n;oss.flush();return oss.str();}
int toInt(string s){int r=0;istringstream sin(s);sin>>r;return r;}
template<typename T> inline bool isOn(T &mask,int pos){return((mask)&(1LL<<pos));}
template<typename T> inline void setf(T &mask,int pos){mask=((mask)&(~(1LL<<pos)));}
template<typename T> inline void sett(T &mask,int pos){mask=((mask)(1LL<<pos));}
template<typename T> inline void flip(T &mask,int pos){mask=((mask)^(1LL<<pos));}
template<class T1> bool tk(T1 &e1){return(cin>>e1?true:false);}
template<class T1,class T2> bool tk(T1 &e1,T2 &e2){return(cin>>e1>>e2?true:false);}
template<class T1,class T2,class T3> bool tk(T1 &e1,T2 &e2,T3 &e3){return(cin>>e1>>e2>>e3?true:false);}
template<class T1,class T2,class T3,class T4> bool tk(T1 &e1,T2 &e2,T3 &e3,T4 &e4){return(cin>>e1>>e2>>e3>>e4?true:false);}
//*/
//int X[]={1,1,2,2,-1,-1,-2,-2},Y[]={2,-2,1,-1,2,-2,1,-1};
//int X[]={0,-1,-1,-1,0,1,1,1},Y[]={-1,-1,0,1,1,1,0,-1};
//int X[]={-1,0,1,0},Y[]={0,1,0,-1};

#define SZ 110
char s[SZ];
int DP[SZ][SZ];

int solve(int st, int en)
{
    if(st>en)return 0;
    int &ret = DP[st][en];
    if(ret)return ret;
    if(s[st]==s[en])return ret = solve(st+1,en-1);
    else return ret = min(solve(st+1,en),solve(st,en-1))+1;
}

int main()
{
    int tt,t=0,l;
    sf("%d",&tt);
    getchar();
    while(tt--)
    {
        memset(DP,0,sizeof(DP));
        gets(s);
        l = strlen(s)-1;
        pf("Case %d: %d\n",++t,solve(0,l));
    }
    return 0;
}
