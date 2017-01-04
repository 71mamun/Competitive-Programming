#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

ll n,k,d;
ll DP[110][3];

ll solve(ll sum, bool dtrue)
{
    if(sum<=0)
    {
        if(sum<0)return 0;
        else if(sum==0&&dtrue) return 1;
        return 0;
    }
    ll &ret = DP[sum][dtrue];
    if(~ret)return DP[sum][dtrue];
    ll ret1=0,ret2=0;
    for(int i=1; i<=k; i++)
    {
        if(i>=d)
        {
            ret1 += solve(sum-i,dtrue|1);
        }
        else
        {
            ret2 += solve(sum-i,dtrue);
        }
    }
    return ret = (ret1+ret2)%MOD;
}


int main()
{
    memset(DP,-1,sizeof(DP));
    cin>>n>>k>>d;
    cout<<solve(n,0);
    return 0;
}
