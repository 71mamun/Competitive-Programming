#include<iostream>
#include<cstring>
using namespace std;
#define ull unsigned long long
ull arr[2005];
ull DP[2005][2005];
ull solve(ull l,ull r,ull d)
{
    ull &ret = DP[l][r];
    if(ret!=-1)return ret;
    if(l==r)
    {
        return arr[l]*d;
    }
    ull ret1 = arr[l]*d+solve(l+1,r,d+1);
    ull ret2 = arr[r]*d+solve(l,r-1,d+1);
    return ret = max(ret1,ret2);
}

int main()
{
    ull n;
    memset(DP,-1,sizeof(DP));
    cin>>n;
    for(ull i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<solve(0,n-1,1)<<endl;
    return 0;
}