#include<iostream>
#include<vector>
#include<queue>
#include<stdio.h>
using namespace std;
#define SZ 105
vector<int>grph[SZ];
int cost[SZ];
int n,a,b;
const int inf = 1e9;


void set_cost()
{
     for(int i=0;i<=n;i++)
     {
          cost[i] = inf;
     }
}

int dijkstra()
{
     set_cost();
     priority_queue<int>pq;
     cost[a]=0;
     pq.push(a);
     while(!pq.empty())
     {
          int u = pq.top();pq.pop();
          for(int i=0;i<grph[u].size();i++)
          {
               int v = grph[u][i];
               if(i==0&&cost[v]>cost[u])
               {
                    cost[v] = cost[u];
                    pq.push(v);
               }
               else if(cost[v]>cost[u]+1)
               {
                    cost[v] = cost[u]+1;
                    pq.push(v);
               }
          }
     }
     return cost[b];
}

int main()
{
     int l,v;
     scanf("%d %d %d",&n,&a,&b);
     for(int i=1;i<=n;i++)
     {
          scanf("%d",&l);
          while(l--)
          {
               scanf("%d",&v);
               grph[i].push_back(v);
          }
     }
     int ans = dijkstra();
     if(ans<inf)printf("%d\n",ans);
     else printf("%d\n",-1);
     return 0;
}

