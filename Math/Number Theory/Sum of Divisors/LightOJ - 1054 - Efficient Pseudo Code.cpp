/**
    "In the name of Allah, the Most Gracious, the Most Merciful."
*/
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <math.h>
#include <limits.h>
#include <limits>
#include <string.h>
#include <string>
#include <algorithm>
#include <stack>
#include <set>
#include <ctime>
#include <queue>
#include <vector>
#include <map>
#include <assert.h>
#include <utility>
#define ms(a,b) memset(a,b,sizeof(a))
#define inf 1<<28
#define mp make_pair
#define pii pair<int,int>
#define fs first
#define sc second
#define pob pop_back
#define vec_ vector
#define clr(a) a.clear()
#define pb push_back
#define eps 1E-7
#define sf scanf
#define pf printf
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define fop   freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define scch(a) scanf(" %c",&a)
#define scll1(a) scanf(" %I64d",&a)
#define scll2(a,b) scanf(" %I64d %I64d",&a,&b)
#define scll3(a,b,c) scanf(" %I64d %I64d %I64d",&a,&b,&c)
#define sci1(a) scanf(" %d",&a)
#define sci2(a,b) scanf(" %d %d",&a,&b)
#define sci3(a,b,c) scanf(" %d %d %d",&a,&b,&c)
#define scd1(a) scanf(" %lf",&a)
#define scd2(a,b) scanf(" %lf %lf",&a,&b)
#define scd3(a,b,c) scanf(" %lf %lf %lf",&a,&b,&c)
#define sz(a) a.size()
#define ll long long
#define ull unsigned long long
#define dd double
#define prnttc printf("Case %d: ",t++)
#define prnttcn printf("Case %d:\n",t++)
using namespace std;

template<class T1> void deb(T1 e)
{
    cout<<e<<endl;
}
template<class T1,class T2> void deb(T1 e1,T2 e2)
{
    cout<<e1<<" "<<e2<<endl;
}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3)
{
    cout<<e1<<" "<<e2<<" "<<e3<<endl;
}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4)
{
    cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;
}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5)
{
    cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<endl;
}
template<class T1,class T2,class T3,class T4,class T5,class T6> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6)
{
    cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<endl;
}
//template <class T> T lcm(T a, T b){return (a/__gcd(a,b)) * b;}
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
//int X[]={0,-1,-1,-1,0,1,1,1};
//int Y[]={-1,-1,0,1,1,1,0,-1};
//int X[]={-1,0,1,0};
//int Y[]={0,1,0,-1};
//int X[]={1,1,2,2,-1,-1,-2,-2};//knight move//
//int Y[]={2,-2,1,-1,2,-2,1,-1};//knight move//


#define mt
const long long mod = 1000000007;

#define SIZE_N 46500
#define SIZE_P 4810

bool flag[SIZE_N];
int primes[SIZE_P];

ll bigmod(ll B,ll P,ll M)
{
    ll R=1;
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

ll inversemodulo(ll B, ll M)
{
    return bigmod(B,M-2,M);
}

int seive()
{
    int i,j,total=0,val;
    for(i=2;i<=SIZE_N;i++)
    {
        flag[i]=true;
    }
    val = sqrt(SIZE_N)+1;
    for(i=2;i<val;i++)
    {
        if(flag[i])
        {
            for(j=i;j*i<=SIZE_N;j++)
            {
                flag[i*j]=false;
            }
        }
    }
    for(i=2;i<=SIZE_N;i++)
    {
        if(flag[i])
        {
            primes[total++]=i;
        }
    }
    return total;
}

ll sum_of_div(ll N,ll m)
{
    ll val,cunt,a,b,tot=1;
    val = sqrt(N)+1;
    for(int i=0;primes[i]<val;i++)
    {
        cunt=0;
        if(N%primes[i]==0)
        {

            while(N%primes[i]==0)
            {
                N/=primes[i];
                cunt++;
            }
            a = bigmod(primes[i],(cunt*m)+1,mod);
            a = (a-1+mod)%mod;
            b = inversemodulo(primes[i]-1,mod);
            tot = (((a*tot)%mod)*b)%mod;
            val = sqrt(N)+1;
        }
    }
    if(N>1)
    {
        a = bigmod(N,m+1,mod);
        a = (a-1+mod)%mod;
        b = inversemodulo(N-1,mod);
        tot = (((a*tot)%mod)*b)%mod;
    }
    return tot;
}

int main ()
{
    int total = seive();
    int T,t=1,n,m;
    sci1(T);
    while(T--)
    {
        sci2(n,m);
        prnttc;
        pf("%lld\n",sum_of_div(n,m));
    }
    return 0;
}

