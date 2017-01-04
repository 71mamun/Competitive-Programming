#include<stdio.h>
#define ll long long
#define sf scanf
#define pf printf
#define LM 30
ll dp[LM][LM];
int K,N;

ll solve(int r, int k)
{
    if(k==0)return 1;
    if(r==0)return 0;
    if(~dp[r][k])return dp[r][k];
    /**
        now available column = total column - ei row te boshanor por rooks bosano baki koyta
    */
    dp[r][k] =  (N-(k-1))*solve(r-1,k-1);
    return dp[r][k] += solve(r-1,k);
}

int main()
{
    int T,t=1,i,j;
    sf("%d",&T);
    while(T--)
    {
        sf("%d %d",&N,&K);
        pf("Case %d: ",t++);
        if(K>N)pf("0\n");
        else
        {
            for(i=1;i<=N;++i)for(j=1;j<=K;++j)dp[i][j]=-1;
            pf("%lld\n",solve(N,K));
        }
    }
    return 0;
}

