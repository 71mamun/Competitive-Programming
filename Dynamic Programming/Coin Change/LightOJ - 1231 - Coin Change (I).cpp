#include<cstdio>
#include<cstring>

using namespace std;

#define sf scanf
#define pf printf
#define ms(a,b) memset(a,b,sizeof(a))
#define printTestCase printf("Case %d: ",t++)
#define mod 100000007

int coin[53],totl[53];
int n,k;
int DP[53][1010];

int solve(int i,int amount)
{
    if(i>=n)
    {
        if(amount==0)return 1;
        return 0;
    }
    int &ret = DP[i][amount];
    if(ret!=-1)return ret;
    ret = 0;
    for(int j=0;j<=totl[i];j++)
    {
        if(amount-j*coin[i]>=0)ret+=(solve(i+1,amount-j*coin[i]))%mod;
    }
    return ret%=mod;
}


int main()
{
    int T,t=1;
    sf("%d",&T);
    while(T--)
    {
        ms(DP,-1);
        sf("%d %d",&n,&k);
        for(int i=0; i<n; i++)
        {
            sf("%d",&coin[i]);
        }
        for(int i=0; i<n; i++)
        {
            sf("%d",&totl[i]);
        }
        printTestCase;
        pf("%d\n",solve(0,k));
    }
    return 0;
}
