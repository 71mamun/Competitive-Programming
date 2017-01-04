#include<stdio.h>
#include<algorithm>
#include<cstring>
#define     count_one       __builtin_popcount
#define     For(i,a,b)      for(int i=a;i<=b;++i)
#define     pii             pair<int,int>
#define     fs              first
#define     sc              second
using namespace std;

pii g[16];
int n,dp[16][(1<<15)+2],dis[16][16];

int solve(int pre,int mask)
{
    if(mask==(1<<n-1)-1)return dis[pre][0];
    int &ans = dp[pre][mask];
    if(~ans)return ans;
    ans = (1<<28);
    For(i,1,n-1)
    {
        if(mask&(1<<i-1))continue;
        ans = min(ans,solve(i,mask|(1<<i-1))+dis[pre][i]);
    }
    return ans;
}

int main()
{
    char tmp;
    int r,c,idx;
    while(scanf("%d %d",&r,&c)==2)
    {
        n=1;
        For(i,1,r)
        {
            For(j,1,c)
            {
                scanf(" %c",&tmp);
                if(tmp=='L')g[0]=make_pair(i,j);
                else if(tmp=='#')g[n++] = make_pair(i,j);
            }
        }
        For(i,0,n-1)
        {
            For(j,0,(1<<n-1))
            {
                dp[i][j]=-1;
            }
        }
        For(i,0,n-1)
        {
            For(j,i,n-1)
            {
                dis[i][j] = dis[j][i] = max(abs(g[i].fs-g[j].fs),abs(g[i].sc-g[j].sc));
            }
        }
        printf("%d\n",solve(0,0));
    }
    return 0;
}

