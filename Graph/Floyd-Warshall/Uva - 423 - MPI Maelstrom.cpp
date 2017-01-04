#include <bits/stdc++.h>
using namespace std;
#define sz 110
#define inf 1000000000
int G[sz][sz];

int main()
{
    int n, mIn;
    char num[sz];
    cin>>n;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            G[i][j]=inf;
        }
    }

    for (int i = 0; i<n; i++)
    {
        for (int j = 0; j<i; j++)
        {
            cin>>num;
            if(num[0]=='x') continue;
            else
            {
                sscanf(num,"%d", &G[i][j]);
                G[j][i]=G[i][j];
            }
        }
    }
    for (int k = 0; k<n; k++)
        for (int i = 0; i<n; i++)
            for (int j = 0; j<n; j++)
                G[i][j]=min(G[i][j], G[i][k]+G[k][j]);
    mIn = 0;
    for (int i=0; i<n; i++)
        mIn=max(mIn,G[0][i]);
    printf("%d\n", mIn);
    return 0;
}
