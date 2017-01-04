///In the name of Allah, the Most Gracious, the Most Merciful.
/********************
* Md. Mamun Hossain *
* SUST CSE 2011     *
********************/
#include<bits/stdc++.h>
using namespace std;
typedef long long I;
typedef unsigned long long  ull;
typedef double dd;
#define     mems(a,b)       memset(a,b,sizeof(a))
#define     IT              iterator
#define     mp              make_pair
#define     pii             pair<I,I>
#define     fs              first
#define     sc              second
#define     VI              vector<I>
#define     ST              set<I>
#define     SI              stack<I>
#define     QI              queue<I>
#define     clr(a)          a.clear()
#define     pob             pop_back
#define     pof             pop_front
#define     pub             push_back
#define     puf             push_front
#define     eps             1E-7
#define     all(a)          a.begin(),a.end()
#define     allr(a)         a.rbegin(),a.rend()
#define     bgn             begin
#define     full(a,l)       a,a+l
#define     fread(name)     freopen(name,"r",stdin);
#define     fwrite(name)    freopen(name,"w",stdout);
#define     sz(a)           a.size()
#define     count_one       __builtin_popcount
#define     count_onell     __builtin_popcountll
#define     fastIO          ios_base::sync_with_stdio(false)
#define     degToRad(x)     (((1.0*(x)* PI)/180.0))
#define     radToDeg(x)     ((((x)*180.0)/(1.0 * PI)))
#define     PI              (acos(-1.0))
#define     MOD             (1000000007)
#define     llInf           (1LL<<62)
#define     msInf           (0x7f7f7f7f)
#define     iInf            (1<<30)
#define     l_b(v,x)        lower_bound(v.begin(), v.end(), x)
#define     u_b(v,x)        upper_bound(v.begin(), v.end(), x)
#define     mine            min_element
#define     maxe            max_element
#define     fore(x,i)       for(typeof((x).begin()) i=(x.begin()); i!=(x).end(); ++i)
#define     rfore(x,i)      for(typeof((x).rbegin()) i=(x.rbegin()); i!=(x).rend(); ++i)
#define     has(c,e)        (c.find(e) != c.end())
#define     vhas(c,e)       (find(all(c),e) != c.end())
#define     rep(i,a,b)      for(I i=a; i<=b; ++i)
#define     repb(i,a)       for(I i=a;; ++i)
#define     repr(i,a,b)     for(I i=b; i>=a; --i)
#define     reprb(i,a)      for(I i=a;; --i)

///**
template<class T1> void put(T1 e){cout<<e<<endl;}
template<class T1,class T2> void put(T1 e1,T2 e2){cout<<e1<<" "<<e2<<endl;}
template<class T1,class T2,class T3> void put(T1 e1,T2 e2,T3 e3){cout<<e1<<" "<<e2<<" "<<e3<<endl;}
template<class T1> void putVec(vector<T1>e1){for(I i=0; i<sz(e1); i++)(!i?cout<<e1[i]:cout<<" "<<e1[i]);cout<<endl;}
template<class T1> void putArr(T1 arr[],I l){for(I i=0; i<l; i++)(!i?cout<<arr[i]:cout<<" "<<arr[i]);cout<<endl;}
template<class T>void xSwap (T &x, T &y){if(x!=y){x^=y;y^=x;x^=y;}}
template<class T> T sqr(T a){return a*a;}
template<class T> dd rAng(T a,T b,T c){return acos((dd)(sqr(a)+sqr(b)-sqr(c))/(a*b*2));}
template<class T> T abs(T a){return (a<0?-a:a);}
template<class T> T lcm(T a, T b){return (a/__gcd(a,b)) * b;}
template<class T> T pwr(T b, T p){T res=1,x=b;while(p){if(p&1)res*=x;x*=x;p=(p>>1);}return res;}
template<class T> string toString(T n){ostringstream oss;oss<<n;oss.flush();return oss.str();}
I toI(string s){I r=0;istringstream sin(s);sin>>r;return r;}
dd ppdis(pii a,pii b){return sqrt((dd)sqr(a.fs-b.fs)+sqr(a.sc-b.sc));}
I extGcd(I a, I b, I& x, I& y){if(b==0){x=1;y=0;return a;}else{I g=extGcd(b,a%b,y,x);y-=a/b*x;return g;}}
I bigMod(I a, I x, I p){I res=1;while(x>0){if(x%2!=0){res=(res*a)%p;}a=(a*a)%p;x=(x>>1);}return res;}
I modInverse(I a, I p){return bigMod(a, p-2, p);}
bool dsc(I a,I b){return a>b;}
template<typename T> inline bool isOn(T &mask,I pos){return ((mask)&(1LL<<pos));}
template<typename T> inline void setf(T &mask,I pos){mask = ((mask)&(~(1LL<<pos)));}
template<typename T> inline void sett(T &mask,I pos){mask = ((mask)(1LL<<pos));}
template<typename T> inline void flip(T &mask,I pos){mask = ((mask)^(1LL<<pos));}
template<class T1> bool tk(T1 &e1){if(cin>>e1)return true;return false;}
template<class T1,class T2> bool tk(T1 &e1,T2 &e2){if(cin>>e1>>e2)return true;return false;}
template<class T1,class T2,class T3> bool tk(T1 &e1,T2 &e2,T3 &e3){if(cin>>e1>>e2>>e3)return true;return false;}
/**/
//I X[]={1,1,2,2,-1,-1,-2,-2},Y[]={2,-2,1,-1,2,-2,1,-1};
//I X[]={0,-1,-1,-1,0,1,1,1},Y[]={-1,-1,0,1,1,1,0,-1};
I X[]={-1,0,1,0},Y[]={0,1,0,-1};
//=====================================================================================================================
#define SZ 50

