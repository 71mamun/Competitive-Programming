#include<bits/stdc++.h>
using namespace std;
#define inf (1<<28)
#define sz 30
int par[sz];
int G[sz][sz];
struct edge
{
    int u,v,w;
    edge(int _,int __,int ___)
    {
        u=_;v=__;w=___;
    }
};

vector<edge>e;
vector<edge>ans;

bool comp(edge a,edge b)
{
    if(a.w!=b.w)return a.w<b.w;
    else if(a.u!=b.u)return a.u<b.u;
    else return a.v<b.v;
}

int get_par(int r)
{
    return (par[r]==r?r:par[r]=get_par(par[r]));
}

void MST(int N)
{
    sort(e.begin(),e.end(),comp);
    for(int i=0;i<N;i++)
        par[i]=i;
    for(int i=0;i<e.size();i++)
    {
        int u=get_par(e[i].u);
        int v=get_par(e[i].v);
        if(u!=v)
        {
            par[u]=v;
            ans.push_back(e[i]);
        }
    }
}
int main()
{
    int T,D,w,u,v;
    cin>>T;
    for(int t=1;t<=T;t++)
    {
        cin>>D;
        for(int i=0;i<D;i++)
        {
            for(int j=0;j<D-1;j++)
            {
                scanf("%d,",&G[i][j]);
                if(G[i][j])e.push_back(edge(i,j,G[i][j]));
            }
            scanf("%d",&G[i][D-1]);
            if(G[i][D-1])e.push_back(edge(i,D-1,G[i][D-1]));
        }
        MST(D);
        printf("Case %d:\n",t);
        for(int i=0;i<ans.size();i++)
        {
            printf("%c-%c %d\n",ans[i].u+'A',ans[i].v+'A',ans[i].w);
        }
        e.clear();
        ans.clear();
    }
    return 0;
}