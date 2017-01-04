#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long  ull;
#define     mem(a,b)        memset(a,b,sizeof(a))
#define     mp              make_pair
#define     pii             pair<int,int>
#define     fs              first
#define     sc              second
#define     VI              vector<ull>
#define     clr(a)          a.clear()
#define     pob             pop_back
#define     pub             push_back
#define     eps             1E-5
#define     sf              scanf
#define     pf              printf
#define     all(a)          a.begin(),a.end()
#define     allr(a)         a.rbegin(),a.rend()
#define     full(a,l)       a,a+l
#define     fread(name)     freopen(name,"r",stdin)
#define     fwrite(name)    freopen(name,"w",stdout)
#define     sz(a)           (ll)a.size()
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
ull bigMod(ull a,ull x,ull p){ull r=1;while(x>0){if(x%2!=0){r=(r*a)%p;}a=(a*a)%p;x=(x>>1);}return r;}
//ll modInverse(ll a, ll p){return bigMod(a,p-2,p);}
//ll extGcd(ll a,ll b,ll& x,ll& y){if(b==0){x=1;y=0;return a;}else{int g=extGcd(b,a%b,y,x);y-=a/b*x;return g;}}
template<class T> T pwr(T b, T p){T r=1,x=b;while(p){if(p&1)r*=x;x*=x;p=(p>>1);}return r;}
template<class T> T lcm(T a,T b){return(a/__gcd(a,b))*b;}
template<class T> T sqr(T a){return a*a;}
template<class T> void xswap (T &x,T &y){if(x!=y){x^=y;y^=x;x^=y;}}
///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
struct triple{double f,s,t;triple(){}triple(double a,double b,double c){f=a,s=b,t=c;}};
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
template<class T1> void putv(vector<T1>e1){for(int i=0;i<sz(e1);i++)(!i?cout<<e1[i]:cout<<" "<<e1[i]);cout<<endl;}
template<class T1> void puta(T1 arr[],int l){for(int i=0;i<l;i++)(!i?cout<<arr[i]:cout<<" "<<arr[i]);cout<<endl;}
///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
template<class T1> bool tk(T1 &e1){return(cin>>e1?true:false);}
template<class T1,class T2> bool tk(T1 &e1,T2 &e2){return(cin>>e1>>e2?true:false);}
template<class T1,class T2,class T3> bool tk(T1 &e1,T2 &e2,T3 &e3){return(cin>>e1>>e2>>e3?true:false);}
template<class T1,class T2,class T3,class T4> bool tk(T1 &e1,T2 &e2,T3 &e3,T4 &e4){return(cin>>e1>>e2>>e3>>e4?true:false);}
///HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
#define LM 5000
char ndl[LM][LM],hay[LM][LM];
ull b1 = 29LLU,b2 = 31LLU;
ull b3 = 11LLU,b4 = 7LLU;
ull x,y,n,m;

ull Hash(char s[LM][LM],ull r,ull c,ull b)
{
    VI cc;
    For(i,0,r-1)
    {
        ull hv = 0LLU;
        For(j,0,c-1)
        {
            hv = hv*b+s[i][j];
        }
        cc.pub(hv);
    }
    ull hv = 0LLU;
    For(i,0,sz(cc)-1)
    {
        hv = hv*b+cc[i];
    }
    return hv;
}

