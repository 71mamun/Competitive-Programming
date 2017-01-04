#include<stdio.h>
#include<vector>
using namespace std;
#define sf scanf
#define pf printf
#define pb push_back
vector<int>G[1003];
vector<int>W[1003];

int dfs(int p,int u)
{
    int ans = 0;
    for(int i=0;i<G[u].size();++i)
    {
        if(G[u][i]==p)continue;
        int v = dfs(u,G[u][i]);
        ans^=(W[u][i]>1?v^(W[u][i]%2):v+1);
    }
    return ans;
}

int main()
{
    int T,n,u,v,w,t=1;
    sf("%d",&T);
    while(T--)
    {
        sf("%d",&n);
        for(int i=0;i<n-1;++i)
        {
            sf("%d %d %d",&u,&v,&w);
            G[u].pb(v);
            W[u].pb(w);
            G[v].pb(u);
            W[v].pb(w);
        }
        pf("Case %d: ",t++);
        if(dfs(-1,0))pf("Emily\n");
        else pf("Jolly\n");
        for(int i=0; i<=n; ++i)
        {
            G[i].clear();
            W[i].clear();
        }
    }
    return 0;
}
