#include<cstdio>
#include<cstring>
using namespace std;
#define SZ 10004
#define mod (100000007)

int coin;
int T,N,K;
int DP[SZ];

int main()
{
    int t=1;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d",&N,&K);
        memset(DP,0,sizeof(DP));
        DP[0]=1;
        while(N--)
        {
            scanf("%d",&coin);
            for(int i=coin;i<=K;i++)
            {
                /**
                    'i'-coin'tk joto vabe banao jay toto vabe baniye
                    notun kore'i' tk toto vabe banano jabe.
                */
                DP[i] = (DP[i]+DP[i-coin])%mod;
            }
        }
        printf("Case %d: %d\n",t++,DP[K]);
    }
    return 0;
}
