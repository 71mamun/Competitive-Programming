#include<bits/stdc++.h>
using namespace std;
#define sz 220
#define inf 1000000000
double G[sz][sz];
int u,v,N;

struct point
{
    int x,y;
};
point plt[sz];

double dis(point a,point b)
{
    return sqrt((double)(a.x-b.x)*(a.x-b.x)+(double)(a.y-b.y)*(a.y-b.y));
}


void floyd_warshall(void)
{
    for(int k=0; k<N; k++)
    {
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<N; j++)
            {
                G[i][j] = min(G[i][j],max(G[i][k],G[k][j]));
            }
        }
    }
    return ;
}


int main()
{
    int T=1;
    while(cin>>N&&N)
    {
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<N; j++)
            {
                if(i==j) G[i][j] = 0;
                else G[i][j] = inf;
            }
        }

        for(int i=0; i<N; i++)
        {
            cin>>plt[i].x>>plt[i].y;
            if(i>0)
            {
                for(int j=0; j<i; j++)
                {
                    G[i][j]=dis(plt[i],plt[j]);
                    G[j][i]=dis(plt[i],plt[j]);
                }
            }
        }

        floyd_warshall();
        printf("Scenario #%d\n",T++);
        printf("Frog Distance = %.3lf\n\n",G[0][1]);

    }
    return 0;
}
