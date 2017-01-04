#include<bits/stdc++.h>
#define SIZE 110
using namespace std;
int adj[SIZE][SIZE];
const int inf=1<<28;
void floyd(int n)
{
    for(int i=1; i<=n; i++) adj[i][i]=0;
    for(int k=1; k<=n; k++)
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                adj[i][j]=min(adj[i][j],adj[i][k]+adj[k][j]);
}
int main()
{
    int T,n,m,u,v,w;
    scanf("%d",&T);
    for(int i=1; i<=T; i++)
    {
        for(int k=0;k<110;k++)
            for(int l=0;l<110;l++)
                    adj[k][l]=inf;
        scanf("%d %d",&n,&m);
        for(int j=0; j<m; j++)
        {
            scanf("%d %d %d",&u,&v,&w);
            if(w<adj[u][v] && w<adj[v][u])
            {
                adj[u][v]=w;
                adj[v][u]=w;
            }
        }
        floyd(n);
        if(adj[1][n]!=inf)printf("Case %d: %d\n",i,adj[1][n]);
        else printf("Case %d: Impossible\n",i);
    }
    return 0;
}
