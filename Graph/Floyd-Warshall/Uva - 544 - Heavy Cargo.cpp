#include<bits/stdc++.h>
using namespace std;
#define sz 210
int G[sz][sz];
int N,M,valu;

void floyed_warsel(void)
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            for(int k=0;k<N;k++)
            {
                if(G[i][k]!=-1&&G[k][j]!=-1&&i!=k&&i!=j&&j!=k)
                {
                    G[i][j] = max(G[i][j],min(G[i][k],G[k][j]));
                }
            }
        }
    }
}

int main()
{
    string ftmp,ttmp;
    map<string,int>vs;
    int T=1;
    while(cin>>N>>M&&N+M)
    {
        memset(G,-1,sizeof(G));
        int alu = 0;
        for(int m=0; m<M; m++)
        {
            cin>>ftmp>>ttmp>>valu;
            if(vs.find(ftmp)==vs.end())vs[ftmp]=alu++;
            if(vs.find(ttmp)==vs.end())vs[ttmp]=alu++;
            G[vs[ftmp]][vs[ttmp]]=valu;
            G[vs[ttmp]][vs[ftmp]]=valu;
        }
        floyed_warsel();
        cin>>ftmp>>ttmp;
        printf("Scenario #%d\n",T++);
        printf("%d tons\n\n",G[vs[ftmp]][vs[ttmp]]);
        vs.clear();
    }
    return 0;
}
