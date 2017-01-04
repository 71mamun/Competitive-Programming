#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long  ull;
#define     mem(a,b)        memset(a,b,sizeof(a))
#define     mp              make_pair
#define     pii             pair<ll,ll>
#define     fs              first
#define     sc              second
#define     VI              vector<ll>
#define     clr(a)          a.clear()
#define     pob             pop_back
#define     pb              push_back
#define     eps             1E-5
#define     sf              scanf
#define     pf              printf
#define     all(a)          a.begin(),a.end()
#define     allr(a)         a.rbegin(),a.rend()
#define     full(a,l)       a,a+l
#define     fread(name)     freopen(name,"r",stdin)
#define     fwrite(name)    freopen(name,"w",stdout)
#define     sz(a)           (int)a.size()
#define     count_one       __builtin_popcount
#define     count_onell     __builtin_popcountll
#define     fastIO          ios_base::sync_with_stdio(false)
#define     PI              (acos(-1.0))
#define     linf            (1LL<<62)//>4e18
#define     inf             (0x7f7f7f7f)//>2e9
#define     fore(x,i)       for(typeof((x).begin()) i=(x.begin()); i!=(x).end(); ++i)
#define     rfore(x,i)      for(typeof((x).rbegin()) i=(x.rbegin()); i!=(x).rend(); ++i)
#define     For(i,a,b)      for(int i=a;i<=b;++i)
#define     rFor(i,a,b)     for(int i=a;i>=b;--i)
///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//int X[]={1,1,2,2,-1,-1,-2,-2},Y[]={2,-2,1,-1,2,-2,1,-1};
//int X[]={0,-1,-1,-1,0,1,1,1},Y[]={-1,-1,0,1,1,1,0,-1};
//int X[]={-1,0,1,0},Y[]={0,1,0,-1};
///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
ll bigMod(ll a,ll x,ll p){ll r=1;while(x>0){if(x%2!=0){r=(r*a)%p;}a=(a*a)%p;x=(x>>1);}return r;}
//ll modInverse(ll a, ll p){return bigMod(a,p-2,p);}
//ll extGcd(ll a,ll b,ll& x,ll& y){if(b==0){x=1;y=0;return a;}else{int g=extGcd(b,a%b,y,x);y-=a/b*x;return g;}}
template<class T> T pwr(T b, T p){T r=1,x=b;while(p){if(p&1)r*=x;x*=x;p=(p>>1);}return r;}
template<class T> T lcm(T a,T b){return(a/__gcd(a,b))*b;}
template<class T> T sqr(T a){return a*a;}
template<class T> void xswap (T &x,T &y){if(x!=y){x^=y;y^=x;x^=y;}}
///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
struct triple{double f,s,t;triple() {} triple(double a,double b,double c){f=a,s=b,t=c;}};
//int cross_product(triple a,triple b){int v=a.f*(b.s-b.t)-a.s*(b.f-b.t)+a.t*(b.f-b.s);return (v==0?0:(v>0?+1:-1));}
//triple make_vector(triple s,triple e){triple a;a.f=e.f-s.f;a.s=e.s-s.s;a.t=e.t-s.t;return a;}
///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
template<typename T> inline bool isOn(T &mask,int pos){return((mask)&(1LL<<pos));}
template<typename T> inline T setf(T mask,int pos){return mask=((mask)&(~(1LL<<pos)));}
template<typename T> inline T sett(T mask,int pos){return mask=((mask)|(1LL<<pos));}
template<typename T> inline T flip(T mask,int pos){return mask=((mask)^(1LL<<pos));}
///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//double dtor(double x){return x*PI/180.0;}
//double rtod(double x){return x*180.0/PI;}
//double pdis(pdd a,pdd b){return sqrt((double)sqr(a.fs-b.fs)+sqr(a.sc-b.sc));}
//template<class T> double rAng(T a,T b,T c){double d=(sqr(a)+sqr(b)-sqr(c))/(a*b*2);d=(d<-1?-1:(d>1?1:d));return acos(d);}
///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//template<class T> string to_string(T n){ostringstream oss;oss<<n;oss.flush();return oss.str();}
//int to_int(string s){int r=0;istringstream sin(s);sin>>r;return r;}
///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
template<class T1> void put(T1 e){cout<<e<<endl;}
template<class T1,class T2> void put(T1 e1,T2 e2){cout<<e1<<" "<<e2<<endl;}
template<class T1,class T2,class T3> void put(T1 e1,T2 e2,T3 e3){cout<<e1<<" "<<e2<<" "<<e3<<endl;}
template<class T1,class T2,class T3,class T4> void put(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;}
template<class T1,class T2,class T3,class T4,class T5> void put(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<endl;}
template<class T1> void putv(vector<T1>e1){for(int i=0; i<sz(e1); i++)(!i?cout<<e1[i]:cout<<" "<<e1[i]);cout<<endl;}
template<class T1> void puta(T1 arr[],int l){for(int i=0; i<l; i++)(!i?cout<<arr[i]:cout<<" "<<arr[i]);cout<<endl;}
///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
template<class T1> bool tk(T1 &e1){return(cin>>e1?true:false);}
template<class T1,class T2> bool tk(T1 &e1,T2 &e2){return(cin>>e1>>e2?true:false);}
template<class T1,class T2,class T3> bool tk(T1 &e1,T2 &e2,T3 &e3){return(cin>>e1>>e2>>e3?true:false);}
template<class T1,class T2,class T3,class T4> bool tk(T1 &e1,T2 &e2,T3 &e3,T4 &e4){return(cin>>e1>>e2>>e3>>e4?true:false);}
///HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
#define LM 50008
char a[LM],virus[LM];
int virus_len,a_len,lps[LM];/// virus_len = length of the virus, a_len = length of the string a.
int virus_end[LM],nxt_start[LM];/// virus_end = ending mark of virus, next_start = starting mark of virus.

