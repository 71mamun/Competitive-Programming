#include<bits/stdc++.h>
using namespace std;
#define sz 105
#define inf 1000000000
int G[sz][sz];

int main()
{
    int N,E,T=1,u,v,w;
    while(cin>>N>>E&&N+E)
    {
        for(int i=0; i<=N; i++)
        {
            for(int j=0; j<=N; j++)
            {
                G[i][j]=-1;
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
                    if(i!=j&&i!=k&&k!=j&&G[i][k]!=-1&&G[k][j]!=-1)G[i][j]=max(G[i][j],min(G[i][k],G[k][j]));
                }
            }
        }
        cout<<"Scenario #"<<T++<<endl;
        cin>>u>>v>>w;
        int mAx = G[u][v]-1;
        cout<<"Minimum Number of Trips = "<<ceil((double)w/mAx)<<endl<<endl;
    }
    return 0;
}