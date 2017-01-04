#include<stdio.h>
#include<set>
#include<algorithm>
#include<cstring>
#include<vector>
#define SZ 10005
using namespace std;
vector<int>G[SZ];
int lowestTime[SZ], discoveryTime[SZ], visitMark[SZ], n, dfsCount;
set<int>articulationPoint;
vector<pair<int,int> >bridge;

void dfs(int u,int p,int root)
{
    visitMark[u]=0;
    int l = (int)G[u].size(),cnt=0;
    discoveryTime[u] = lowestTime[u] = ++dfsCount;
    for(int i=0;i<l;i++)
    {
        int v = G[u][i];
        if(v==p)continue;
        if(visitMark[v]==-1)
        {
            cnt++;
            dfs(v,u,root);
            lowestTime[u] = min(lowestTime[u],lowestTime[v]);
            if(lowestTime[v]>=discoveryTime[u]&&u!=root)articulationPoint.insert(u);
            if(lowestTime[v]>discoveryTime[u])bridge.push_back(make_pair(min(u,v),max(u,v)));
        }
        else
        {
            lowestTime[u] = min(lowestTime[u],discoveryTime[v]);
        }
    }
    if(cnt>1&&u==root)
    {
        articulationPoint.insert(u);
    }
}


void calculateArticulationPointAndBridge()
{
    for(int i=0;i<n;i++)visitMark[i]=-1;
    articulationPoint.clear();
    bridge.clear();
    dfsCount = -1;
    for(int i=0;i<n;i++)
    {
        if(visitMark[i]==-1)dfs(i,-1,i);
    }
}

bool cmp(pair<int,int>a,pair<int,int>b)
{
    if(a.first!=b.first)return a.first<b.first;
    else return a.second<b.second;
}


int main()
{
    int T,t=1,u,l,v;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)G[i].clear();
        for(int i=0;i<n;i++)
        {
            scanf("%d (%d)",&u,&l);
            while(l--)
            {
                scanf("%d",&v);
                G[u].push_back(v);
            }
        }
        calculateArticulationPointAndBridge();
        printf("Case %d:\n",t++);
        printf("%d critical links\n",(int)bridge.size());
        sort(bridge.begin(),bridge.end(),cmp);
        for(int i=0;i<bridge.size();i++)
        {
            printf("%d - %d\n",bridge[i].first,bridge[i].second);
        }
    }
    return 0;
}
