///In the name of Allah, the Most Gracious, the Most Merciful.
#include "bits/stdc++.h"
using namespace std;
typedef long long I;
typedef long long ll;
typedef unsigned long long  ull;
typedef double dd;
#define     mems(a,b)       memset(a,b,sizeof(a))
#define     mp              make_pair
#define     pii             pair<I,I>
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
#define     degToRad(x)     (((1.0*(x)* PI)/180.0))
#define     radToDeg(x)     ((((x)*180.0)/(1.0 * PI)))
#define     PI              (acos(-1.0))
#define     MOD             (1000000007)
#define     llInf           (1LL<<62)
#define     msInf           (0x7f7f7f7f)
#define     inf             (1<<30)
#define     fore(x,i)       for(typeof((x).begin()) i=(x.begin()); i!=(x).end(); ++i)
#define     rfore(x,i)      for(typeof((x).rbegin()) i=(x.rbegin()); i!=(x).rend(); ++i)
///**
template<class T1> void put(T1 e){cout<<e<<endl;}
template<class T1,class T2> void put(T1 e1,T2 e2){cout<<e1<<" "<<e2<<endl;}
template<class T1,class T2,class T3> void put(T1 e1,T2 e2,T3 e3){cout<<e1<<" "<<e2<<" "<<e3<<endl;}
template<class T1,class T2,class T3,class T4> void put(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;}
template<class T1> void putVec(vector<T1>e1){for(I i=0;i<sz(e1);i++)(!i?cout<<e1[i]:cout<<" "<<e1[i]);cout<<endl;}
template<class T1> void putArr(T1 arr[],I l){for(I i=0;i<l;i++)(!i?cout<<arr[i]:cout<<" "<<arr[i]);cout<<endl;}
template<class T>void xSwap (T &x,T &y){if(x!=y){x^=y;y^=x;x^=y;}}
template<class T> T sqr(T a){return a*a;}
template<class T> dd rAng(T a,T b,T c){return acos((dd)(sqr(a)+sqr(b)-sqr(c))/(a*b*2));}
template<class T> T abs(T a){return(a<0?-a:a);}
template<class T> T lcm(T a,T b){return(a/__gcd(a,b))*b;}
template<class T> T pwr(T b, T p){T res=1,x=b;while(p){if(p&1)res*=x;x*=x;p=(p>>1);}return res;}
template<class T> string toString(T n){ostringstream oss;oss<<n;oss.flush();return oss.str();}
I toInt(string s){I r=0;istringstream sin(s);sin>>r;return r;}
dd pdis(pii a,pii b){return sqrt((dd)sqr(a.fs-b.fs)+sqr(a.sc-b.sc));}
ll extGcd(ll a,ll b,ll& x,ll& y){if(b==0){x=1;y=0;return a;}else{I g=extGcd(b,a%b,y,x);y-=a/b*x;return g;}}
ll bigMod(ll a,ll x,ll p){ll res=1;while(x>0){if(x%2!=0){res=(res*a)%p;}a=(a*a)%p;x=(x>>1);}return res;}
ll modInverse(ll a, ll p){return bigMod(a,p-2,p);}
template<typename T> inline bool isOn(T &mask,I pos){return((mask)&(1LL<<pos));}
template<typename T> inline void setOff(T &mask,I pos){mask=((mask)&(~(1LL<<pos)));}
template<typename T> inline void setOn(T &mask,I pos){mask=((mask)(1LL<<pos));}
template<typename T> inline void flip(T &mask,I pos){mask=((mask)^(1LL<<pos));}
template<class T1> bool tk(T1 &e1){if(cin>>e1)return true;return false;}
template<class T1,class T2> bool tk(T1 &e1,T2 &e2){if(cin>>e1>>e2)return true;return false;}
template<class T1,class T2,class T3> bool tk(T1 &e1,T2 &e2,T3 &e3){if(cin>>e1>>e2>>e3)return true;return false;}
/**/
//I X[]={1,1,2,2,-1,-1,-2,-2},Y[]={2,-2,1,-1,2,-2,1,-1};
//I X[]={0,-1,-1,-1,0,1,1,1},Y[]={-1,-1,0,1,1,1,0,-1};
//I X[]={-1,0,1,0},Y[]={0,1,0,-1};
///=============================================================================================================
I x,y;
string bsrc(I l,I h,I nth)
{
    while(true)
    {
        I m = (l+h)/2;
        if(l==h)
        {
            if(m%x==0 and m%y==0)return "Both";
            if(m%x==0) return "Vanya";
            else return "Vova";
        }
        I hv = m/x+m/y;
        if(hv<nth)l = m+1;
        else h = m;
    }
}

int main()
{
	//fwrite("out.txt");
	//fread("in.txt");
    I n,th;
    tk(n,x,y);
    I g = lcm(x,y);
    x=g/x,y=g/y;
    while(n--)
    {
        tk(th);
        put(bsrc(0LL,1000000000000000000LL,th));
    }
    return 0;
}
