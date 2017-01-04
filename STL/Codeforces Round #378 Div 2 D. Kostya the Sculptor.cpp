#include<bits/stdc++.h>
using namespace std;
#define     ll                      long long
#define     ull                     unsigned long long
#define     mems(a,b)               memset(a,b,sizeof(a))
#define     mp                      make_pair
#define     pii                     pair<int,int>
#define     pdd                     pair<double,double>
#define     fs                      first
#define     sc                      second
#define     VI                      vector<int>
#define     clr(a)                  a.clear()
#define     pb                      push_back
#define     eps                     1E-5
#define     sf                      scanf
#define     pf                      printf
#define     For(i,a,b)              for(int i=a;i<=b;++i)
#define     all(a)                  a.begin(),a.end()
#define     fread(name)             freopen(name,"r",stdin)
#define     fwrite(name)            freopen(name,"w",stdout)
#define     sz(a)                   (int)a.size()
#define     cone                    __builtin_popcountll
#define     fastIO                  ios_base::sync_with_stdio(false)
#define     cintie                  cin.tie(NULL)
#define     endl                    "\n"
#define     PI                      (acos(-1.0))
#define     linf                    (1LL<<62)
#define     inf                     (0x7f7f7f7f)
#define     sqr(a)                  ((a)*(a))
#define     lcm(a,b)                ({(a)/__gcd(a,b)*(b);})
#define     is_set(mask,pos)        ((mask)&(1LL<<pos))
#define     rset(mask,pos)          ((mask)&(~(1LL<<pos)))
#define     sett(mask,pos)          ((mask)|(1LL<<pos))
#define     flip(mask,pos)          ((mask)^(1LL<<pos))
#define     debv(v)                 for(int i=0;i<sz(v);++i)(!i?cout<<v[i]:cout<<" "<<v[i]);cout<<endl;
#define     deba(arr,l)             for(int i=0; i<l; i++)(!i?cout<<arr[i]:cout<<" "<<arr[i]);cout<<endl;
#define     deb(a...)               {cerr<<"#line:"<<__LINE__<<" -> ";dbg,a; cerr<<endl;}
struct debugger { template<typename T> debugger& operator , (const T v) { cerr<<v<<" "; return *this; } } dbg;
///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//int X[]={1,1,2,2,-1,-1,-2,-2},Y[]={2,-2,1,-1,2,-2,1,-1};
//int X[]={0,-1,-1,-1,0,1,1,1},Y[]={-1,-1,0,1,1,1,0,-1};
//int X[]={-1,0,1,0},Y[]={0,1,0,-1};
///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//int bigMod(int a,int x,int p){int r=1;while(x>0){if(x%2!=0){r=(r*a)%p;}a=(a*a)%p;x=(x>>1);}return r;}
//int modInverse(int a, int p){return bigMod(a,p-2,p);}
//int extGcd(int a,int b,ll& x,ll& y){if(b==0){x=1;y=0;return a;}else{int g=extGcd(b,a%b,y,x);y-=a/b*x;return g;}}
//template<class T> T pwr(T b, T p){T r=1,x=b;while(p){if(p&1)r*=x;x*=x;p=(p>>1);}return r;}
///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//struct triple{double f,s,t;triple() {} triple(double a,double b,double c){f=a,s=b,t=c;}};
//int cross_product(triple a,triple b){int v=a.f*(b.s-b.t)-a.s*(b.f-b.t)+a.t*(b.f-b.s);return (v==0?0:(v>0?+1:-1));}
//triple make_vector(triple s,triple e){triple a;a.f=e.f-s.f;a.s=e.s-s.s;a.t=e.t-s.t;return a;}
///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//double pdis(pdd a,pdd b){return sqrt((double)sqr(a.fs-b.fs)+sqr(a.sc-b.sc));}
//template<class T> double rAng(T a,T b,T c){double d=(sqr(a)+sqr(b)-sqr(c))/(a*b*2);d=(d<-1?-1:(d>1?1:d));return acos(d);}
///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//template<class T> string to_str(T n){ostringstream oss;oss<<n;oss.flush();return oss.str();}
//template<typename T>T str_to(const string& s){T d;istringstream(s) >> d;return d;}
///HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
int alls[100007][5];
map<pii,int>best;
map<pii,int>loc_best;
map<pii,int>sbest;
map<pii,int>loc_sbest;

int min(int a,int b,int c)
{
    return min(a,min(b,c));
}

set<pii>sob;

void make(int a,int b,int c,int i)
{
    int aa = min(a,b);
    int bb = max(a,b);
    a = aa;
    b = bb;
    if(loc_sbest[mp(a,b)]==i)return;
    if(loc_best[mp(a,b)]==i)return;
    sob.insert(mp(a,b));

    if(best.find(mp(a,b))==best.end())
    {
        best[mp(a,b)] = c;
        loc_best[mp(a,b)] = i;
    }
    else
    {
        if(best[mp(a,b)]<c)
        {
            sbest[mp(a,b)] = best[mp(a,b)];
            loc_sbest[mp(a,b)] = loc_best[mp(a,b)];
            best[mp(a,b)] = c;
            loc_best[mp(a,b)] = i;
        }
        else if(sbest[mp(a,b)]<c)
        {
            sbest[mp(a,b)] = c;
            loc_sbest[mp(a,b)] = i;
        }
    }
}

int main()
{
    int n,sr=-inf,si,dr = -inf,di1,di2;
    cin>>n;
    for(int i=0;i<n;++i)
    {
        cin>>alls[i][0]>>alls[i][1]>>alls[i][2];
        int tr = min(alls[i][0],alls[i][1],alls[i][2]);
        if(tr>sr)
        {
            sr = tr;
            si = i+1;
        }
    }

    for(int i=0;i<n;++i)
    {
        int a = alls[i][0];
        int b = alls[i][1];
        int c = alls[i][2];
        make(a,b,c,i+1);
        make(a,c,b,i+1);
        make(b,c,a,i+1);
    }

    for(auto i:sob)
    {
        if(best[i]==0||sbest[i]==0)continue;
        int tr = min(i.fs,i.sc,best[i]+sbest[i]);
        if(tr>dr)
        {
            dr = tr;
            di1 = loc_best[i];
            di2 = loc_sbest[i];
        }
    }

    if(sr>dr)
    {
        cout<<1<<endl;
        cout<<si<<endl;
    }
    else
    {
        cout<<2<<endl;
        cout<<di1<<" "<<di2<<endl;
    }

    return 0;
}

