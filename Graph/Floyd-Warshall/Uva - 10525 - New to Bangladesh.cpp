#include<bits/stdc++.h>
using namespace std;
#define sz 110
#define inf (1 << 28)
int delay[sz][sz];
int dis[sz][sz];
int main()
{
    int T,N,E,u,v,w,t;
    cin>>T;
    while(T--)
    {
        cin>>N>>E;
        for(int i=0; i<=N; i++)
        {
            for(int j=0; j<=N; j++)
            {
                if(i==j)dis[i][j]=delay[i][j]=0;
                else dis[i][j]=delay[i][j]=inf;
            }
        }
        for(int e=0; e<E; e++)
        {
            cin>>u>>v>>t>>w;
            if(delay[u][v]>t)
            {
                delay[u][v]=delay[v][u]=t;
                dis[u][v]=dis[v][u]=w;
            }
            if(delay[u][v]==t)
            {
                dis[u][v]=dis[v][u]=min(dis[u][v],w);
            }
        }
        for(int k=1; k<=N; k++)
        {
            for(int i=1; i<=N; i++)
            {
                for(int j=1; j<=N; j++)
                {
                    if(delay[i][j]>(delay[i][k]+delay[k][j]))
                    {
                        delay[i][j]=delay[i][k]+delay[k][j];
                        dis[i][j]=dis[i][k]+dis[k][j];
                    }
                    if(delay[i][j]==(delay[i][k]+delay[k][j]))
                    {
                        dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
                    }
                }
            }
        }
        int Q;
        cin>>Q;
        while(Q--)
        {
            cin>>u>>v;
            if(delay[u][v]<inf)printf("Distance and time to reach destination is %d & %d.\n",dis[u][v],delay[u][v]);
            else cout<<"No Path."<<endl;
        }
        if(T)cout<<endl;
    }
    return 0;
}
