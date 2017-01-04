#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define LM 50007
#define deb(a...)          {cerr<<"#"<<__LINE__<<" -> ";dbg,a; cerr<<endl;}
struct debugger { template<typename T> debugger& operator , (const T v) { cerr<<v<<" "; return *this; } } dbg;

ll n,k;
vector<ll>G[LM];
ll dp[LM][550];

ll dfs(ll u,ll p)
{
    dp[u][0] = 1;
    ll ans = 0;
    for(ll i=0;i<G[u].size();++i)
    {
        ll v = G[u][i];
        if(p==v)continue;
        ans+=dfs(v,u);

        for(ll i=1; i<=k; ++i)
        {
            ans+= (dp[v][i-1]*dp[u][k-i]);
        }

        for(ll j=0;j<k;++j)
        {
            dp[u][j+1]+=dp[v][j];
        }
    }

    return ans;

}


int main()
{
    ll u,v;
    cin>>n>>k;
    for(ll i=0;i<n-1;++i)
    {
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    cout<<dfs(1,0)<<endl;
    return 0;
}
