#include<bits/stdc++.h>
using namespace std;
#define sz 110
#define inf (1<<18)
int G[sz][sz];
int fcost[sz];
int Gf[sz][sz];
int main()
{
    int C,R,Q,u,v,w,T=1;
    while(cin>>C>>R>>Q&&C||R||Q)
    {
        if(T!=1)cout<<endl;
        for(int c=1; c<=C; c++)cin>>fcost[c];
        for(int i=0; i<=C; i++)
        {
            for(int j=0; j<=C; j++)
            {
                if(i==j)G[i][j]=Gf[i][j]=0;
                else G[i][j]=Gf[i][j]=inf;
            }
        }
        for(int r=0; r<R; r++)
        {
            cin>>u>>v>>w;
            G[u][v]=G[v][u]=min(G[u][v],w);
            Gf[u][v]=Gf[v][u]=max(fcost[u],fcost[v]);
        }

        for(int k=1; k<=C; k++)
        {
            for(int i=1; i<=C; i++)
            {
                for(int j=1; j<=C; j++)
                {
                    if((G[i][j]+Gf[i][j])>(G[i][k]+G[k][j]+max(Gf[i][k],Gf[k][j])))
                    {
                        G[i][j]=G[i][k]+G[k][j];
                        Gf[i][j]=max(Gf[i][k],Gf[k][j]);
                    }
                    if(G[i][j]==(G[i][k]+G[k][j]))
                    {
                        Gf[i][j]=min(Gf[i][j],max(Gf[i][k],Gf[k][j]));
                    }
                }
            }
        }

        for(int k=1; k<=C; k++)
        {
            for(int i=1; i<=C; i++)
            {
                for(int j=1; j<=C; j++)
                {
                    if((G[i][j]+Gf[i][j])>(G[i][k]+G[k][j]+max(Gf[i][k],Gf[k][j])))
                    {
                        G[i][j]=G[i][k]+G[k][j];
                        Gf[i][j]=max(Gf[i][k],Gf[k][j]);
                    }
                    if(G[i][j]==(G[i][k]+G[k][j]))
                    {
                        Gf[i][j]=min(Gf[i][j],max(Gf[i][k],Gf[k][j]));
                    }
                }
            }
        }

        cout<<"Case #"<<T++<<endl;
        for(int q=0; q<Q; q++)
        {
            cin>>u>>v;
            if(G[u][v]<inf)
            {
                cout<<G[u][v]+Gf[u][v]<<endl;
            }
            else cout<<"-1"<<endl;
        }
    }
    return 0;
}
