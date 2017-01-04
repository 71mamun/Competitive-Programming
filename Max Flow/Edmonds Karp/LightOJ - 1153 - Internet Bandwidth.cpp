#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
#define LM 110
int n,source,sink,m,residual[LM][LM],par[LM],flow;
vector<int>G[LM];

bool augment_path()
{
    queue<int>Q;
    Q.push(source);
    memset(par,-1,sizeof par);
    while(!Q.empty())
    {
        int u = Q.front();Q.pop();
        for(int i=0;i<G[u].size();++i)
        {
            int v = G[u][i];
            if(par[v]==-1 and residual[u][v]>0)
            {
                par[v]=u;
                Q.push(v);
                if(v==sink)return true;
            }
        }
    }
    return false;
}

void path_update(int v)
{
    int u = par[v];
    flow = min(flow,residual[u][v]);
    if(u!=source)path_update(u);
    residual[u][v]-=flow;
    residual[v][u]+=flow;
}

int max_flow()
{
    int tot_flow = 0;
    while(augment_path())
    {
        flow = (1<<28);
        path_update(sink);
        tot_flow+=flow;
    }
    return tot_flow;
}

int main()
{
    int T,t=1,u,v,w;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d %d %d",&n,&source,&sink,&m);
        for(int i=1;i<=n;++i)G[i].clear();
        memset(residual,0,sizeof residual);
        for(int i=0;i<m;++i)
        {
            scanf("%d %d %d",&u,&v,&w);
            if(residual[u][v]==0)
            {
                G[u].push_back(v);
                G[v].push_back(u);
            }
            residual[u][v]+=w;
            residual[v][u]+=w;
        }
        printf("Case %d: %d\n",t++,max_flow());
    }
    return 0;
}
