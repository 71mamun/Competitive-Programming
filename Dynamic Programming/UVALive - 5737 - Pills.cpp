#include<bits/stdc++.h>
using namespace std;
long long n;
long long DP[45][70][45];

long long solve(long long half, long long crnt, long long one)
{
    if(crnt>=2*n)return 1ll;

    long long &ret = DP[half][crnt][one];
    if(ret!=-1)return ret;

    long long ret1=0,ret2=0;
    if(half>0)
    {
        ret1 = solve(half-1,crnt+1,one);
    }
    if(one>0){
            ret2 = solve(half+1,crnt+1,one-1);
    }
    return ret = ret1+ret2;
}


int main()
{
    while(cin>>n)
    {
        if(n==0)break;
        memset(DP,-1,sizeof(DP));
        cout<<solve(0,0,n)<<endl;
    }
    return 0;
}
