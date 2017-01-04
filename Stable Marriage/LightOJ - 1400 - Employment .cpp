#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;

#define sz 305
int pos[sz][sz],N,T;
int h[sz];
queue<int>freem;
queue<int>wlist[sz];

void stableMarriage()
{
    memset(h,-1,sizeof(h));
    for(int i=1; i<=N; i++)freem.push(i);

    while (!freem.empty())
    {
        int m = freem.front();
        int wm = wlist[m].front();
        wlist[m].pop();

        if (h[wm] == -1)
        {
            h[wm] = m;
            freem.pop();
        }
        else
        {
            int herh = h[wm];
            if (pos[wm][m]<pos[wm][herh])
            {
                h[wm] = m;
                freem.pop();
                freem.push(herh);
            }
        }
    }
}

int main()
{
    int tmp,t=1;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&N);
        for(int r=1; r<=N; r++)for(int c=1; c<=N; c++)
            {
                scanf("%d",&tmp);
                wlist[r].push(tmp);
            }
        for(int r=N+1; r<=2*N; r++)for(int c=1; c<=N; c++)
            {
                scanf("%d",&tmp);
                pos[r][tmp]=c;
            }
        stableMarriage();
        printf("Case %d:",t++);
        for(int i=N+1; i<=N*2; i++)
        {
            printf(" (%d %d)",h[i],i);
        }
        printf("\n");
        for(int i=0; i<=N; i++)
            while(!wlist[i].empty())
                wlist[i].pop();
    }
    return 0;
}
