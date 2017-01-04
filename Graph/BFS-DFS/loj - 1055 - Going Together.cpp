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
#define     sett(mask,pos)           ((mask)|(1LL<<pos))
#define     flip(mask,pos)          ((mask)^(1LL<<pos))
#define     debv(v)                 for(int i=0;i<sz(v);++i)(!i?cout<<v[i]:cout<<" "<<v[i]);cout<<endl;
#define     deba(arr,l)             for(int i=0; i<l; i++)(!i?cout<<arr[i]:cout<<" "<<arr[i]);cout<<endl;
#define     deb(a...)               {cerr<<"#line:"<<__LINE__<<" -> ";dbg,a; cerr<<endl;}
struct debugger { template<typename T> debugger& operator , (const T v) { cerr<<v<<" "; return *this; } } dbg;
///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//int X[]={1,1,2,2,-1,-1,-2,-2},Y[]={2,-2,1,-1,2,-2,1,-1};
//int X[]={0,-1,-1,-1,0,1,1,1},Y[]={-1,-1,0,1,1,1,0,-1};
int X[]={-1,0,1,0},Y[]={0,1,0,-1};
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
struct fast{fast(){ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);}}cincout;
///HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
int T,n,ar,br,cr,ac,bc,cc,t=1;
string g[11];
int dis[11][11][11][11][11][11];
int vis[11][11][11][11][11][11];

bool check(int ar,int ac,int br,int bc,int cr,int cc)
{
    return (g[ar][ac] == 'X') && (g[cr][cc] == 'X') && (g[br][bc] == 'X');
}

int bfs(int ar,int ac,int br,int bc,int cr,int cc)
{
    queue<int>q;
    vis[ar][ac][br][bc][cr][cc] = 1;
    q.push(ar);
    q.push(ac);
    q.push(br);
    q.push(bc);
    q.push(cr);
    q.push(cc);
    while(!q.empty())
    {
        ar = q.front();
        q.pop();
        ac = q.front();
        q.pop();
        br = q.front();
        q.pop();
        bc = q.front();
        q.pop();
        cr = q.front();
        q.pop();
        cc = q.front();
        q.pop();
        if(check(ar, ac, br, bc, cr, cc))
        {
//            deb("from here");
            return dis[ar][ac][br][bc][cr][cc];
        }
        for(int i=0;i<4;++i)
        {
            int nar = ar+X[i];
            int nbr = br+X[i];
            int ncr = cr+X[i];
            int nac = ac+Y[i];
            int nbc = bc+Y[i];
            int ncc = cc+Y[i];


            if(nar<0||nar>=n||nac<0||nac>=n||g[nar][nac]=='#')nar=ar,nac=ac;
            if(nbr<0||nbr>=n||nbc<0||nbc>=n||g[nbr][nbc]=='#')nbr=br,nbc=bc;
            if(ncr<0||ncr>=n||ncc<0||ncc>=n||g[ncr][ncc]=='#')ncr=cr,ncc=cc;

            if(nar==nbr&&nac==nbc)
            {
                nar = ar,nac = ac;
                nbr = br,nbc = bc;
                if((nar==ncr&&nac==ncc)||(nbr==ncr&&nbc==ncc))
                {
                    ncr = cr,ncc = cc;
                }
            }
            else if(nar==ncr&&nac==ncc)
            {
                nar = ar,nac = ac;
                ncr = cr,ncc = cc;
                if((nar==nbr&&nac==nbc)||(nbr==ncr&&nbc==ncc))
                {
                    nbr = br,nbc = bc;
                }
            }
            else if(ncr==nbr&&ncc==nbc)
            {
                ncr = cr,ncc = cc;
                nbr = br,nbc = bc;
                if((nar==nbr&&nac==nbc)||(nar==ncr&&nac==ncc))
                {
                    nar = ar,nac = ac;
                }
            }

            if(!vis[nar][nac][nbr][nbc][ncr][ncc])
            {
                vis[nar][nac][nbr][nbc][ncr][ncc] = 1;
                dis[nar][nac][nbr][nbc][ncr][ncc]=dis[ar][ac][br][bc][cr][cc]+1;
//                deb(nar, nac, nbr, nbc, ncr, ncc);
                q.push(nar);
                q.push(nac);
                q.push(nbr);
                q.push(nbc);
                q.push(ncr);
                q.push(ncc);
            }
        }
    }
    return -1;
}

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    cin>>T;
    while(T--)
    {
        mems(vis,0);
        mems(dis,0);
        for(int i = 0; i < 10; i++)
            g[i].clear();
        cin>>n;
        for(int i=0;i<n;++i)
        {
            cin>>g[i];
            for(int j=0;j<n;++j)
            {
                if(g[i][j]=='A')
                {
                    ar = i,ac = j;
                }
                else if(g[i][j]=='B')
                {
                    br = i,bc = j;
                }
                else if(g[i][j]=='C')
                {
                    cr = i,cc = j;
                }
            }
        }

        int res = bfs(ar,ac,br,bc,cr,cc);
        cout<<"Case "<<t++<<": ";
        if(res>-1)
        {
            cout<<res;
        }
        else
        {
            cout<<"trapped";
        }
        cout<<endl;

    }
    return 0;
}

/*
2
7
.....#.
.......
.#B....
...A.#.
.CX....
.X.X.#.
.#.....
3
ABC
###
XXX
*/
