#include<bits/stdc++.h>
using namespace std;
#define LM      100007
#define ll      long long
#define pb      push_back
#define fs      first
#define sc      second
#define sz(a)   (ll)a.size()
ll t,m,base[LM],pwr[LM];
ll f[LM],If[LM],flag[LM],cnt[LM];
const ll mod = 1000000007,phi_mod = mod-1;
vector< pair<ll,ll> >factor[LM];

ll big_mod(ll b,ll p,ll m)
{
    ll r=1;
    while(p>0)
    {
        if(p&1)
        {
            r = (r*b)%m;
        }
        p/=2;
        b=(b*b)%m;
    }
    return r;
}

void seive()
{
    ll v,c;
    factor[2].pb({2,1});
    for(ll i=4;i<LM;i+=2)
    {
        c = 0;
        v = i;
        while(!(v&1))
        {
            c++;
            v>>=1;
        }
        factor[i].pb({2,c});
        flag[i] = true;
    }

    for(ll i=3;i<LM;i+=2)
    {
        if(flag[i])continue;
        factor[i].pb({i,1});
        for(ll j=i+i;j<LM;j+=i)
        {
            c = 0;
            v = j;
            while(v%i==0)
            {
                v/=i;
                c++;
            }
            factor[j].pb({i,c});
            flag[j] = true;
        }
    }
}

void preprocess()
{
    f[0] = 1;
    If[0] = 1;
    for(ll i=1;i<LM;++i)
    {
        f[i] = (i*f[i-1])%mod;
        If[i] = big_mod(f[i],mod-2,mod);
    }

    seive();
}


ll ncr_mod(ll n,ll r)
{
    if(r<0||r>n)return 0;
    ll res = (f[n]*If[r])%mod;
    res = (res*If[n-r])%mod;
    return res;
}

ll ncr_phi_mod(ll n,ll r)
{
    if(r<0||r>n)return 0;
    memset(cnt,0,sizeof(cnt));
    for(ll i=n;i>n-r;--i)
    {
        for(ll j=0;j<sz(factor[i]);++j)
        {
            cnt[factor[i][j].fs] += factor[i][j].sc;
        }
    }

    for(ll i=2;i<=r;++i)
    {
        for(ll j=0;j<sz(factor[i]);++j)
        {
            cnt[factor[i][j].fs] -=factor[i][j].sc;
        }
    }


    ll res = 1;
    for(ll i=2;i<LM;++i)
    {
        if(cnt[i])
        {
            res = (res*big_mod(i,cnt[i],phi_mod))%phi_mod;
        }
    }
    return res;
}

int main()
{
    preprocess();
    scanf("%lld",&t);
    while(t--)
    {
        ll res = 1;
        scanf("%lld",&m);
        for(ll i=0;i<m;++i)
        {
            scanf("%lld %lld",base+i,pwr+i);
            res = (res*pwr[i])%mod;
        }

        ll len = ncr_mod(m,m/2);

        ll e = ncr_phi_mod(m-1,m/2-1);

        ll way = big_mod(res,e,mod);

        if(m&1)
        {
            e =  ncr_phi_mod(m-1,(m+1)/2-1);
            way = (way+big_mod(res,e,mod))%mod;
        }

        printf("%lld %lld\n",len,way);

    }
    return 0;
}


/*
1
6
2 3
3 9
5 4
7 1
11 2
13 2

20 23758833
*/
