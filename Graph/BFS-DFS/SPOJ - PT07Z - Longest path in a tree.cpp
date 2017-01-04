#include<stdio.h>
#include<iostream>
#include<math.h>
#include<string>
#include<string.h>
#include<algorithm>
#include<stack>
#include<queue>
#include<vector>
#include<map>
#include<stdlib.h>
using namespace std;
#define ll long long
vector<int>G[10005];
int dis[10005];
int pdis[10005];
int col[10005];
int n,u,v;

int bfs(int src)
{
    memset(col,-1,sizeof(col));
    memset(dis,0,sizeof(dis));
    queue<int>Q;
    dis[src]=0;
    Q.push(src);
    col[src] = 1;
    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        for(int i=0;i<G[u].size();i++)
        {
            int v  = G[u][i];
            if(col[v]==-1)
            {
                dis[v] = dis[u]+1;
                col[v] = 1;
                Q.push(v);
            }
        }
    }
    int mxdis = -1;
    for(int i=1;i<=n;i++)
    {
        if(mxdis<dis[i])
        {
            mxdis = dis[i];
        }
    }
    return mxdis;
}

int main()
{
    cin>>n;
    for(int i=1;i<n;i++)
    {
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int mxdix = bfs(1);
    for(int i=1;i<=n;i++)pdis[i] = dis[i];
    int ans = -1;
    for(int i=1;i<=n;i++)
    {
        if(pdis[i]==mxdix)
        {
            ans = max(mxdix,bfs(i));
            break;
        }
    }
    cout<<ans<<endl;
    return 0;
}