vector<I>G[SZ*SZ];
char grd[SZ][SZ];
map<pii,I>m;
I par[SZ*SZ],tot_node;
bool c[SZ*SZ];

vector<I>bg[SZ*SZ],seta;
I set_col[SZ*SZ],bpm_col[SZ*SZ];

bool bpm_dfs(I u)
{

    if(bpm_col[u]!=-1LL)return false;
    bpm_col[u]=0LL;
    for(I i=0LL;i<bg[u].size();++i)
    {
        I v = bg[u][i];
        if(par[v]==-1LL or bpm_dfs(par[v]))
        {
            par[v]=u;
            return true;
        }
    }
    return false;
}

I max_bpm()
{
    memset(par,-1LL,sizeof(par));
    I cnt = 0LL;
    for(I i=0LL;i<seta.size();++i)
    {
        memset(bpm_col,-1LL,sizeof(bpm_col));
        if(bpm_dfs(seta[i]))cnt++;
    }
    return cnt;
}

void set_dfs(I u)
{
    tot_node++;
    for(I i=0LL;i<G[u].size();++i)
    {
        I v = G[u][i];
        if(set_col[v]==-1LL)
        {
            set_col[v]=set_col[u]^1LL;
            if(set_col[v]==0LL)seta.push_back(v),bg[v].push_back(u);
            else bg[u].push_back(v);
            set_dfs(v);
        }
        else
        {
            if(set_col[v]==1LL)bg[u].push_back(v);
            else bg[v].push_back(u);
        }
    }
}

I cal(I u,I n)
{
    tot_node = 0LL;
    seta.clear();
    for(I i=1LL;i<=n;++i)bg[i].clear();
    set_col[u]=0LL;
    seta.push_back(u);
    set_dfs(u);
    I ans = max_bpm();
    return tot_node-ans;
}

void init(I n)
{
    memset(set_col,-1LL,sizeof(set_col));
    for(I i=1LL;i<=n;++i)G[i].clear();
}

int main()
{
//    fread("input.txt");
//    fwrite("myout.txt");
    I T,r,c;
    tk(T);
    for(I t=1LL; t<=T; ++t)
    {
        I cnt=0LL;
        m.clear();
        tk(r,c);
        for(I i=0LL; i<r; ++i)
        {
            for(I j=0LL; j<c; ++j)
            {
                tk(grd[i][j]);
                if(grd[i][j]=='*')m[mp(i,j)] = ++cnt;
            }
        }

        init(cnt);

        for(I i=0LL; i<r; ++i)
        {
            for(I j=0LL; j<c; ++j)
            {
                if(grd[i][j]=='*')
                {
                    for(I k=0LL;k<4LL;++k)
                    {
                        I ii=i+X[k],jj=j+Y[k];
                        if(ii>=0LL and ii<r and jj>=0LL and jj<c and grd[ii][jj]=='*')
                        {
                            G[m[mp(i,j)]].pub(m[mp(ii,jj)]);
                        }
                    }
                }
            }
        }

        I ans = 0LL;
        for(I i=1LL;i<=cnt;++i)
        {
            if(set_col[i]==-1LL)ans+=cal(i,cnt);
        }

        printf("Case %lld: %lld\n",t,ans);

        for(I i=0LL;i<=cnt;++i)
        {
            G[i].clear();
        }
    }
    return 0;
}


/**

1
5 5
ooooo
oo***
*o**o
ooo*o
oo*oo



*/
