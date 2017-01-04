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
//#define     is_set(mask,pos)        ((mask)&(1LL<<pos))
//#define     rset(mask,pos)          ((mask)&(~(1LL<<pos)))
//#define     sett(mask,pos)           ((mask)|(1LL<<pos))
//#define     flip(mask,pos)          ((mask)^(1LL<<pos))
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
//struct fast{fast(){ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);}}cincout;
///HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
///https://open.kattis.com/problems/magicallights
#define LM 300007
int n,q,par;
int col[LM],child[LM], parent[LM],level[LM];
VI g[LM];
bitset<103> tree[LM];
queue<int>qua;
bool col2[LM];

int qry(int i,int j)
{
    int s = 0;
    while(j>0)
    {
        s^=tree[j][i];
        j-=(j&(-j));
    }
    return s;
}

void up(int j,int i)
{
    while(j<=n)
    {
        tree[j].flip(i);
        j+=(j&(-j));
    }
}

vector<pii>marr;
pii gua[LM];

void bfs()
{
    while(!qua.empty())qua.pop();
    qua.push(1);
    clr(marr);
    col2[1]=1;
    int u,ba;
    gua[1]=mp(1,child[1]);
    int a,b,bc;
    while(!qua.empty())
    {
        u=qua.front();qua.pop();
        a=gua[u].fs;
        b=gua[u].sc;
        marr.pb(mp(a++,u));
        for(int i=0;i<sz(g[u]);i++)
        {
            ba=g[u][i];
            if(col2[ba])
            continue;
            qua.push(ba);
            col2[ba]=1;
            gua[ba]=mp(a,a+child[ba]-1);
            a+=child[ba];
        }
    }
}

queue<int>q2;
void bfs2()
{
    level[1] = 1;
    q2.push(1);
    while(!q2.empty())
    {
        int top = q2.front();
        q2.pop();
        for(int i=0;i<sz(g[top]);++i)
        {
            int v = g[top][i];
            level[v] = level[top]+1;
            q2.push(v);
        }
    }
}

vector<pii>node;

int main()
{
    int t = 1;
    fread("in.txt");
    fwrite("wa.txt");
    while(sf("%d %d",&n,&q)==2)
    {
        node.clear();
        for(int i=1;i<=n;++i)
        {
            col2[i]=0;
            child[i] = 1;
            g[i].clear();
            sf("%d",col+i);
        }
        for(int i=2;i<=n;++i)
        {
            sf("%d",&par);
            g[par].pb(i);
            parent[i] = par;
        }

        bfs2();

        for(int i=1;i<=n;++i)
        {
            node.pb(mp(-level[i],i));
        }

        sort(all(node));


        for(int i = 0; i < sz(node)-1; i++)
        {
            int bap = parent[node[i].sc];
            child[bap]+=child[node[i].sc];
        }

        bfs();

        for(int i=1;i<=n;++i)
        {
            up(gua[i].fs,col[i]);
        }

        int typ,idx;

        while(q--)
        {
            sf("%d %d",&typ,&idx);
            if(typ==0)
            {
                int ans = 0;
                for(int i=1;i<=100;++i)
                {
                    int loc=(qry(i,gua[idx].sc)^qry(i,gua[idx].fs-1));
                    ans+=loc;
                }
                pf("%d\n",ans);
            }
            else
            {
                up(gua[idx].fs,col[idx]);
                up(gua[idx].fs,typ);
                col[idx] = typ;
            }
        }

        for(int i=0; i<=n; ++i)
        {
            tree[i].reset();
        }
        t++;
    }
    return 0;
}

/*

7 7
1 2 2 1 1 2 1
5 7 1 1 5 1
0 1
0 2
0 3
0 4
0 5
0 6
0 7


9 8
2 3 1 2 3 1 3 1 2
8 8 8 8 7 1 1 8
1 3
0 3
1 8
0 7
3 7
0 1
2 3
0 8
*/