void solve()
{
    ull nv1 = Hash(ndl,x,y,b1);
    ull nv2 = Hash(ndl,x,y,b2);
    ull nv3 = Hash(ndl,x,y,b3);
    ull nv4 = Hash(ndl,x,y,b4);
    ull r1,r2,r3,r4;
    r1 = r2 = r3 = r4 = 1LLU;
    For(i,0,y-2)
    {
        r1*=b1;
        r2*=b2;
        r3*=b3;
        r4*=b4;
    }

    VI mat1[LM],mat2[LM],mat3[LM],mat4[LM];
    ull hv1,hv2,hv3,hv4;

    For(i,0,n-1)
    {
        hv1 = hv2 = hv3 = hv4 = 0LLU;
        For(j,0,m-1)
        {
            if(j<y)
            {
                hv1 = hv1*b1+hay[i][j];
                hv2 = hv2*b2+hay[i][j];
                hv3 = hv3*b3+hay[i][j];
                hv4 = hv4*b4+hay[i][j];
                if(j==y-1)
                {
                    mat1[i].pub(hv1);
                    mat2[i].pub(hv2);
                    mat3[i].pub(hv3);
                    mat4[i].pub(hv4);
                }
            }
            else
            {
                hv1 = hv1-r1*hay[i][j-y];
                hv2 = hv2-r2*hay[i][j-y];
                hv3 = hv3-r3*hay[i][j-y];
                hv4 = hv4-r4*hay[i][j-y];
                hv1 = hv1*b1+hay[i][j];
                hv2 = hv2*b2+hay[i][j];
                hv3 = hv3*b3+hay[i][j];
                hv4 = hv4*b4+hay[i][j];
                mat1[i].pub(hv1);
                mat2[i].pub(hv2);
                mat3[i].pub(hv3);
                mat4[i].pub(hv4);
            }
        }
    }

    r1 = r2 = r3 = r4 = 1LLU;
    For(i,0,x-2)
    {
        r1*=b1;
        r2*=b2;
        r3*=b3;
        r4*=b4;
    }
//    cout<<r1<<" see"<<endl;

    VI fmt1[LM],fmt2[LM],fmt3[LM],fmt4[LM];

    For(j,0,sz(mat1[0])-1)
    {
        hv1 = hv2 = hv3 = hv4 = 0LLU;
        For(i,0,n-1)
        {
            if(i<x)
            {
                hv1 = hv1*b1+mat1[i][j];
                hv2 = hv2*b2+mat2[i][j];
                hv3 = hv3*b3+mat3[i][j];
                hv4 = hv4*b4+mat4[i][j];
                if(i==x-1)
                {
                    fmt1[i-x+1].pub(hv1);
                    fmt2[i-x+1].pub(hv2);
                    fmt3[i-x+1].pub(hv3);
                    fmt4[i-x+1].pub(hv4);
                }
            }
            else
            {
                hv1 = hv1-r1*mat1[i-x][j];
                hv2 = hv2-r2*mat2[i-x][j];
                hv3 = hv3-r3*mat3[i-x][j];
                hv4 = hv4-r4*mat4[i-x][j];
                hv1 = hv1*b1+mat1[i][j];
                hv2 = hv2*b2+mat2[i][j];
                hv3 = hv3*b3+mat3[i][j];
                hv4 = hv4*b4+mat4[i][j];
                fmt1[i-x+1].pub(hv1);
                fmt2[i-x+1].pub(hv2);
                fmt3[i-x+1].pub(hv3);
                fmt4[i-x+1].pub(hv4);
            }
        }
    }

    ull ans = 0;
//    cout<<nv1<<endl;
    For(i,0,n-x)
    {
        For(j,0,m-y)
        {
//            cout<<fmt1[i][j]<<" ";
            if(fmt1[i][j]==nv1&&fmt2[i][j]==nv2&&fmt3[i][j]==nv3&&fmt4[i][j]==nv4)
            {
                pf("(%d,%d)\n",i+1,j+1);
                ans++;
            }
        }
//        cout<<endl;
    }
    if(ans==0)pf("NO MATCH FOUND...\n");
}

int main()
{
    char ch;
//    fread("in.txt");
    sf("%llu %llu",&x,&y);
    For(i,0,x-1)
    {
        For(j,0,y-1)
        {
            sf(" %c",&ch);
            ndl[i][j] = ch-'a';
        }
    }
    sf("%llu %llu",&n,&m);
    For(i,0,n-1)
    {
        For(j,0,m-1)
        {
            sf(" %c",&ch);
            hay[i][j] = ch-'a';
        }
    }

    solve();

    return 0;
}


/*

2 2
bc
cd
3 3
abc
bcd
cde



*/
