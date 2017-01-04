//complexity O(n*sqr(m)) where n and m is the no of node in each side.
#include<bits/stdc++.h>
using namespace std;
#define SZ 102
int par[SZ];
bool c[SZ];
vector<int>G[SZ];

bool dfs(int u)
{
    if(c[u])return false;
    c[u]=true;
    for(int i=0; i<G[u].size(); ++i)
    {
        int v = G[u][i];
        if(par[v]==-1 or dfs(par[v]))
        {
            par[v]=u;
            return true;
        }
    }
    return false;
}

int max_bpm(int n)
{
    int ans=0;
    memset(par,-1,sizeof(par));
    for(int i=0; i<n; ++i)
    {
        memset(c,false,sizeof(c));
        if(dfs(i))ans++;
    }
    return ans;
}

int main()
{
    int T,n,m,a[SZ],b[SZ];
    scanf("%d",&T);
    for(int t=1; t<=T; ++t)
    {
        scanf("%d",&n);
        for(int i=0; i<n; ++i)
            scanf("%d",a+i);
        scanf("%d",&m);
        for(int i=0; i<m; ++i)
            scanf("%d",b+i);
        for(int i=0; i<n; ++i)
        {
            for(int j=0; j<m; ++j)
            {
                if(b[j]%a[i]==0)
                {
                    G[i].push_back(j);
                }
            }
        }

        printf("Case %d: %d\n",t,max_bpm(n));
        for (int i=0; i<n; ++i)
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
