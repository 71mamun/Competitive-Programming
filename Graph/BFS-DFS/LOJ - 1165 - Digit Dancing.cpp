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
struct debugger
{
    template<typename T> debugger& operator, (const T v)
    {
        cerr<<v<<" ";
        return *this;
    }
} dbg;
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
#define LM 10
#define MLM 322600
#define CHRSZ 10
int pola[LM];
int dis[MLM];
VI done;
VI List[MLM];

struct node
{
    int next[CHRSZ];
    int endMark;
    node()
    {
        for(int i = 0; i<CHRSZ; i++)next[i] = 0;
        endMark = 0;
    }
};
node data[MLM];

int counter = 1;

void Insert(VI a)
{
    int cur = 0;
    for(int i=0;i<sz(a);++i)
    {
        int now = a[i];
        if(data[cur].next[now]==0)
        {
            data[cur].next[now] = ++counter;
        }
        cur = data[cur].next[now];
    }
}

int Search(VI a)
{
    int cur = 0;
    for(int i=0; i<sz(a); i++)
    {
        int now = a[i];
        cur = data[cur].next[now];
    }
    return cur;
}

bool is_prime(int n)
{
    for(int i=2; i*i<=n; ++i)
    {
        if(n%i==0)return 0;
    }
    return 1;
}

void print(VI a,VI b)
{
    for(int i=0; i<sz(a); ++i)
    {
        cout<<a[i]<<" ";
    }
    cout<<" -> ";
    for(int i=0; i<sz(b); ++i)
    {
        cout<<b[i]<<" ";
    }
    cout<<"\n";

}

int bfs(VI now)
{
    int n = sz(now);
    int idx = Search(now);
    dis[idx] = 0;
    queue< int >q;
    q.push(idx);
    while(!q.empty())
    {
        int now_idx = q.front();
        q.pop();
        VI now = List[now_idx];
        VI next;
        for(int i=0; i<n; ++i)
        {
            for(int j=0; j<n; ++j)
            {
                if(pola[now[i]]!=pola[now[j]]&&is_prime(now[i]+now[j])&&i!=j)
                {
                    if(i>j)
                    {
                        int temp = now[i];
                        next = now;
                        next.erase(next.begin()+i);
                        next.insert(next.begin()+j,temp);
                        int next_idx = Search(next);
                        if(dis[next_idx]>dis[now_idx]+1)
                        {
                            dis[next_idx] = dis[now_idx]+1;
                            q.push(next_idx);
                        }
                        next = now;
                        next.erase(next.begin()+i);
                        next.insert(next.begin()+j+1,temp);
                        next_idx = Search(next);
                        if(dis[next_idx]>dis[now_idx]+1)
                        {
                            dis[next_idx] = dis[now_idx]+1;
                            q.push(next_idx);
                        }
                    }
                    else
                    {
                        int temp = now[i];
                        next = now;
                        next.erase(next.begin()+i);
                        next.insert(next.begin()+j,temp);
                        int next_idx = Search(next);
                        if(dis[next_idx]>dis[now_idx]+1)
                        {
                            dis[next_idx] = dis[now_idx]+1;
                            q.push(next_idx);
                        }
                        next = now;
                        next.erase(next.begin()+i);
                        next.insert(next.begin()+j-1,temp);
                        next_idx = Search(next);
                        if(dis[next_idx]>dis[now_idx]+1)
                        {
                            dis[next_idx] = dis[now_idx]+1;
                            q.push(next_idx);
                        }
                    }
                }
            }
        }
    }
    return dis[Search(done)];
}

int main()
{
    for(int i=1; i<=8; ++i)
    {
        done.pb(i);
    }

    VI temp = done;

    do
    {
        Insert(temp);
        int idx = Search(temp);
        List[idx] = temp;
    }while(next_permutation(temp.begin(),temp.end()));

    int T,n,t=1;
    cin>>T;
    while(T--)
    {
        mems(dis,inf);
        mems(pola,0);
        VI now;
        for(int i=0; i<8; ++i)
        {
            cin>>n;
            if(n>0)
            {
                pola[n] = 1;
                n=-n;
            }
            now.pb(-n);
        }
        int ans = bfs(now);
        pf("Case %d: %d\n",t++,(ans<inf/2?ans:-1));
    }
    return 0;
}
