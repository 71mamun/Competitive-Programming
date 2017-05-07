#include<bits/stdc++.h>
using namespace std;
#define LM 1007
int n,m,k[LM];
int dp[LM][LM];
int optimal[LM][LM];

int sol(int l,int r)
{
    if(l+1>=r)
    {
        optimal[l][r] = l;
        return 0;
    }

    int &ans = dp[l][r];
    if(~ans)return ans;
    ans = 1e9;

    sol(l,r-1);
    sol(l+1,r);

    for(int i=optimal[l][r-1];i<=optimal[l+1][r];++i)
    {
        if(ans>sol(l,i)+sol(i,r)+(k[r]-k[l]))
        {
            ans = sol(l,i)+sol(i,r)+(k[r]-k[l]);
            optimal[l][r] = i;
        }
    }

    return ans;
}


int main()
{
    while(scanf("%d %d",&n,&m)==2)
    {
        memset(dp,-1,sizeof(dp));
        memset(optimal,0,sizeof(dp));
        for(int i=1;i<=m;++i)
        {
            scanf("%d",k+i);
        }

        k[0] = 0;
        k[m+1] = n;

        printf("%d\n",sol(0,m+1));

    }

    return 0;
}

/*
20 3
3 8 10
*/
