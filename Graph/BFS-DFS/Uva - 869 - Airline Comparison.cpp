#include<bits/stdc++.h>
using namespace std;
#define sz 300
vector<int>G[sz];
vector<int>P[sz];
int col[sz];
int ok1[sz];
int ok2[sz];

void DFS(int src,int alu)
{
    if(col[src]!=1)return;
    ok1[src]=alu;
    col[src] = -5;
    for(int i=0; i<G[src].size(); i++)
    {
        DFS(G[src][i],alu);
    }
    col[src] = -7;
}

void dfs(int src,int balu)
{
    if(col[src]!=1)return;
    ok2[src]=balu;
    col[src] = -5;
    for(int i=0; i<P[src].size(); i++)
    {
        dfs(P[src][i],balu);
    }
    col[src]=-7;
}

int main()
{
    int T,M,N;
    char u,v;
    cin>>T;
    while(T--)
    {
        for(int i=0; i<sz; i++)
        {
            G[i].clear();
            P[i].clear();
        }
        memset(ok1,0,sizeof(ok1));
        memset(ok2,0,sizeof(ok2));
        memset(col,0,sizeof(col));
        cin>>N;
        for(int n=0; n<N; n++)
        {
            cin>>u>>v;
            col[u]=1;col[v]=1;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        int alu=2;
        for(int i=0;i<sz;i++)
        {
            if(col[i]==1)DFS(i,alu++);
        }
        memset(col,0,sizeof(col));
        cin>>M;
        for(int m=0; m<M; m++)
        {
            cin>>u>>v;
            col[u]=1;col[v]=1;
            P[u].push_back(v);
            P[v].push_back(u);
        }
        int balu = 2;
        for(int i=0;i<sz;i++)
        {
            if(col[i]==1)dfs(i,balu++);
        }
        int flag=1;

        for(int i=0; i<sz; i++)
        {
            if(ok1[i]!=ok2[i])
            {
                flag=0;
                break;
            }
        }
        if(flag)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        if(T)cout<<endl;
    }
    return 0;
}
