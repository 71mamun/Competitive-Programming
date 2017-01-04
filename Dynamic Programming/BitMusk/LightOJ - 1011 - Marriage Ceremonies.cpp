#include<bits/stdc++.h>
using namespace std;
#define SZ 18
#define maskSZ (1<<18)

int priority[SZ][SZ];
int DP[SZ][maskSZ];
int T,N;

int solve(int now,int mask)
{
    if(now>=N)return 0;
    int &ret = DP[now][mask];
    if(ret)return ret;
    for(int i=0; i<N; i++)
    {
        if((mask&(1<<i))==0)
        {
            ret = max(ret,solve(now+1,mask|(1<<i))+priority[i][now]);
        }
    }
    return ret;
}

int main()
{
    cin>>T;
    for(int t=1; t<=T; t++)
    {
        memset(DP,0,sizeof(DP));
        cin>>N;
        for(int r = 0; r<N; r++)
        {
            for(int c=0; c<N; c++)
            {
                cin>>priority[r][c];
            }
        }
        printf("Case %d: %d\n",t,solve(0,0));
    }
    return 0;
}
