#include<bits/stdc++.h>
using namespace std;
#define sz 100003
vector<int>G[sz];
vector<int>clk;
bool col[sz];

void dfs(int src)
{
    col[src]=true;
    for(int i=0;i<G[src].size();i++)
    {
        int child = G[src][i];
        if(col[child]==false)dfs(child);
    }
}


int main()
{
    int T,N,M,u,v;
    cin>>T;
    while(T--)
    {
        memset(col,false,sizeof(col));
        clk.clear();
        for(int i=0;i<sz;i++)
        {
            G[i].clear();
        }
        cin>>N>>M;
        while(M--)
        {
            cin>>u>>v;
            G[u].push_back(v);
        }
        for(int i=1;i<=N;i++)
        {
            if(col[i]==false)
            {
                dfs(i);
                clk.push_back(i);
            }
        }
        memset(col,false,sizeof(col));
        int ans = 0;
        for(int i=clk.size()-1;i>=0;i--)
        {
            if(col[clk[i]]==false)
            {
                dfs(clk[i]);
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
