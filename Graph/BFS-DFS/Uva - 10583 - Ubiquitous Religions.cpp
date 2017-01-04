#include<bits/stdc++.h>
using namespace std;
#define sz  50010
vector<int>G[sz];
int col[sz];

void DFS(int src)
{
    if(col[src])return;
    col[src]=1;
    for(int i=0; i<G[src].size(); i++)DFS(G[src][i]);
}

int main()
{
    int E,N,u,v,T=1;
    while(cin>>N>>E&&E+N)
    {
        memset(col,0,sizeof(col));
        for(int e=0; e<E; e++)
        {
            cin>>u>>v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        int cnt = 0;
        for(int i=1; i<=N; i++)
        {
            if(!col[i])
            {
                DFS(i);
                cnt++;
            }
        }
        cout<<"Case "<<T++<<": "<<cnt<<endl;
        for(int i=0; i<=N; i++)G[i].clear();
    }
    return 0;
}
