#include<cstdio>
#include<cstring>

using namespace std;

#define sf scanf
#define pf printf
#define ms(a,b) memset(a,b,sizeof(a))

int coin[] = {50,25,10,5,1};
int DP[6][7500];

int solve(int i,int amount)
{
    if(i>=5)
    {
        if(amount==0)return 1;
        else return 0;
    }
    int &ret = DP[i][amount];
    if(ret!=-1)return ret;
    int ret1=0,ret2=0;
    if(amount-coin[i]>=0)ret1 = solve(i,amount-coin[i]);
    ret2 = solve(i+1,amount);
    return ret=ret1+ret2;
}

int main()
{
    int amount;
    ms(DP,-1);
    while(sf("%d",&amount)==1)
    {
        pf("%d\n",solve(0,amount));
    }
    return 0;
}
