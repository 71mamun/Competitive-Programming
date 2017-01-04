#include<cstdio>
using namespace std;
#define ll long long
#define sf scanf
#define pf printf

ll BigMod(ll B,ll P,ll M)
{
    ll R=1%M;
    while(P>0)
    {
        if(P%2==1)
        {
            R=(R*B)%M;
        }
        P/=2;
        B=(B*B)%M;
    }
    return R;
}

int main()
{
    ll b,p,m;
    while(sf("%lld %lld %lld",&b,&p,&m)==3)
    {
        pf("%lld\n",BigMod(b,p,m));
    }
    return 0;
}
