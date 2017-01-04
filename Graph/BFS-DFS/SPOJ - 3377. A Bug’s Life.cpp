#include<iostream>
#include<vector>
#include<queue>
#include<cstdio>
#include<cstring>
using namespace std;
#define SZ 2005
vector<int>G[SZ];
int color[SZ];
int BFS(int src)
{
    int u,v;
    queue<int>Q;
    Q.push(src);
    color[src]=1;
    int i;
    while(!Q.empty())
    {
        u=Q.front();
        for(i=0; i<G[u].size(); i++)
        {
            v=G[u][i];
            if(color[v]==-1)
            {
                color[v]=!color[u];
                Q.push(v);
            }
            else if(color[v]==color[u])return 0;
        }
        Q.pop();
    }
    return 1;
}
int main()
{
    int T,n,e,x,y,l,i,j;
    scanf("%d",&T);
    for(i=1; i<=T; i++)
    {
        scanf("%d %d",&n,&e);
        printf("Scenario #%d:\n",i);
        for(int k=1; k<=n; k++)
        {
            G[k].clear();
            color[k]=-1;
        }
        for(int j=0; j<e; j++)
        {
            scanf("%d %d",&x,&y);
            G[x].push_back(y);
            G[y].push_back(x);
        }
        for(l=1; l<=n; l++)
        {
            if(color[l]==-1&&!BFS(l))
            {
                printf("Suspicious bugs found!\n");
                break;
            }
        }
        if(l>n)printf("No suspicious bugs found!\n");
    }
    return 0;
}
