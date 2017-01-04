#include<bits/stdc++.h>
using namespace std;
#define pro_size 1005
#define max_taken 35
int DP[pro_size][max_taken];
int weight[pro_size];
int price[pro_size];
int N,cap;
int Try(int w,int n)
{
    int &ret = DP[n][w];
    if(n>N)return 0;
    if(ret!=-1)return ret;
    int taken_profit = 0;
    if(w+weight[n]<=cap)taken_profit = price[n]+Try(w+weight[n],n+1);
    int ignore_profit = Try(w,n+1);
    return ret = max(ignore_profit,taken_profit);
}
int main()
{
    int T,G,ans;
    cin>>T;
    while(T--)
    {
        ans = 0;
        cin>>N;
        for(int i=1;i<=N;i++)cin>>price[i]>>weight[i];
        cin>>G;
        for(int i=0;i<G;i++)
        {
            memset(DP,-1,sizeof(DP));
            cin>>cap;
            ans+=Try(0,1);
        }
        cout<<ans<<endl;
    }
    return 0;
}
