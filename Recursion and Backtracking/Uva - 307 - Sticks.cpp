#include<cstdio>
#include<algorithm>
#include<cstring>
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
#define LM 70

int stk[LM],totlen,n,used[LM],len;

bool cmp(const int &a,const int &b)
{
    return a>b;
}

int sol(int stk_no,int tkn,int now_len)
{
    if(tkn==n)return 1;
    For(i,stk_no,n-1)
    {
        if(used[i])continue;
        if(stk[i]+now_len<len)
        {
            used[i] = 1;
            if(sol(i+1,tkn+1,now_len+stk[i]))return 1;
            used[i] = 0;
        }
        else if(stk[i]+now_len==len)
        {
            used[i] = 1;
            if(sol(0,tkn+1,0))return 1;
            used[i] = 0;
            return 0;
        }
        if(now_len==0)return 0;
    }
    return 0;
}

int main()
{
    while(sf("%d",&n)==1&&n)
    {
        totlen = 0;
        For(i,0,n-1)
        {
            sf("%d",&stk[i]);
            totlen+=stk[i];
        }
        sort(stk,stk+n,cmp);
        rFor(i,n,1)
        {
            if(totlen%i==0 && (totlen/i)>=stk[0])
            {
                len = totlen/i;
                mems(used,0);
                if(sol(0,0,0))
                {
                    pf("%d\n",len);
                    break;
                }
            }
        }
    }
    return 0;
}

