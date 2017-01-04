.edu#include<bits/stdc++.h>
using namespace std;
#define sf scanf
#define pf printf
#define mod (1000000007)
#define For(i,a,b) for(int i=1;i<=b;++i)
#define inf 2005
int n,k;
int dp[2007][2007];
int ok[2007][2007];
int sub(int pre,int pos)
{
    if(pos>k)return 1;
    if(ok[pre][pos])return dp[pre][pos];
    ok[pre][pos]=1;
    dp[pre][pos]=0;
    /// vitore n loop ghuraitesilam so O(n^3) hoitesilo
    /// so TLE Khaisilam.
    for(int i=pre;i<=n;i+=pre)
    {
        dp[pre][pos]+=sub(i,pos+1);
        dp[pre][pos]%=mod;
    }
    return dp[pre][pos];
}

int main()
{
    sf("%d %d",&n,&k);
    pf("%d\n",sub(1,1));
    return 0;
}
