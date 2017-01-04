//complexity O(n*sqr(m)) where n and m is the no of node in each side.
#include<bits/stdc++.h>
using namespace std;
#define SZ 102
#define ll long long
ll par[SZ];
bool c[SZ];
vector<ll>G[SZ];

bool dfs(ll u)
{
    if(c[u])return false;
    c[u]=true;
    for(ll i=0; i<G[u].size(); ++i)
    {
        ll v = G[u][i];
        if(par[v]==-1 or dfs(par[v]))
        {
            par[v]=u;
            return true;
        }
    }
    return false;
}

ll max_bpm(ll n)
{
    ll ans=0;
    memset(par,-1,sizeof(par));
    for(ll i=0; i<n; ++i)
    {
        memset(c,false,sizeof(c));
        if(dfs(i))ans++;
    }
    return ans;
}

int main()
{
    ll T,n,m,a[SZ],b[SZ];
    cin>>T;
    for(ll t=1; t<=T; ++t)
    {
        cin>>n;
        for(ll i=0; i<n; ++i)
            cin>>a[i];
        cin>>m;
        for(ll i=0; i<m; ++i)
            cin>>b[i];
        for(ll i=0; i<n; ++i)
        {
            for(ll j=0; j<m; ++j)
            {
                if(a[i]!=0 and b[j]%a[i]==0)
                {
                    G[i].push_back(j);
                }
                else if(b[j]==0)
                {
                    G[i].push_back(j);
                }
            }
        }

        printf("Case %lld: %lld\n",t,max_bpm(n));
        for (ll i=0; i<n; ++i)
            G[i].clear();
    }
}

/**

2
4 2 3 4 5
4 6 7 8 9
3 100 200 300
1 150

*/
