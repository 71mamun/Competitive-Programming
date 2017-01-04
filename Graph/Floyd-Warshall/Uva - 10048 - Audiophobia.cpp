#include<bits/stdc++.h>
using namespace std;
#define sz 105
#define inf 1000000000
int G[sz][sz];

int main()
{
    int N,E,Q,T=1,u,v,w;
    while(cin>>N>>E>>Q&&N+E+Q)
    {
        if(T!=1)cout<<endl;
        for(int i=0; i<=N; i++)
        {
            for(int j=0; j<=N; j++)
            {
                G[i][j]=inf;
            }
        }
        for(int i=0; i<E; i++)
        {
            cin>>u>>v>>w;
            G[u][v]=w;
            G[v][u]=w;
        }
        for(int k=1; k<=N; k++)
        {
            for(int j=1; j<=N; j++)
            {
                for(int i=1; i<=N; i++)
                {
                    if(i!=j&&i!=k&&k!=j&&G[i][k]!=inf&&G[k][j]!=inf)G[i][j]=min(G[i][j],max(G[i][k],G[k][j]));
                }
            }
        }
        cout<<"Case #"<<T++<<endl;
        for(int i=0;i<Q;i++)
        {
            cin>>u>>v;
            if(G[u][v]<inf)cout<<G[u][v]<<endl;
            else cout<<"no path"<<endl;
        }
    }
    return 0;
}

