#include<bits/stdc++.h>
using namespace std;
#define SZ 120
vector<int>graph[SZ];
int color[SZ];
vector<int>topsort;
void DFS_Visit(int src)
{
    color[src]=0;
    for(int i=0; i<graph[src].size(); i++)
    {
        if(color[graph[src][i]]==-1)
        {
            DFS_Visit(graph[src][i]);
        }
    }
    topsort.push_back(src);
}
void DFS(int n)
{
    memset(color,-1,sizeof(color));
    for(int i=1; i<=n; i++)
    {
        if(color[i]==-1)
        {
            DFS_Visit(i);
        }
    }
}
int main()
{
    int n,e,u,v;
    while(cin>>n>>e&&n+e)
    {
        for(int i=0; i<e; i++)
        {
            cin>>u>>v;
            graph[u].push_back(v);
        }
        DFS(n);
        cout<<topsort[topsort.size()-1];
        for(int j=topsort.size()-2; j>=0; j--)
            cout<<" "<<topsort[j];
        cout<<endl;
        topsort.clear();
        for(int i=0;i<=n;i++)graph[i].clear();
    }
}


