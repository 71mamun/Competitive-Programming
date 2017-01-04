#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<vector>

using namespace std;
#define SZ 28
map<string,int>Map;
vector<int>G[SZ];
vector<int>RG[SZ];
vector<int>sorted;
vector<int>ans[SZ];
string RMap[SZ];
bool col[SZ];
int n,m,t=0;

void DFS(int src)
{
    col[src]=true;
    for(int i=0;i<G[src].size();i++)
    {
        if(col[G[src][i]]==false)DFS(G[src][i]);
    }
    sorted.push_back(src);
}

void topsort()
{
    for(int i=1;i<=n;i++)
    {
        if(col[i]==false)DFS(i);
    }
}

void SCC_DFS(int src,int g)
{
    col[src]=false;
    for(int i=0;i<RG[src].size();i++)
    {
        if(col[RG[src][i]]==true)SCC_DFS(RG[src][i],g);
    }
    ans[g].push_back(src);
}


int main()
{
    string u,v;
    while(cin>>n>>m&&(n|m))
    {
        memset(col,false,sizeof(col));
        Map.clear();
        sorted.clear();
        for(int i=0;i<=SZ;i++)
        {
            ans[i].clear();
            G[i].clear(),RG[i].clear();
        }
        int c=1;
        for(int i=0;i<m;i++)
        {
            cin>>u>>v;
            if(Map.find(u)==Map.end())
            {
                Map[u]=c++;
                RMap[Map[u]]=u;
            }
            if(Map.find(v)==Map.end())
            {
                Map[v]=c++;
                RMap[Map[v]]=v;
            }
            G[Map[u]].push_back(Map[v]);
            RG[Map[v]].push_back(Map[u]);
        }
        topsort();c=0;
        memset(col,true,sizeof(col));
        for(int i=sorted.size()-1;i>=0;i--)
        {
            if(col[sorted[i]]==true)SCC_DFS(sorted[i],c++);
        }
        if(t)cout<<endl;
        printf("Calling circles for data set %d:\n",++t);
        for(int i=0;i<c;i++)
        {
            for(int j=0;j<ans[i].size();j++)
            {
                    if(j)cout<<", ";
                cout<<RMap[ans[i][j]];
            }
            cout<<endl;
        }
    }
    return 0;
}



