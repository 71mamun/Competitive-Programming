#include<bits/stdc++.h>
using namespace std;
#define SZ 1005
vector<int>bg[SZ],G[SZ],seta;
int n,m,set_col[SZ],par[SZ],bpm_col[SZ],tot_node;

bool bpm_dfs(int u)
{
    if(bpm_col[u]!=-1)return false;
    bpm_col[u]=0;
    for(int i=0;i<bg[u].size();++i)
    {
        int v = bg[u][i];
        if(par[v]==-1 or bpm_dfs(par[v]))
        {
            par[v]=u;
            return true;
        }
    }
    return false;
}

int max_bpm()
{
    memset(par,-1,sizeof(par));
    int cnt = 0;
    for(int i=0;i<seta.size();++i)
    {
        memset(bpm_col,-1,sizeof(bpm_col));
        if(bpm_dfs(seta[i]))cnt++;
    }
    return cnt;
}

void set_dfs(int u)
{
    tot_node++;
    for(int i=0;i<G[u].size();++i)
    {
        int v = G[u][i];
        if(set_col[v]==-1)
        {
            set_col[v]=set_col[u]^1;
            if(set_col[v]==0)seta.push_back(v),bg[v].push_back(u);
            else bg[u].push_back(v);
            set_dfs(v);
        }
    }
}

int cal(int u)
{
    tot_node = 0;
    seta.clear();
    for(int i=1;i<=n;++i)bg[i].clear();
    set_col[u]=0;
    seta.push_back(u);
    set_dfs(u);
    int ans = max_bpm();
    return tot_node-ans;
}

void init()
{
    memset(set_col,-1,sizeof(set_col));
    for(int i=1;i<=n;++i)G[i].clear();
}

int main()
{
	int T,t=0,u,v;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&n,&m);
		init();
		for(int i=0;i<m;++i)
		{
			scanf("%d %d",&u,&v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		int ans = 0;
		for(int i=1;i<=n;++i)
		{
			if(set_col[i]==-1)ans+=cal(i);
		}
		printf("Case %d: %d\n",++t,ans);
	}
}