void bff()
{
    int j;
    virus_len = strlen(virus);
    lps[0] = 0;
    For(i,1,virus_len-1)
    {
        j = lps[i-1];
        while(j>0&&virus[i]!=virus[j])
            j = lps[j-1];
        if(virus[i]==virus[j])++j;
        lps[i] = j;
    }
}

void kmp()
{
    mem(virus_end,0);
    mem(nxt_start,0);
    int j = 0;
    a_len = strlen(a);
    For(i,0,a_len-1)
    {
        while(j>0&&a[i]!=virus[j])
        {
            j = lps[j-1];
        }
        if(a[i]==virus[j])
        {
            ++j;
            if(j>=virus_len)
            {
                virus_end[i] = 1;
                j = lps[j-1];
            }
        }
    }
    rFor(i,a_len-1,0)
    {
        if(virus_end[i])
        {
            nxt_start[i-virus_len+1]=1;
        }
    }
    int last_virus_end = a_len;
    rFor(i,a_len-1,0)
    {
        if(nxt_start[i])
        {
            last_virus_end = i;
        }
        nxt_start[i] = last_virus_end;
    }
}

struct SuffixArray
{
    int sa[LM], lcp[LM], n;
    char cinp[LM];

    int w[LM], ta[LM], tb[LM];
    void sort(int *x, int *y, int m)
    {
        static int i ;
        for(i=0; i<m; i++) w[i] = 0;
        for(i=0; i<n; i++) w[x[y[i]]]++;
        for(i=1; i<m; i++) w[i] += w[i-1];
        for(i=n-1; i>=0; i--) sa[--w[x[y[i]]]] = y[i];
    }
    bool comp(int *r, int a, int b, int l)
    {
        if(r[a]==r[b])
        {
            if(a+l>=n || b+l>=n) return false;
            return r[a+l]==r[b+l];
        }
        return false;
    }
    void callcp()
    {
        int i, j, k;
        for(i=0; i<n; i++) ta[sa[i]] = i;
        for(i=0; i<n; i++)
        {
            if(ta[i]==0)
            {
                lcp[ta[i]] = 0;
                continue;
            }
            if(i==0 || lcp[ta[i-1]]<=1) k = 0;
            else k = lcp[ta[i-1]] - 1;
            while(cinp[sa[ta[i]-1]+k]==cinp[sa[ta[i]]+k]) k++;
            lcp[ta[i]] = k;
        }
    }
    void build_sa()
    {
        int i, k, m = 128, p;
        int *x = ta, *y = tb, *z;
        n = strlen(cinp);
        x[n] = 0;
        for(i=0; i<n; i++) x[i] = cinp[i], y[i] = i;
        sort(x,y,m);
        for(k=1, p=1; p<n; k*=2, m= p)
        {
            for(p=0, i=n-k; i<n; i++) y[p++] = i;
            for(i=0; i<n; i++)
            {
                if(sa[i]>=k)
                {
                    y[p++] = sa[i] - k;
                }
            }
            sort(x,y,m);
            z = x, x = y, y = z;
            for(i=1, p=1, x[sa[0]] =0; i<n; i++)
                x[sa[i]] = comp(y,sa[i-1],sa[i],k) ? p - 1: p++;
        }
    }
};


int main()
{
    int T,t=1;
    sf("%d",&T);

    SuffixArray sa;
    while(T--)
    {
        sf(" %s %s",a,virus);
        bff();/// building failure function of the virus
        kmp();/// building next starting position of virus after any position i as nxt_start[i]
        strcpy(sa.cinp,a);
        sa.build_sa();
        sa.callcp();
        int ans = 0,nxt_s,nxt_e,now,pmatc;
        For(i,0,a_len-1)
        {
            nxt_s = nxt_start[sa.sa[i]];
            nxt_e = nxt_s+virus_len-1;
            now = sa.sa[i];
            pmatc = sa.lcp[i];

            ans += max(0,(min(nxt_e,sa.n)-now)-pmatc);
            ///i can take the min of the ending of string a and virus ending position to count new distinct substrings.
        }
        pf("Case %d: %d\n",t++,ans);
    }
    return 0;
}

