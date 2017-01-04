#include<bits/stdc++.h>
#define mod 100009
using namespace std;
char line[2007];
int dp[500][2007],len;
int sol(int pre,int now)
{
    if(now>=len)return 1;
    int &ans = dp[pre][now];
    if(~ans)return ans;
    ans = 0;
    if(pre!=line[now]-'a')ans+=sol(line[now]-'a',now+1);
    ans%=mod;
    ans+=sol(pre,now+1);
    ans%=mod;
    return ans%=mod;;
}


int main()
{
    int T,t=1;
    scanf("%d",&T);
    while(T--)
    {
        memset(dp,-1,sizeof(dp));
        scanf("%s",line);
        len = strlen(line);
        printf("Case %d: %d\n",t++,sol(450,0));
    }
    return 0;
}
