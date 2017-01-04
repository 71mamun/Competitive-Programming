///link - https://www.codechef.com/problems/TACNTSTR
#include<stdio.h>
#include<string.h>
#define LM 100007
const int mod = 1e9+7;
char s[LM];
int l,dp[LM][2][2];

int sol(int pos,int front_large,int back_large)
{
    if(pos>=l)return (front_large&&back_large);

    int low = 0,now = s[pos]-'A',&ans = dp[pos][front_large][back_large];
    if(~ans)return ans;
    ans = 0;
    if(!front_large)low = now;

    for(;low<26;++low)
    {
        if(low>now)ans+=sol(pos+1,1,1);
        else if(low==now) ans+=sol(pos+1,front_large,back_large);
        else ans+=sol(pos+1,front_large,0);
        ans%=mod;
    }

    return ans;
}

int main()
{
    scanf("%s",s);
    memset(dp,-1,sizeof(dp));
    l = strlen(s);
    printf("%d\n",sol(0,0,0));
    return 0;
}

