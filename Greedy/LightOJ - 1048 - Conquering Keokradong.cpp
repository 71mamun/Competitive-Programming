#include<stdio.h>
#include<algorithm>
#include<iostream>
using namespace std;
#define sf scanf
#define pf printf
#define SZ 1005

int dis[SZ];
int N,M;

int needed(int d)
{
    int sum = dis[0], n = 1;
    for(int i=1;i<=N;)
    {
        if(dis[i]+sum>d)
        {
            sum = 0;
            n++;
        }
        else
        {
            sum+=dis[i];
            i++;
        }
    }
    return n;
}

void print_dis(int res)
{
    int total = N+1, haveTo = M;
    int weight = 0;
    for(int i=0; i<=N;)
    {
        while(res>=weight+dis[i]&&i<=N)
        {
            if(total==haveTo)break;
            weight+=dis[i];
            total--;
            i++;
        }
        printf("%d\n",weight);
        weight = 0;
        if(haveTo==total)
        {
            for(int j=i; j<=N; j++)
            {
                printf("%d\n",dis[j]);
            }
            return;
        }
        haveTo--;
    }
}


int main()
{
    int T,t=1,Min,Max,Mid,req,ans;
    sf("%d",&T);
    while(T--)
    {
        Min = -1; Max = 0;
        sf("%d%d",&N,&M);
        for(int i=0;i<=N;i++)
        {
            sf("%d",&dis[i]);
            Min = max(Min,dis[i]);
            Max+=dis[i];
        }
        while(Min<=Max)
        {
            Mid = ((Min+Max)>>1);
            int req = needed(Mid);
            if(req<=M+1)
            {
                ans = Mid;
                Max = Mid-1;
            }
            else
            {
                Min = Mid+1;
            }
        }
        pf("Case %d: %d\n",t++,ans);
        print_dis(ans);
    }
    return 0;
}
