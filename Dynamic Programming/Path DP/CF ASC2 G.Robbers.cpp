#include<bits/stdc++.h>
using namespace std;
#define LM 1007
#define ll long long
ll n,m,y;
ll k[LM],x[LM];

ll dp[LM][LM];

ll sol(ll pos,ll extra)
{

    if(pos>=n)
    {
        return (extra==0?0:(1<<30));
    }

    if(extra<0)return (1<<30);

    ll &ans = dp[pos][extra];
    if(~ans)return ans;
    ans = (1<<30);

    ans = min(ans,sol(pos+1,extra-1)+abs(x[pos]*m-(k[pos]+1)*y));
    ans = min(ans,sol(pos+1,extra)+abs(x[pos]*m-(k[pos])*y));

    return ans;

}

void path(ll pos,ll extra)
{
    ll ans = sol(pos,extra);
    if(pos>=n)
    {
        return;
    }

    if(ans == sol(pos+1,extra-1)+abs(x[pos]*m-(k[pos]+1)*y))
    {
        cout<<k[pos]+1<<" ";
        path(pos+1,extra-1);
    }
    else if(ans == sol(pos+1,extra)+abs(x[pos]*m-(k[pos])*y))
    {
        cout<<k[pos]<<" ";
        path(pos+1,extra);
    }
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    memset(dp,-1,sizeof(dp));
    cin>>n>>m>>y;
    for(ll i=0;i<n;++i)
    {
        cin>>x[i];
    }

    ll sum=0;

    for(ll i=0;i<n;++i)
    {
        sum+=((x[i]*m)/y);
        k[i] = ((x[i]*m)/y);
    }

    ll extra = m-sum;

    ll cost = sol(0,extra);

    path(0,extra);

    return 0;
}

/*
3 10 4
1 1 2
*/
