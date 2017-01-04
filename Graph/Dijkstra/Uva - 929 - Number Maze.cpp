#include<bits/stdc++.h>
using namespace std;
#define sz 1005
#define inf 1000000000
int G[sz][sz],dis[sz][sz],T,R,C,dr[]={0,0,-1,1},dc[]={-1,1,0,0};
struct edge
{int ur,uc,w;edge(int _,int __,int _$){ur = _;uc=__;w=_$;}bool operator<(const edge&p) const{return w > p.w;}};
priority_queue<edge>Q;
void dijkstra(int src_r,int src_c)
{
    int v_r,v_c;
    dis[src_r][src_c]=G[src_r][src_c];
    for(int i=0; i<4; i++)
    {
        v_r = src_r+dr[i];
        v_c = src_c+dc[i];
        if(v_r>=0&&v_c>=0&&v_r<R&&v_c<C)
        {
            dis[v_r][v_c]=dis[src_r][src_c]+G[v_r][v_c];
            Q.push(edge(v_r,v_c,dis[v_r][v_c]));
        }
    }
    while(!Q.empty())
    {
        edge now = Q.top();
        Q.pop();
        for(int d=0; d<4; d++)
        {
            v_r = now.ur+dr[d];
            v_c = now.uc+dc[d];
            if(v_r>=0&&v_c>=0&&v_r<R&&v_c<C&&dis[v_r][v_c]>dis[now.ur][now.uc]+G[v_r][v_c])
            {
                dis[v_r][v_c]=dis[now.ur][now.uc]+G[v_r][v_c];
                Q.push(edge(v_r,v_c,dis[v_r][v_c]));
            }
        }
    }
}

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&R,&C);
        for(int r=0; r<R; r++)for(int c=0; c<C; c++)dis[r][c]=inf;
        for(int r=0; r<R; r++)for(int c=0; c<C; c++)scanf("%d",&G[r][c]);
        dijkstra(0,0);
        printf("%d\n",dis[R-1][C-1]);
    }
    return 0;
}
