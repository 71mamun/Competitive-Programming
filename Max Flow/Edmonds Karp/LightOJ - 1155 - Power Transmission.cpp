#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
#define LM 220
vector<int>G[LM];
int n,residual[LM][LM],par[LM],source=1,drain,flow;

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
                if(v==drain)return true;
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
        path_update(drain);
        tot_flow+=flow;
    }
    return tot_flow;
}

int main()
{
    int T,u,v,w,m,t=1,b,d;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        drain = (n+1)*2;
        for(int i=1;i<=n;++i)
        {
            /// unidirectional
            u = i*2;
            v = (u^1);
            G[u].push_back(v);
            G[v].push_back(u);
            scanf("%d",&w);
            residual[u][v]+=w;
        }
        scanf("%d",&m);
        while(m--)
        {
            /// unidirectional
            scanf("%d %d %d",&u,&v,&w);
            u = ((2*u)^1);
            v = 2*v;
            G[u].push_back(v);
            G[v].push_back(u);
            residual[u][v]+=w;
        }
        scanf("%d %d",&b,&d);
        for(int i=0;i<b;++i)
        {
            /// unidirectional
            scanf("%d",&v);
            G[source].push_back(v*2);
            G[v*2].push_back(source);
            residual[source][v*2]+=(1<<28);
        }
        for(int i=0;i<d;++i)
        {
            /// unidirectional
            scanf("%d",&u);
            u = (2*u)^1;
            G[u].push_back(drain);
            G[drain].push_back(u);
            residual[u][drain]+=(1<<28);
        }
        printf("Case %d: %d\n",t++,max_flow());
        for(int i=1;i<=2*(n+1);++i)G[i].clear();
        memset(residual,0,sizeof residual);
    }
    return 0;
}
