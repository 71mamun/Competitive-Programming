#include<bits/stdc++.h>
using namespace std;
#define LM 12
int arr[LM];
int dp[LM];

int sol(int pos)
{
    if(pos==0)return 1;
    int &ans = dp[pos];
    if(ans)return ans;
    ans = 1;
    for(int i=0;i<pos;++i)
    {
        if(arr[i]<arr[pos]) ans=max(ans,sol(i)+1);
    }
    return ans;
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i)
    {
        scanf("%d",arr+i);
    }
    int ans=0;
    for(int i=0;i<n;i++) ans=max(ans,sol(i));
    printf("%d\n",ans);
    return 0;
}
