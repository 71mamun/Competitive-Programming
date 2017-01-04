#include<bits/stdc++.h>
using namespace std;
#define sz 25
#define inf 1000000000
int G[sz][sz];

int main()
{
    //freopen("risk.txt","r",stdin);
    int a,X,to,T=1;
    while(cin>>a)
    {
        for(int i=0; i<sz; i++)
        {
            for(int j=0; j<sz; j++)
            {
                if(i==j)G[i][j]=0;
                else G[i][j]=inf;
            }
        }
        for(int i=0; i<a; i++)
        {
            cin>>X;
            G[1][X]=1;
            G[X][1]=1;
        }
        for(int from=2; from<20; from++)
        {
            cin>>X;
            for(int i=0; i<X; i++)
            {
                cin>>to;
                G[from][to]=1;
                G[to][from]=1;
            }
        }

        for(int k=1; k<21; k++)
        {
            for(int j=1; j<21; j++)
            {
                for(int i=1; i<21; i++)
                {
                    G[i][j]=min(G[i][j],G[i][k]+G[k][j]);
                }
            }
        }

        int N,s,e;
        cin>>N;
        printf("Test Set #%d\n",T++);
        for(int i=0; i<N; i++)
        {
            cin>>s>>e;
            printf("%2d to %2d: %d\n",s,e,G[s][e]);
        }
        cout<<endl;
    }
    return 0;
}
