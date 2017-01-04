#include <cstdio>
#include <map>
#include <utility>
#include <vector>
#include <iostream>
#include <cstring>
using namespace std;
#define ll long long
#define sf scanf
#define pf printf
#define ms(a,b) memset(a,b,sizeof(a))
#define mp make_pair
#define psb push_back
#define fs first
#define sc second
#define SZ(a) (int) a.size()

const int MAX = 1004000;
const ll MOD = 1000000007LL;
bool sieve[MAX];
ll prime[80000];
vector<pair<ll,ll> >info;
ll pre[MAX];

ll BigMod(ll B,ll P,ll M)
{
    ll R=1%M;
    while(P>0)
    {
        if(P%2==1)
        {
            R=(R*B)%M;
        }
        P/=2;
        B=(B*B)%M;
    }
    return R;
}

void Sieve()
{
    int i,j,k=0,r;
    prime[k++]=2LL;
    for(i=3; i<MAX; i+=2)
    {
        if(sieve[i]==false)
        {
            prime[k++]=(ll) i;
            if(i<MAX/i)
            {
                r=(i<<1);
                for(j=i*i; j<MAX; j+=r)
                {
                    sieve[j]=true;
                }
            }
        }
    }
    return ;
}

void primeFact(ll N)
{
    int i;
    ll p,cnt;
    info.clear();
    for(i=0; prime[i]*prime[i]<=N; i++)
    {
        if(N%prime[i]==0)
        {
            p=prime[i];
            cnt=0LL;
            while(N%prime[i]==0)
            {
                cnt++;
                N/=prime[i];
            }
            info.psb(mp(p,cnt+1LL));
        }
    }
    if(N>1LL)
    {
        info.psb(mp(N,2LL));
    }
    return ;
}

ll solution(ll R,bool mark)
{
    ll p,cur,prv,INV;
    for(int i=0; i<SZ(info); i++)
    {
        p=info[i].fs;
        cur = info[i].sc;
        prv = pre[p];
        if(prv)
        {
            if(mark)
            {
                cur = prv+cur-1LL;
            }
            else
            {
                cur = (prv-cur)+1LL;
            }
            INV = BigMod(prv,MOD-2,MOD);
            R = (R*INV)%MOD;
            R = (R*cur)%MOD;
        }
        else
        {
            cur = info[i].sc;
            R = (R*cur)%MOD;
        }
        pre[p] = cur;
    }
    return R;
}

int main()
{
    Sieve();
    bool mark;
    int T,t=1,N;
    ll v,R,sol;
    sf("%d",&T);
    while(T--)
    {
        sol=0LL;
        R=1LL;
        ms(pre,0LL);
        sf("%d",&N);
        while(N--)
        {
            sf("%lld",&v);
            if(v<0)
            {
                mark = false;
                v=-v;
            }
            else mark = true;
            primeFact(v);
            for(int i=0;i<SZ(info);++i)
            {
                cout<<info[i].fs<<" "<<info[i].sc<<endl;
            }
            R=solution(R,mark);
            sol = (sol+R)%MOD;
        }
        pf("Case %d: %lld\n",t++,sol);
    }
    return 0;
}
