#include<bits/stdc++.h>
using namespace std;
#define     ll                      long long
#define     ull                     unsigned long long
#define     mems(a,b)               memset(a,b,sizeof(a))
#define     mp                      make_pair
#define     pii                     pair<int,int>
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
#define     deb1(e1)                cout<<"\n"<<e1;
#define     deb2(e1,e2)             deb1(e1)cout<<" "<<e2;
#define     deb3(e1,e2,e3)          deb2(e1,e2)cout<<" "<<e3;
#define     deb4(e1,e2,e3,e4)       deb3(e1,e2,e3)cout<<" "<<e4;
#define     deb5(e1,e2,e3,e4,e5)    deb4(e1,e2,e3,e4)cout<<" "<<e5;
#define     deb6(e1,e2,e3,e4,e5,e6) deb5(e1,e2,e3,e4,e5)cout<<" "<<e6;
#define     putv(v)                 for(int i=0;i<sz(v);++i)(!i?cout<<v[i]:cout<<" "<<v[i]);cout<<endl;
#define     puta(arr,l)             for(int i=0; i<l; i++)(!i?cout<<arr[i]:cout<<" "<<arr[i]);cout<<endl;

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
int X[]= {-1,0,1,0},Y[]= {0,1,0,-1};
int R,C;
char grid[103][103];

const int INF = 2000000000;

struct Edge {
  int from, to, cap, flow, index;
  Edge(int from, int to, int cap, int flow, int index) :
    from(from), to(to), cap(cap), flow(flow), index(index) {}
};

struct Dinic
{
    int N;
    vector<vector<Edge> > G;
    vector<Edge *> dad;
    vector<int> Q;

    Dinic(int N) : N(N), G(N), dad(N), Q(N) {}

    void AddEdge(int from, int to, int cap)
    {
        G[from].push_back(Edge(from, to, cap, 0, G[to].size()));
        if (from == to) G[from].back().index++;
        G[to].push_back(Edge(to, from, 0, 0, G[from].size() - 1));
    }

    long long BlockingFlow(int s, int t)
    {
        fill(dad.begin(), dad.end(), (Edge *) NULL);
        dad[s] = &G[0][0] - 1;

        int head = 0, tail = 0;
        Q[tail++] = s;
        while (head < tail)
        {
            int x = Q[head++];
            for (int i = 0; i < G[x].size(); i++)
            {
                Edge &e = G[x][i];
                if (!dad[e.to] && e.cap - e.flow > 0)
                {
                    dad[e.to] = &G[x][i];
                    Q[tail++] = e.to;
                }
            }
        }
        if (!dad[t]) return 0;

        long long totflow = 0;
        for (int i = 0; i < G[t].size(); i++)
        {
            Edge *start = &G[G[t][i].to][G[t][i].index];
            int amt = INF;
            for (Edge *e = start; amt && e != dad[s]; e = dad[e->from])
            {
                if (!e)
                {
                    amt = 0;
                    break;
                }
                amt = min(amt, e->cap - e->flow);
            }
            if (amt == 0) continue;
            for (Edge *e = start; amt && e != dad[s]; e = dad[e->from])
            {
                e->flow += amt;
                G[e->to][e->index].flow -= amt;
            }
            totflow += amt;
        }
        return totflow;
    }

    long long GetMaxFlow(int s, int t)
    {
        long long totflow = 0;
        while (long long flow = BlockingFlow(s, t))
            totflow += flow;
        return totflow;
    }
};

int v(int r,int c)
{
    return r*C+(c+1);
}

int in(int x)
{
    return 2*x-1;
}

int out(int x)
{
    return 2*x;
}


int main()
{
    int T,t=1;
    cin>>T;
    while(T--)
    {
        int to_do=0;
        cin>>R>>C;
        Dinic dinic(2*R*C+1);
        For(i,1,R*C)
        {
            dinic.AddEdge(in(i),out(i),1);
            dinic.AddEdge(out(i),in(i),0);
        }
        For(i,0,R-1)
        {
            For(j,0,C-1)
            {
                sf(" %c",&grid[i][j]);
                if(grid[i][j]=='*')
                {
                    dinic.AddEdge(0,in(v(i,j)),1);
                    dinic.AddEdge(out(v(i,j)),0,0);
                    to_do++;
                }
                if(i==0||i==R-1||j==0||j==C-1)
                {
                    dinic.AddEdge(out(v(i,j)),R*C+1,1);
                    dinic.AddEdge(R*C+1,in(v(i,j)),0);
                }
                For(k,0,3)
                {
                    int nr = i+X[k];
                    int nc = j+Y[k];
                    if(nr<0||nc<0||nr>=R||nc>=C)continue;
                    dinic.AddEdge(out(v(i,j)),in(v(nr,nc)),1);
                    dinic.AddEdge(out(v(nr,nc)),in(v(i,j)),0);
                }
            }
        }
        int done = dinic.GetMaxFlow(0,R*C+1);
        pf("Case %d: ",t++);
        if(done>=to_do)pf("yes\n");
        else pf("no\n");
    }
    return 0;
}


/*


4 4
..**
.***
.***
..**




*/
