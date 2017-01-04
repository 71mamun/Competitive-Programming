#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define LM 92690
#define For(i,a,b) for(ll i=a;i<=b;++i)
#define mem(a,b) memset(a,b,sizeof(a))
#define pf printf
#define sf scanf


bitset<LM>status;
ll primes[LM],base,power[LM];

ll seive()
{
    status.set();
    status.reset(0);
    status.reset(1);
    for(ll i=2;i<=sqrt(LM);++i)
    {
        if(status[i])
        {
            for(ll j=i;j*i<LM;++j)
            {
                status[i*j]=false;
            }
        }
    }
    ll idx=0;
    For(i,2,LM)
    {
        if(status[i])primes[idx++]=i;
    }
    return idx;
}

void prime_factor(ll n)
{
    base=0;
    ll i;
    for(i=0; primes[i]<=sqrt(n); i++)
    {
        while(n%primes[i]==0)
        {
            n/=primes[i];
            power[primes[i]]++;
        }
    }
    if(n>1)
    {
        base=n;
    }
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("wa.txt","w",stdout);
    ll tot_prime = seive(),t=1;
    ll T,n;
    sf("%lld",&T);
    while(T--)
    {
        sf("%lld",&n);
        mem(power,0);
        prime_factor(abs(n));
        ll ans = 0;
        if(base>1)
        {
            ans = 1;
        }
        For(i,0,tot_prime-1)
        {
            ans = __gcd(ans,power[i]);
        }

        if(n<0)
        {
            while(ans%2==0)
            {
                ans/=2;
            }
        }

        pf("Case %lld: %lld\n",t++,ans);
    }
    return 0;
}

