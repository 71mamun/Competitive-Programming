#include<bits/stdc++.h>
using namespace std;
#define LM 207
long long T,t=1,n,q,d,m,value[LM],dp[LM][12][25];

long long sol(long long  pos,long long  taken,long long sum){

    if(taken>=m){
        return sum==0;
    }

    if(pos>=n){
        return 0;
    }

    long long &ans = dp[pos][taken][sum];
    if(~ans)return ans;
    ans = 0;
    ans+=sol(pos+1,taken,sum);
    ans+=sol(pos+1,taken+1,((((sum+value[pos])%d)+d)%d));
    return ans;
}

int main(){
    scanf("%lld",&T);
    while(T--){


        scanf("%lld %lld",&n,&q);

        for(int i=0;i<n;++i){
            scanf("%lld",value+i);
        }

        printf("Case %lld:\n",t++);

        while(q--){
            memset(dp,-1LL,sizeof(dp));
            scanf("%lld %lld",&d,&m);
            printf("%lld\n",sol(0,0,0));
        }
    }
    return 0;
}
