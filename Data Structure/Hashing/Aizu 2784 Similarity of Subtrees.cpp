#include<bits/stdc++.h>
using namespace std;
#define LM 100007
#define ll long long
int n;
vector<int>G[LM];
map<ll,ll>store;
const int base = 100007;
const int mod = 1000000007;

ll dfs(int u,int p)
{
    ll ans = 0;
    for(auto v:G[u])
    {
        if(p!=v)
            ans=(ans+dfs(v,u))%mod;
    }

    ans=(ans*base)%mod;
    ans=(ans+1)%mod;
    store[ans]++;
    return ans;
}

int main()
{
    int u,v;
    cin>>n;

    for(int i=0;i<n-1;++i)
    {
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    dfs(1,-1);

    ll ans = 0;

    for(auto it:store)
    {
        ans+=((it.second-1)*it.second)/2;
    }

    cout<<ans<<endl;

    return 0;
}
