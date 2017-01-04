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
#define     pf              printf
#define     sf              scanf
#define     linf            (1LL<<62)
#define     For(i,a,b)      for(int i=a;i<=b;++i)
#define     rFor(i,a,b)     for(int i=a;i>=b;--i)
#define 	LM 				4000000
ll dp[LM];

int main()
{
    dp[0]=0;
    dp[1]=1;
    For(k,2,400000)
    {
        ll i = 1;
        ll &ans = dp[k];
        ans = linf;
        while(i*i*i<=k)
        {
            if(k-(i*i*i)<0)continue;
            ans = min(ans,dp[k-(i*i*i)]);
            i++;
        }
        ll j=0;
        i=1;
        while(j+i*i<=k)
        {
            if(k-(j+i*i)<0)continue;
            ans = min(ans,dp[k-(j+i*i)]);
            j+=(i*i);
            i++;
        }
        ans = ans+1;
    }
    ll n;
    while(sf("%lld",&n) and ~n)
    {
        pf("%lld\n",dp[n]);
    }
    return 0;
}
