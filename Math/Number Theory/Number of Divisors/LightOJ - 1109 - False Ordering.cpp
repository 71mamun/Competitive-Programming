/**
    Bismillah hir-Rahman nir-Raheem
    In the name of Allah, the Most Gracious, the Ever Merciful.
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

using namespace std;

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
#define PTC pf("Case %lld: ",t++);

template<class T1> void deb(T1 e){cout<<e<<endl;}
template<class T1,class T2> void deb(T1 e1,T2 e2){cout<<e1<<" "<<e2<<endl;}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3){cout<<e1<<" "<<e2<<" "<<e3<<endl;}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<endl;}
template<class T1,class T2,class T3,class T4,class T5,class T6> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<endl;}
//template <class T> T lcm(T a, T b){return (a/__gcd(a,b)) * b;}
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
//int X[]={0,-1,-1,-1,0,1,1,1};//king move//
//int Y[]={-1,-1,0,1,1,1,0,-1};//king move//
//int X[]={-1,0,1,0};//4 direction move//
//int Y[]={0,1,0,-1};//4 direction move//
//int X[]={1,1,2,2,-1,-1,-2,-2};//knight move//
//int Y[]={2,-2,1,-1,2,-2,1,-1};//knight move//

#define mt
#define mod

#define SIZE_N 1010
#define SIZE_P 170

struct info
{
    ll num;
    ll numOfDiv;
    info(ll _,ll __)
    {
        num=_;numOfDiv=__;
    }
};

bool flag[SIZE_N];
ll primes[SIZE_N];

ll seive()
{
    ll i,j,total = 0,val;

    for(i=2;i<=SIZE_N;i++)flag[i]=1;

    val = sqrt(SIZE_N)+1;

    for(i=2;i<val;i++)
    {
        if(flag[i])
        {
            for(j=i;j*i<=SIZE_N;j++)
            {
                flag[i*j]=0;
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


ll divisor(ll N)
{
    int i,val,count,sum;

    val = sqrt(N)+1;
    sum=1;
    for(i=0;primes[i]<val;++i)
    {
        if(N%primes[i]==0)
        {
            count = 0;
            while(N%primes[i]==0)
            {
                N/=primes[i];
                count++;
            }
            sum*=(count+1);
        }
    }
    if(N>1)sum = sum*2;
    return sum;
}

bool comp(info a,info b)
{
    return (a.numOfDiv==b.numOfDiv?a.num>b.num:a.numOfDiv<b.numOfDiv);
}


vector<info>store;

int main ()
{
    ll total = seive();

    store.pb(info(1,1));
    for(ll i=2;i<=1000;++i)
    {
        ll u = divisor(i);
        store.pb(info(i,u));
    }

    sort(store.begin(),store.end(),comp);

    ll T,t=1,n;

    sf("%lld",&T);
    while(T--)
    {
        sf("%lld",&n);
        PTC;
        pf("%lld\n",store[n-1].num);
    }
    return 0;
}
