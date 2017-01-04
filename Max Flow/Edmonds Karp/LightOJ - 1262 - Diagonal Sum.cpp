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
#define     inf                     (1e9)
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

#define LM  1007
int mat[LM][LM];
int cunt_dg[LM];

struct edmonds_karp
{
    vector<int>adj[LM];
    int residual[LM][LM],par[LM],N,flow;

    edmonds_karp(int n)
    {
        mems(residual,0);
        For(i,0,n)clr(adj[i]);
    }

    void clear(int n)
    {
        mems(residual,0);
        For(i,0,n)clr(adj[i]);
    }

    void add_edge(int u,int v,int cap)
    {
        if(residual[u][v])
        {
            residual[u][v]+=cap;
            return;
        }
        adj[u].pb(v);
        adj[v].pb(u);
        residual[u][v] = cap;
    }


    bool augment_path(int source,int sink)
    {
        queue<int>Q;
        Q.push(source);
        mems(par,-1);
        while(!Q.empty())
        {
            int u = Q.front();
            Q.pop();
            For(i,0,sz(adj[u])-1)
            {
                int v = adj[u][i];
                if(par[v]==-1 and residual[u][v]>0)
                {
                    par[v]=u;
                    Q.push(v);
                    if(v==sink)return true;
                }
            }
        }
        return false;
    }

    void path_update(int v,int source)
    {
        int u = par[v];
        flow = min(flow,residual[u][v]);
        if(u!=source)path_update(u,source);
        residual[u][v]-=flow;
        residual[v][u]+=flow;
    }

    int max_flow(int source,int sink)
    {
        int tot_flow = 0;
        while(augment_path(source,sink))
        {
            flow = 1e9;
            path_update(sink,source);
            tot_flow+=flow;
        }
        return tot_flow;
    }
};

int main()
{
    int T,n,m,sum,t=1;
    edmonds_karp ek(LM);
    sf("%d",&T);
    while(T--)
    {
        sf("%d %d",&n,&m);
        int dn = n+m-1;
        ek.clear(n+m+dn);
        mems(cunt_dg,0);

        For(i,1,dn)
        {
            For(j,1+dn,n+m-1+dn)
            {
                int r = (i+j-dn-m-1);
                int c = (i-(j-dn)+m-1);
                if(r%2||c%2)continue;
                r/=2;
                c/=2;
                if(r<0||c<0||r>=n||c>=m)continue;
                cunt_dg[i]++;
                cunt_dg[j]++;
                ek.add_edge(i,j,99);
            }
        }

        For(i,1,dn)
        {
            sf("%d",&sum);
            ek.add_edge(0,i,sum-cunt_dg[i]);
        }
        For(j,1+dn,n+m-1+dn)
        {
            sf("%d",&sum);
            ek.add_edge(j,n+m+dn,sum-cunt_dg[j]);
        }


        int mxflw = ek.max_flow(0,n+m+dn);

        For(j,1+dn,n+m-1+dn)
        {
            For(i,1,dn)
            {
                int r = (i+j-dn-m-1);
                int c = (i-(j-dn)+m-1);
                if(r%2||c%2)continue;
                r/=2;
                c/=2;
                if(r<0||c<0||r>=n||c>=m)continue;
                mat[r][c] = ek.residual[j][i];
            }
        }

        pf("Case %d:\n",t++);
        For(i,0,n-1)
        {
            For(j,0,m-1)
            {
                if(j)pf(" %d",mat[i][j]+1);
                else pf("%d",mat[i][j]+1);
            }
            pf("\n");
        }
    }
    return 0;
}
