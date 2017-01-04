#include<bits/stdc++.h>
using namespace std;
#define sz 50010
vector<int>G[sz];
int col[sz];
int cnt;

void DFS(int src)
{
    cnt++;
    col[src]=1;
    for(int i=0; i<G[src].size(); i++)
    {
        if(!col[G[src][i]])DFS(G[src][i]);
    }
}

int main()
{
    int M,N;
    map<string,int>vos;
    string u,v;
    while(cin>>N>>M&&N|M)
    {
        for(int i=0;i<N;i++)
        {
            cin>>u;
            vos[u]=i;
        }
        for(int m=0; m<M; m++)
        {
            cin>>u>>v;
            G[vos[u]].push_back(vos[v]);
            G[vos[v]].push_back(vos[u]);
        }
        memset(col,0,sizeof(col));
        int ans = -1;
        for(int i=1; i<=N; i++)
        {
            if(!col[i])
            {
                cnt=0;
                DFS(i);
                ans = max(cnt,ans);
            }
        }
        cout<<ans<<endl;
        for(int i=0; i<=N; i++)G[i].clear();
        vos.clear();
    }
    return 0;
}
