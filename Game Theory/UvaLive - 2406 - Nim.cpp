#include<iostream>
#include<cstring>
using namespace std;
#define LM 9000
#define SZ 50
#define For(i,a,b) for(int i=a;i<=b;++i)
#define mem(a,b) memset(a,b,sizeof(a))
int arr[LM];
int n,s;
int dp[LM][SZ];

int sol(int s,int p)
{
    p%=(2*n);
    if(s==0)return (p%2==1?1:0);

    int &ret = dp[s][p];
    if(~ret)return ret;

    if(p%2==1)
    {
        For(i,1,arr[p])
        {
            if(s-i<0)break;
            if(sol(s-i,p+1))return ret = 1;
        }
        return ret = 0;
    }
    else
    {
        For(i,1,arr[p])
        {
            if(s-i<0)break;
            if(!sol(s-i,p+1))return ret = 0;
        }
        return ret = 1;
    }
}

int main()
{
    while(cin>>n&&n)
    {
        mem(dp,-1);
        cin>>s;
        For(i,0,2*n-1)
        {
            cin>>arr[i];
        }
        cout<<!sol(s,0)<<endl;
    }
    return 0;
}
