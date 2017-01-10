#include<bits/stdc++.h>
using namespace std;
#define LM 22

int T,t=1,h,s,turn,side,zed;

int dp[LM][LM*LM];
double mem[LM][LM*LM];

double sol(int pos,int sum)
{
    if(pos>=turn)
    {
        if(sum+zed>=h)return 1.0;
        else return 0.0;
    }
    if(h>turn*side+zed)
    {
        return 0.0;
    }

    double &ans = mem[pos][sum];
    if(dp[pos][sum]==t)return ans;
    dp[pos][sum] = t;
    ans = 0;

    for(int i=1;i<=side;++i)
    {
        ans+=sol(pos+1,sum+i)/side;
    }

    return ans;
}

string line;
char chr;

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    cin>>T;
    while(T--)
    {
        cin>>h>>s;
        double ans = -1;
        for(int i=0;i<s;++i)
        {
            memset(dp,0,sizeof(dp));
            zed = 0;
            cin>>line;
            stringstream ss(line);
            ss>>turn;
            ss>>chr;
            ss>>side;
            ss>>chr;
            if(chr==EOF)
            {
                ans = max(ans,sol(0,0));
                break;
            }
            if(chr==' ')
            {
                ans = max(ans,sol(0,0));
                continue;
            }
            ss>>zed;

            zed *= (chr=='-'?-1:1);

            ans = max(ans,sol(0,0));
        }
        printf("Case #%d: %.6lf\n",t++,ans);
    }
    return 0;
}

