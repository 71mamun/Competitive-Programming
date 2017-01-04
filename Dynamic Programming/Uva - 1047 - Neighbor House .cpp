#include<bits/stdc++.h>
#define SIZE 25
using namespace std;

struct info
{
    int red,green,blue;
};

info line[SIZE];
int N,DP[6][SIZE];

int Try(int prv_col,int now)
{
    if(now>N)return 0;
    int &ret = DP[prv_col][now];
    if(ret!=-1)return ret;
    int cost_red=0,cost_green=0,cost_blue=0;
    if(prv_col!=1)cost_red = line[now].red+Try(1,now+1);
    if(prv_col!=2)cost_green = line[now].green+Try(2,now+1);
    if(prv_col!=3)cost_blue = line[now].blue+Try(3,now+1);
    if(prv_col==1) return ret = min(cost_blue,cost_green);
    if(prv_col==2) return ret = min(cost_red,cost_blue);
    if(prv_col==3) return ret = min(cost_green,cost_red);
    else return ret = min(cost_blue,min(cost_red,cost_green));
}


int main()
{
    int T;
    cin>>T;
    for(int t=1;t<=T;t++)
    {
        memset(DP,-1,sizeof(DP));
        cin>>N;
        for(int i=1;i<=N;i++)cin>>line[i].red>>line[i].green>>line[i].blue;
        printf("Case %d: %d\n",t,Try(0,1));
    }
    return 0;
}
