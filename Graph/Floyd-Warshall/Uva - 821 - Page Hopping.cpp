#include<bits/stdc++.h>
using namespace std;
#define sz 110
#define inf 1000000000
int G[sz][sz];
int mAx;


void floyd_warshall(void)
{
    for(int k=1; k<=mAx; k++)
    {
        for(int i=1; i<=mAx; i++)
        {
            for(int j=1; j<=mAx; j++)
            {
                G[i][j] = min(G[i][j],G[i][k]+G[k][j]);
            }
        }
    }
    return ;
}


int main()
{
    int u,v,T=1;
    while(cin>>u>>v&&u+v)
    {
        mAx = 105;
        for(int i=1; i<=mAx; i++)
        {
            for(int j=1; j<=mAx; j++)
            {
                if(i==j) G[i][j] = 0;
                else G[i][j] = inf;
            }
        }

        mAx = max(u,v);
        G[u][v]=1;
        while(cin>>u>>v&&u+v)
        {
            mAx= max(mAx,max(u,v));
            G[u][v]=1;
        }
        floyd_warshall();
        int sum=0;
        int num=0;
        for(int i=1; i<=mAx; i++)
        {
            for(int j=1; j<=mAx; j++)
            {
                if(G[i][j]>0&&G[i][j]<inf)
                {
                    sum+=G[i][j];
                    num++;
                }
            }
        }
        printf("Case %d: average length between pages = %.3lf clicks\n",T++,((double)sum/num));
    }
    return 0;
}
