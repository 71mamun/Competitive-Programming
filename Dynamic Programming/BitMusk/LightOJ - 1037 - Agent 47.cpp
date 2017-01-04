#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<cstring>
#define LM 20
#define ll long long
using namespace std;
ll n;
ll life[LM];
ll hit[LM][LM];
const ll inf = (1LL<<61);
ll dp[65540];

ll sol(ll mask)
{
    if(__builtin_popcount(mask)==n)return 0;
    ll i,j;
    ll &ans = dp[mask];
    if(~ans) return ans;
    ans = inf;
    for(i=0;i<n;++i)
    {
        if(mask&(1LL<<i))
        {
            for(j=0;j<n;++j)
            {
                if(mask&(1LL<<j))continue;
                if(hit[i][j]==0)continue;
                ans = min(ans,(sol(mask|(1LL<<j))+(int)ceil(1.*life[j]/hit[i][j])));
            }
        }
        else
        {
            ans = min(ans,(sol(mask|(1LL<<i))+life[i]));
        }
    }
    return ans;
}

int main()
{
    ll T,i,j,t=1;
    char ch;
    scanf("%lld",&T);
    while(T--)
    {
        memset(dp,-1,sizeof(dp));
        scanf("%lld",&n);
        for(i=0;i<n;++i)
        {
            scanf("%lld",&life[i]);
        }
        for(i=0;i<n;++i)
        {
            for(j=0;j<n;j++)
            {
                scanf(" %c",&ch);
                hit[i][j] = ch-'0';
            }
        }
        printf("Case %lld: ",t++);
        printf("%lld\n",sol(0));
    }
    return 0;
}
