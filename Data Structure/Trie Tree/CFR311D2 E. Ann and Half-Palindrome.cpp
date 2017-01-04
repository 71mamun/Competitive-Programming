#include<bits/stdc++.h>
using namespace std;
#define     ll                      long long
#define     ull                     unsigned long long
#define     mem(a,b)                memset(a,b,sizeof(a))
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
#define LM 5003
#define charsetsize 3
#define maxWordLength LM
#define SZ 12500007

string str;
int dp[LM][LM];

int is_half_palindrome(int l,int r)
{
    if(l>=r)return 1;
    int &ret = dp[l][r];
    if(~ret) return ret;
    if(str[l]==str[r] && is_half_palindrome(l+2,r-2))return ret = 1;
    return ret = 0;
}

struct node
{
    int next[charsetsize];
    int endMark;
    int cunt;
    node()
    {
        for(int i=0;i<charsetsize;++i)next[i] = 0;
        endMark = 0;
        cunt = 0;
    }
};

node data[SZ];
int counter = 0;

void Insert(int l,int r)
{
    int curr = 0;
    for(int i=l;i<=r;++i)
    {
        int c = str[i]-'a';
        if(data[curr].next[c] == 0)
        {
            data[curr].next[c] = counter++;
        }

        curr = data[curr].next[c];
        if(is_half_palindrome(l,i))data[curr].cunt++;
    }
    data[curr].endMark++;
}

vector<char>print;

void print_dictionary(int curr)
{
    if(data[curr].endMark!=0)
    {
        putv(print);
    }
    for(int i=0;i<2;++i)
    {
        if(data[curr].next[i]==0)continue;
        print.pb(i+'a');
        print_dictionary(data[curr].next[i]);
        print.pop_back();
    }
}

int dfs(int curr)
{
    int ret = 0;
    for(int i=0;i<2;++i)
    {
        if(data[curr].next[i]==0)continue;
        ret+=dfs(data[curr].next[i]);
    }
    return data[curr].cunt += ret;
}

void initialize_trie()
{
    counter = 1;
}

void print_solution(int curr,int num)
{
    if(num<=0)return;
    int curr_has = data[curr].cunt;
    int left = (data[curr].next[0]?data[data[curr].next[0]].cunt:0);
    int right = (data[curr].next[1]?data[data[curr].next[1]].cunt:0);
    int has = curr_has - left - right;
    if(num<=has)return;
    num-=has;
    if(num<=left)
    {
        cout<<"a";
        print_solution(data[curr].next[0],num);
    }
    else
    {
        cout<<"b";
        print_solution(data[curr].next[1],num-left);
    }
}

int main()
{
    int m;
    initialize_trie();
    mem(dp,-1);
    cin>>str;
    for(int i = 0;i<sz(str);++i)
    {
        Insert(i,sz(str)-1);
    }
    cin>>m;
    dfs(0);
    print_solution(0,m);
    return 0;
}

