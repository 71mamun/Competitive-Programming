#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long  ull;
#define     clr(a)          a.clear()
#define     sf              scanf
#define     pf              printf
#define     inf             (5e5+1)
#define     For(i,a,b)      for(int i=a;i<=b;++i)
#define     mem(a,b)        memset(a,b,sizeof(a))
#define LM 250003
int brk[LM],n;
int dp[2][LM];


int main()
{
    int T,t=1,tot;
    sf("%d",&T);
    while(T--)
    {
        tot=0;
        sf("%d",&n);
        For(i,1,n)
        {
            sf("%d",brk+i);
            tot+=brk[i];
        }
        tot/=2;

        if(tot>=LM)return 0;

        For(i,1,tot)dp[0][i] = -inf;
        dp[0][0] = 0;
        For(pos,1,n)
        {
            int cp = pos&1;
            int pp = (pos-1)&1;
            For(def,0,tot)
            {
                int &res = dp[cp][def];
                if(def<=tot)res = dp[pp][def];
                if(abs(def-brk[pos])<=tot)res = max(res,dp[pp][abs(def-brk[pos])]+brk[pos]);
                if(def+brk[pos]<=tot)res = max(res,dp[pp][def+brk[pos]]+brk[pos]);
            }
        }

        int ans = dp[n&1][0];
        pf("Case %d: ",t++);
        if(ans<=0)pf("impossible\n");
        else pf("%d\n",ans/2);
    }
    return 0;
}
