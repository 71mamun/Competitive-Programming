#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
#include<cstdio>
using namespace std;
#define SZ 107
vector<int>G[SZ];
int dis[SZ][2];
int start,finish;
int T,n,e,x,y;
void Dijkstra(int src,int flag)
{
    queue<int>Q;
    Q.push(src);
    int taken[SZ]={0};
    taken[src]=1;
    dis[src][flag]=0;
    while(!Q.empty())
    {
        int u=Q.front();
        Q.pop();
        for(int i=0; i<G[u].size(); i++)
        {
            int v=G[u][i];
            if(!taken[v])
            {
                Q.push(v);
                dis[v][flag]=dis[u][flag]+1;
                taken[v]=1;
            }
        }
    }
}
int main()
{
    scanf("%d",&T);
    for(int i=1; i<=T; i++)
    {
        memset(dis,0,sizeof(dis));
        scanf("%d %d",&n,&e);
        for(int o=0; o<SZ; o++)
        {
            G[o].clear();
        }
        for(int j=0; j<e; j++)
        {
            scanf("%d %d",&x,&y);
            G[x].push_back(y);
            G[y].push_back(x);
        }
        scanf("%d %d",&start,&finish);
        Dijkstra(start,0);
        Dijkstra(finish,1);
        int ans=0;
        for(int alu=0;alu<n;alu++)
            ans=max(ans,dis[alu][0]+dis[alu][1]);
        printf("Case %d: %d\n",i,ans);
    }
    return 0;
}
