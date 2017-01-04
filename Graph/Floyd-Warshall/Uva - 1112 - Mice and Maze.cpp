#include<bits/stdc++.h>
using namespace std;
#define sz 110
#define inf 1000000000
int G[sz][sz];
int main()
{
    cin.tie(NULL);
    int T,N,E,EXIT,TIME,u,v,t;
    cin>>T;
    while(T--)
    {
        cin>>N>>EXIT>>TIME>>E;
        for(int i=0; i<=N; i++)
        {
            for(int j=0; j<=N; j++)
            {
                if(i==j)G[i][j]=0;
                else G[i][j]=inf;
            }
        }
        for(int e=0; e<E; e++)
        {
            cin>>u>>v>>t;
            G[u][v]=min(G[u][v],t);
        }
        for(int k=1; k<=N; k++)
        {
            for(int i=1; i<=N; i++)
            {
                for(int j=1; j<=N; j++)
                {
                    if(i!=j&&j!=k&&k!=i&&G[i][k]!=inf&&G[k][j]!=inf)
                        G[i][j]=min(G[i][j],G[i][k]+G[k][j]);
                }
            }
        }
        int cnt=0;
        for(int i=1; i<=N; i++)
        {
            if(G[i][EXIT]<=TIME)cnt++;
        }
        cout<<cnt<<endl;
        if(T)cout<<endl;
    }
    return 0;
}