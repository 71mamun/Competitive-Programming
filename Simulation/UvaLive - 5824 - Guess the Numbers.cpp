#include<algorithm>
#include<sstream>
#include<iostream>
#include<iomanip>
#include<climits>
#include<cstring>
#include<cassert>
#include<utility>
#include<limits>
#include<cstdio>
#include<string>
#include<vector>
#include<bitset>
#include<stack>
#include<ctime>
#include<queue>
#include<cmath>
#include<map>
#include<set>
using namespace std;
typedef long long ll;
typedef unsigned long long  ull;
#define     mem(a,b)        memset(a,b,sizeof(a))
#define     mp              make_pair
#define     pii             pair<int,int>
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
//struct tuple{int f,s,t;tuple(){}tuple(int a,int b,int c){f=a,s=b,t=c;}};
//int cross_product(tuple a,tuple b){int v=a.f*(b.s-b.t)-a.s*(b.f-b.t)+a.t*(b.f-b.s);return (v==0?0:(v>0?+1:-1));}
//tuple make_vector(tuple s,tuple e){tuple a;a.f=e.f-s.f;a.s=e.s-s.s;a.t=e.t-s.t;return a;}
///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//template<typename T> inline bool isOn(T &mask,int pos){return((mask)&(1LL<<pos));}
//template<typename T> inline void setf(T &mask,int pos){mask=((mask)&(~(1LL<<pos)));}
//template<typename T> inline void sett(T &mask,int pos){mask=((mask)(1LL<<pos));}
//template<typename T> inline void flip(T &mask,int pos){mask=((mask)^(1LL<<pos));}
///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//double dtor(double x){return x*PI/180.0;}
//double rtod(double x){return x*180.0/PI;}
//double pdis(pii a,pii b){return sqrt((double)sqr(a.fs-b.fs)+sqr(a.sc-b.sc));}
//template<class T> double rAng(T a,T b,T c){return acos((double)(sqr(a)+sqr(b)-sqr(c))/(a*b*2));}
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
///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//ll bigMod(ll a,ll x,ll p){ll r=1;while(x>0){if(x%2!=0){r=(r*a)%p;}a=(a*a)%p;x=(x>>1);}return r;}
//ll modInverse(ll a, ll p){return bigMod(a,p-2,p);}
//ll extGcd(ll a,ll b,ll& x,ll& y){if(b==0){x=1;y=0;return a;}else{int g=extGcd(b,a%b,y,x);y-=a/b*x;return g;}}
template<class T> T sqr(T a){return a*a;}
template<class T> T pwr(T b, T p){T r=1,x=b;while(p){if(p&1)r*=x;x*=x;p=(p>>1);}return r;}
template<class T> T lcm(T a,T b){return(a/__gcd(a,b))*b;}
template<class T> void xswap (T &x,T &y){if(x!=y){x^=y;y^=x;x^=y;}}
///HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
#define LIM (100007)
#define MOD (1000000007)

vector<int>uv;
int n,tmp,res;
map<char,int>us;

stack<int>Snum;
stack<char>Sop;

int signValue(char op)
{
    if(op=='*')
        return 2;
    else if(op=='+'||op=='-')
        return 1;
    else if(op=='(')
        return 0;
}

int calculate(char op)
{
    int a=Snum.top();
    Snum.pop();
    int b=Snum.top();
    Snum.pop();
    if(op=='+')
        return b+a;
    if(op=='-')
        return b-a;
    if(op=='*')
        return b*a;
}

int simulate(string line)
{
    int idx = 0;
    line+=')';
    Sop.push('(');
    for(int i=0; i<line.size(); i++)
    {
        if(line[i]!=' ')
        {
            if(line[i]>='0'&&line[i]<='9')
            {
                Snum.push(line[i]-'0');
            }
            else if(line[i]>='a'&&line[i]<='z')
            {
                if(us[line[i]]==0)
                {
                    us[line[i]]=uv[idx];
                    idx++;
                }
                Snum.push(us[line[i]]);
            }

            else if(line[i]=='+'||line[i]=='*'||line[i]=='-'||line[i]=='(')
            {
                char preop=Sop.top();
                if(signValue(preop)>=signValue(line[i])&&line[i]!='(')
                {
                    int value=calculate(preop);
                    Snum.push(value);
                    Sop.pop();
                    Sop.push(line[i]);
                }
                else Sop.push(line[i]);
            }
            else if(line[i]==')')
            {
                while(Sop.top()!='(')
                {
                    char nop=Sop.top();
                    int num=calculate(nop);
                    Snum.push(num);
                    Sop.pop();
                }
                Sop.pop();
            }
        }
    }
    return Snum.top();
}


int main()
{
    string line;
    while(tk(n))
    {
        if(n==0)
        {
            tk(tmp);
            if(tmp==0)break;
        }
        bool ok = false;
        uv.clear();
        For(i,0,n-1)
        {
            tk(tmp);
            uv.pub(tmp);
        }
        tk(res);
        tk(line);
        sort(all(uv));
        do
        {
            us.clear();
            int locRes = simulate(line);
//            put(locRes,res);
//            putv(uv);
            if(locRes==res)
            {
                put("YES");
                ok = true;
                break;
            }

        }while(next_permutation(uv.begin(),uv.end()));
        if(ok)continue;
        else put("NO");
    }
    return 0;
}



