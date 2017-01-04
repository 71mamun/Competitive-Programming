///In the name of Allah, the Most Gracious, the Most Merciful.
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long  ull;
typedef double dd;
typedef int I;
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
#define     degToRad(x)     (((1.0*(x)*PI)/180.0))
#define     radToDeg(x)     ((((x)*180.0)/(1.0*PI)))
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
template<class T1> void putv(vector<T1>e1){for(I i=0;i<sz(e1);i++)(!i?cout<<e1[i]:cout<<" "<<e1[i]);cout<<endl;}
template<class T1> void puta(T1 arr[],I l){for(I i=0;i<l;i++)(!i?cout<<arr[i]:cout<<" "<<arr[i]);cout<<endl;}
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
template<typename T> inline void setf(T &mask,I pos){mask=((mask)&(~(1LL<<pos)));}
template<typename T> inline void sett(T &mask,I pos){mask=((mask)|(1LL<<pos));}
template<typename T> inline void flip(T &mask,I pos){mask=((mask)^(1LL<<pos));}
template<class T1> bool tk(T1 &e1){return(cin>>e1?true:false);}
template<class T1,class T2> bool tk(T1 &e1,T2 &e2){return(cin>>e1>>e2?true:false);}
template<class T1,class T2,class T3> bool tk(T1 &e1,T2 &e2,T3 &e3){return(cin>>e1>>e2>>e3?true:false);}
template<class T1,class T2,class T3,class T4> bool tk(T1 &e1,T2 &e2,T3 &e3,T4 &e4){return(cin>>e1>>e2>>e3>>e4?true:false);}
/**/
//I X[]={1,1,2,2,-1,-1,-2,-2},Y[]={2,-2,1,-1,2,-2,1,-1};
//I X[]={0,-1,-1,-1,0,1,1,1},Y[]={-1,-1,0,1,1,1,0,-1};
//I X[]={-1,0,1,0},Y[]={0,1,0,-1};
///==================================================================================================================================
#define SZ 10005
struct tpl
{
    I u,v,w;
    tpl(){}
    tpl(I a,I b,I c){u=a,v=b,w=c;}
};

struct node
{
    I u,w;
    node(I a,I b){u=a;w=b;}
    bool operator<(const node&p)const{return w>p.w;}
};

vector<pii>G[SZ];
vector<pii>ed;
stack<tpl>S;
I n,e,q,d,com;
I l[SZ],t[SZ],cmpno[SZ],len[SZ],dis[SZ];

void calc_bcc(I u,I v)
{
    tpl now;
    I ccost=0,uu,vv,ww;
    ed.clear();

    while(!S.empty())
    {
        now = S.top();S.pop();
        uu=now.u,vv=now.v,ww=now.w;
        ccost+=ww;
        ed.pub(mp(uu,vv));
        if((u==uu and v==vv) or(u==vv and v==uu))break;
    }

    if(sz(ed)<=1) return;

    for(I i=0;i<sz(ed);++i)
    {
        uu=ed[i].fs,vv=ed[i].sc;
        cmpno[uu]=cmpno[vv]=com;
        len[uu]=len[vv]=ccost;
    }
    com++;
}

void bcc_dfs(I u,I p)
{
    l[u]=t[u]=++d;
    for(I i=0;i<sz(G[u]);++i)
    {
        I v=G[u][i].fs,w=G[u][i].sc;
        if(v==p)continue;
        if(!t[v])
        {
            S.push(tpl(u,v,w));
            bcc_dfs(v,u);
            l[u]=min(l[u],l[v]);
            if(l[v]>=t[u])
            {
                calc_bcc(u,v);
            }
        }
        else if(t[v]<t[u])
        {
            l[u]=min(l[u],t[v]);
            S.push(tpl(u,v,w));
        }
    }
}

void bcc(I n)
{
    d=0,com=1;
    mems(t,0);
    for(I i=1;i<=n;++i)
    {
        if(!t[i])
        {
            bcc_dfs(i,-1);
        }
    }
}

void dijsktra(I u)
{
    priority_queue<node>Q;
    mems(dis,msInf);
    dis[u] = 0;
    Q.push(node(u,dis[u]));
    while(!Q.empty())
    {
        node top = Q.top();
        Q.pop();
        I u = top.u;
        for(I i=0;i<sz(G[u]);++i)
        {
            I v = G[u][i].fs,w = G[u][i].sc;
            if(dis[v]>dis[u]+w)
            {
                dis[v]=dis[u]+w;
                Q.push(node(v,dis[v]));
            }
        }
    }
}

int main()
{
    int t=1;
    I u,v,w;
    while(tk(n,e))
    {
        while(!S.empty())S.pop();
        mems(len,0);
        for(I i=0;i<e;++i)
        {
            tk(u,v,w);
            G[u].pub(mp(v,w));
            G[v].pub(mp(u,w));
        }

        bcc(n);
        tk(q);
        while(q--)
        {
            tk(u,w);
            I ans = inf;
            dijsktra(u);
            for(I i=1;i<=n;++i)
            {
                ans = min(ans,(len[i]>=w?len[i]+2*dis[i]:inf));
            }
            put(ans>=inf?-1:ans);
        }
        for(I i=1;i<=n;++i)G[i].clear();
        t++;
    }
    return 0;
}

