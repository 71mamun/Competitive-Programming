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
#define     all(a)                  a.begin(),a.end()
#define     fread(name)             freopen(name,"r",stdin)
#define     fwrite(name)            freopen(name,"w",stdout)
#define     sz(a)                   (int)a.size()
#define     cone                    __builtin_popcountll
#define     fastIO                  ios_base::sync_with_stdio(false)
#define     cintie                  cin.tie(NULL)
#define     endl                    "\n";
#define     PI                      (acos(-1.0))
#define     linf                    (1LL<<62)
#define     inf                     (0x7f7f7f7f)
#define     fore(x,i)               for(typeof((x).begin()) i=(x.begin()); i!=(x).end(); ++i)
#define     rfore(x,i)              for(typeof((x).rbegin()) i=(x.rbegin()); i!=(x).rend(); ++i)
#define     For(i,a,b)              for(int i=a;i<=b;++i)
#define     rFor(i,a,b)             for(int i=a;i>=b;--i)
#define     cp(t)                   cout<<"Case "<<t<<": ";
#define     sqr(a)                  ((a)*(a))
#define     lcm(a,b)                ({(a)/__gcd(a,b)*(b);})
#define     is_set(mask,pos)        ((mask)&(1LL<<pos))
#define     rset(mask,pos)          ((mask)&(~(1LL<<pos)))
#define     set(mask,pos)           ((mask)|(1LL<<pos))
#define     flip(mask,pos)          ((mask)^(1LL<<pos))
#define     debv(v)                 for(int i=0;i<sz(v);++i)(!i?cout<<v[i]:cout<<" "<<v[i]);cout<<endl;
#define     deba(arr,l)             for(int i=0; i<l; i++)(!i?cout<<arr[i]:cout<<" "<<arr[i]);cout<<endl;
#define     deb(a...)               {cerr<<"#"<<__LINE__<<" -> ";dbg,a; cerr<<endl;}
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
//template<class T> string to_string(T n){ostringstream oss;oss<<n;oss.flush();return oss.str();}
//int to_int(string s){int r=0;istringstream sin(s);sin>>r;return r;}
///HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH


/*
 * Author : Bidhan Roy
 * Required Headers : <cstring>
 * Complexity : O (|E|√|V|)
 * 1 based indexing
 * If you find any bug contact me : mail2bidhan@gmail.com
 */

namespace hopcroftKarp{
    #define MAXN 100007 /// Maximum possible Number of nodes
    #define MAXE 1000007 /// Maximum possible Number of edges
    #define INF (1<<29)
    int ptr[MAXN],next[MAXE],zu[MAXE];
    int n,m,match[MAXN],D[MAXN],q[MAXN];
    void init(int _n){ /// initialization _n=number of nodes
        n=_n;
        m=0;
        memset(ptr,~0,sizeof(int)*(n+1));
        memset(match,0,sizeof(int)*(n+1));
    }
    void add_edge(int u,int v){ /// Adding edge between u and v
        next[m]=ptr[u];ptr[u]=m;zu[m]=v;++m;
    }
    bool bfs(){
        int u,v;
        register int i;
        int qh=0, qt=0;
        for(i=1; i<=n; i++){
            if(!match[i]){
                D[i]=0;
                q[qt++]=i;
            }
            else D[i]=INF;
        }
        D[0]=INF;
        while(qh<qt){
            u=q[qh++];
            if(u!=0){
                for(i=ptr[u]; ~i; i=next[i]){
                    v=zu[i];
                    if(D[match[v]]==INF){
                        D[match[v]]=D[u]+1;
                        q[qt++]=match[v];
                    }
                }
            }
        }
        return D[0]!=INF;
    }
    bool dfs(int u){
        int v;
        register int i;
        if(u){
            for(i=ptr[u]; ~i; i=next[i]){
                v=zu[i];
                if(D[match[v]]==D[u]+1){
                    if(dfs(match[v])){
                        match[v]=u;
                        match[u]=v;
                        return true;
                    }
                }
            }
            D[u]=INF;
            return false;
        }
        return true;
    }
    int run(){
        int matching=0;
        int i;
        while(bfs())
            for(i=1; i<=n; i++)
                if(!match[i] && dfs(i))
                    matching++;
        return matching;
    }
    #undef MAXN
    #undef INF
};

vector<pii>hor;
int width = 120;

int main()
{
//    fread("in.txt");
//    fwrite("wa.txt");
    int x,y,n,m;
    while(cin>>n>>m&&n+m)
    {
        int tot = n+m;hor.clear();
        hopcroftKarp::init(tot+7);
        for(int j=0;j<tot;++j)
        {
            cin>>x>>y;
            x++,y++;
            if(j<n)
            {
                hor.pb(mp(x*width+y,(x+1)*width+y));
            }
            else
            {
                int c1 = x*width+y;
                int c2 = (x)*width+(y+1);
                for(int i=0;i<hor.size();++i)
                {
                    if(c1==hor[i].fs||c1==hor[i].sc||c2==hor[i].fs||c2==hor[i].sc)
                    {
                        hopcroftKarp::add_edge(j,i);
                    }
                }
            }
        }
        cout<<tot-hopcroftKarp::run()<<endl;
    }
    return 0;
}
