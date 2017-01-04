#include<cstdio>
#include<queue>
#include<cstring>
#include<iostream>
using namespace std;

#define sz 505
int position[sz][sz],N,T;
int husband[sz];
queue<int>freemans;
queue<int>womanlist[sz];

void stableMarriage()
{
    memset(husband,-1,sizeof(husband));
    for(int i=1; i<=N; i++)freemans.push(i);

    while (!freemans.empty())
    {
        int man = freemans.front();
        int woman = womanlist[man].front();
        womanlist[man].pop();

        if (husband[woman] == -1)
        {
            husband[woman] = man;
            freemans.pop();
        }
        else
        {
            int herhusband = husband[woman];
            if (position[woman][man]<position[woman][herhusband])
            {
                husband[woman] = man;
                freemans.pop();
                freemans.push(herhusband);
            }
        }
    }
}

int main()
{
    int tmp;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&N);
        for(int r=1; r<=N; r++)
        {
            cin>>tmp;
            for(int c=1; c<=N; c++)
            {
                scanf("%d",&tmp);
                womanlist[r].push(tmp);
            }
        }
        for(int r=1; r<=N; r++)
        {
            cin>>tmp;
            for(int c=1; c<=N; c++)
            {
                scanf("%d",&tmp);
                position[r][tmp]=c;
            }
        }
        stableMarriage();
        for(int i=1; i<=N; i++)
        {
            printf("%d %d\n",i,husband[i]);
        }
        for(int i=0; i<=N; i++)while(!womanlist[i].empty())womanlist[i].pop();
    }
    return 0;
}


