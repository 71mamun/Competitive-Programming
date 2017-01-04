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
#define LM 10007
vector<int>G[LM];

set<int>ap;
vector< pii >b;
int n,c[LM],l[LM],t[LM],d;

void dfs(int u,int p,int r)
{
    c[u]=0;
    int cnt =0;
    l[u]=t[u]=++d;
    int m = sz(G[u]);
    for(int i=0;i<m;i++)
    {
        int v = G[u][i];
        if(v==p)continue;
        if(c[v]==-1)
        {
            cnt++;
            dfs(v,u,r);
            l[u]=min(l[u],l[v]);
            if(l[v]>=t[u]&&u!=r)ap.insert(u);
            if(l[v]>t[u])b.pb(mp(min(u,v),max(u,v)));
        }
        else
        {
            l[u]=min(l[u],t[v]);
        }
    }
    if(u==r&&cnt>1)ap.insert(u);
}

pii capb()
{
    for(int i=0;i<=n;i++)c[i]=-1;
    ap.clear();
    b.clear();
    d=-1;
    for(int i=1;i<=n;i++)
    {
        if(c[i]==-1)
        {
            dfs(i,-1,i);
        }
    }
    return mp(sz(ap),sz(b));
}

map< pair<int,int>, int>edge;
map< pair<int,int>, int>frq;

int main()
{
    fread("bridges.in");
    fwrite("bridges.out");
    int m,u,v;
    cin>>n>>m;

    for(int i=0;i<m;++i)
    {
        cin>>u>>v;
        G[u].pb(v);
        G[v].pb(u);
        edge[mp(min(u,v),max(u,v))] = i;
        frq[mp(min(u,v),max(u,v))]++;
    }

    pii ans = capb();
    vector<pii>res;

    for(int i=0;i<b.size();++i)
    {
//        deb(b[i].fs,b[i].sc,frq[b[i]]);
        if(frq[b[i]]>1)continue;
        else res.pb(b[i]);
    }

    vector<int>ret;

    for(int i=0;i<res.size();++i)
    {
        ret.pb(edge[res[i]]+1);
    }

    sort(all(ret));

    cout<<ret.size()<<endl;
    for(int i=0;i<ret.size();++i)
    {
        if(i!=0)cout<<" ";
        cout<<ret[i];
    }
    cout<<endl;

    return 0;
}

/*

6 6
1 2
2 3
2 4
5 4
1 3
3 6



*/
