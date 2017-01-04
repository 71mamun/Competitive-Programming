#include<bits/stdc++.h>
using namespace std;
#define SZ 16
#define popcount __builtin_popcount
long long tbl[SZ][SZ];
int N,T;
long long DP[(1<<14)+10][SZ];

long long solve(long long musk,long long curr)
{
    if(popcount(musk)==N)
    {
        return 0;
    }
    long long &ans = DP[musk][curr];
    if(ans!=-1)return ans;
    long long add = (1<<30);
    for(long long i=0;i<N;i++)
    {
        if((musk&(1<<i))==0)
        {
            musk = (musk|(1<<i));
            long long cost = 0;
            for(long long j=0;j<N;j++)
            {
                if((musk&(1<<j)))cost+=tbl[i][j];
            }
            add = min(add,solve(musk,curr+1)+cost);
            musk = (musk&(~(1<<i)));
        }
    }
    return ans = add;
}

int main()
{
    cin>>T;
    for(long long t=1;t<=T;t++)
    {
        memset(DP,-1,sizeof(DP));
        cin>>N;
        for(long long n=0;n<N;n++)
        {
            for(long long m=0;m<N;m++)
            {
                cin>>tbl[n][m];
            }
        }
        printf("Case %lld: ",t);
        cout<<solve(0,0)<<endl;
    }
    return 0;
}


