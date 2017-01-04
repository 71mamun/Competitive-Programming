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
int indeg[300000];
vector<int>G[300000];
int col[300000];
bool ok[300000];
int root;
bool dfs(int u)
{
    col[u]=1;
    for(int i=0;i<G[u].size();i++)
    {
        int v = G[u][i];
        if(col[v]==1||col[v]==2)return false;
        if(dfs(v))continue;
        else return false;
    }
    col[u] = 2;
    return true;
}

bool check(int maxnode)
{
    for(int i=1;i<=maxnode;i++)
    {
        if(ok[i]&&col[i]==-1)return false;
    }
    return true;
}
bool check2(int maxnode)
{
    for(int i=1;i<=maxnode;i++)
    {
        if(i==root)continue;
        else if(ok[i]&&indeg[i]!=1)return false;
    }
    return true;
}




int main()
{
    int u,v,t=1;
    while(cin>>u>>v)
    {
        if(u<0&&v<0)break;
        if(!(u+v)) {printf("Case %I64u is a tree.\n",t++);continue;}
        for(int i=0; i<300000; i++)G[i].clear();
        memset(indeg,0,sizeof(indeg));
        memset(col,-1,sizeof(col));
        memset(ok,false,sizeof(ok));
        int maxnode = -1;
        G[u].push_back(v);
        maxnode = max(v,max(u,maxnode));
        indeg[v]++;
        ok[u] = ok[v] = true;
        while(cin>>u>>v)
        {
            if(u==0&&v==0)break;
            G[u].push_back(v);
            indeg[v]++;
            ok[u] = ok[v] = true;
            maxnode = max(maxnode,max(v,u));
        }
        int c=0;
        for(int i=1;i<=maxnode;i++)
        {
            if(indeg[i]==0&&ok[i])
            {
                root = i;
                c++;
            }
        }
        printf("Case %d ",t++);
        if(c!=1)
        {
            cout<<"is not a tree."<<endl;
        }
        else if(dfs(root))
        {
            if(check(maxnode)&&check2(maxnode))cout<<"is a tree."<<endl;
            else cout<<"is not a tree."<<endl;
        }
        else
        {
            cout<<"is not a tree."<<endl;
        }
    }
    return 0;
}