#include<bits/stdc++.h>
using namespace std;
#define sz 1007
#define inf (1<<20)

int dis[sz];
struct edge
{
    int u,v,w;
    edge(int _,int __,int ___){
        u=_;v=__;w=___;
    }
};
vector<edge>edges;

bool Bellman_Ford(int n_node,int n_edge)
{
    int u,v,w;
    for(int n=0; n<=n_node; n++)dis[n]=inf;
    for(int n=1; n<n_node; n++)
    {
        for(int e=0; e<n_edge; e++)
        {
            u=edges[e].u;
            v=edges[e].v;
            w=edges[e].w;
            if(dis[u]+w<dis[v])
                dis[v]=dis[u]+w;
        }
    }
    for(int e=0; e<n_edge; e++)
    {
        u=edges[e].u;
        v=edges[e].v;
        w=edges[e].w;
        if(dis[u]+w<dis[v])return true;
    }
    return false;
}

int main()
{
    int T,N,M,a,b,c;
    cin>>T;
    while(T--)
    {
        cin>>N>>M;
        for(int m=0; m<M; m++)
        {
            cin>>a>>b>>c;
            edges.push_back(edge(a,b,c));
        }
        if(Bellman_Ford(N,M))cout<<"possible"<<endl;
        else cout<<"not possible"<<endl;
        edges.clear();
    }
    return 0;
}
