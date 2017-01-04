#include<bits/stdc++.h>
using namespace std;
#define SZ 1000
priority_queue<int>Qgraph[SZ];
int color[SZ];
int disTime[SZ];
int finishTime[SZ];
int parent[SZ];
int t;
vector<int>topsort;
void DFS_Visit(int src)
{
    t++;
    disTime[src]=t;
    color[src]=0;
    while(!Qgraph[src].empty())
    {
        int x = Qgraph[src].top();
        if(color[x]!=-1)Qgraph[src].pop();
        else
        {
            DFS_Visit(x);
            Qgraph[src].pop();
        }
    }
    color[src]=1;
    t++;
    finishTime[src]=t;
    topsort.push_back(src);
}
void DFS(int n)
{
    memset(color,-1,sizeof(color));
    memset(parent,-1,sizeof(parent));
    t=0;
    for(int i=n-1; i>=0; i--)
    {
        if(color[i]==-1)
        {
            DFS_Visit(i);
        }
    }
}
int main()
{
    int n,e,u,v,N,T,t=1;
    cin>>T;
    while(T--)
    {
        cin>>n>>e;
        for(int i=0;i<=n;++i)while(!Qgraph[i].empty())Qgraph[i].pop();
        topsort.clear();
        for(int E=0; E<e; E++)
        {
            cin>>u>>N;
            for(int nn=0; nn<N; nn++)
            {
                cin>>v;
                Qgraph[v-1].push(u-1);
            }
        }

        DFS(n);
        for(int j=topsort.size()-1; j>=0; j--)
        {
            if(j)cout<<topsort[j]+1<<" ";
            else cout<<topsort[j]+1;
        }
        cout<<endl;
        if(T)cout<<endl;
    }
    return 0;
}
