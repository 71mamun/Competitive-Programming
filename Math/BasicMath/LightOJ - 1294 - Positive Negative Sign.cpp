#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll T,t=1,n,m;
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld %lld",&n,&m);
        ll x = n/m;
        ll y = ceil((x-1.0)/2);
        ll z = y*m*m;
        printf("Case %lld: %lld\n",t++,z);
    }
    return 0;
}
