//complexity O(n*sqr(m)) where n and m is the no of node in each side.
#include<bits/stdc++.h>
using namespace std;
#define SZ 105
int par[SZ*SZ];
bool c[SZ*SZ];
char grd[SZ][SZ];
vector<int>G[SZ*SZ];

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
    int T,t=0,R,C;
    char tmp;
    cin>>T;
    while(T--)
    {
        cin>>R>>C;
        for(int i=0;i<R;++i)
        {
            for(int j=0;j<C;++j)
            {
                cin>>tmp;
                if(tmp=='1')G[i].push_back(R+j);
            }
        }
        printf("Case #%d: %d\n",++t,max_bpm(R*C));
        for(int i=0;i<=R*C;++i)G[i].clear();
    }
    return 0;
}
