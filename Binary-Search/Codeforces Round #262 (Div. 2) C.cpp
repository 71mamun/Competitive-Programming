#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define SZ 100000
#define sf scanf
#define pf printf
ll arr[SZ+5],n,m,w;

bool possible(ll banabo)
{
    vector<ll>disilm(n,0);
    ll disi = 0;
    ll done = 0;
    for(ll i =0; i<n; i++)
    {
        if(i>=w)disi-=disilm[i-w];
        if(arr[i]+disi<banabo)
        {
            disilm[i] = banabo-arr[i]-disi;
            done+=disilm[i];
            disi+=disilm[i];
        }
        if(done>m)return false;
    }
    return true;
}

ll binSearch(ll b,ll e)
{
    if(b==e)return (possible(b)?b:-(1<<28));
    ll mid = ((b+e)>>1);
    return (possible(mid)?max(mid,binSearch(mid+1,e)):binSearch(b,mid));
}

int main()
{
    sf("%d %d %d",&n,&m,&w);
    for (int i=0; i<n; i++)
        cin>>arr[i];
    pf("%d\n",binSearch(0,1000000000000));
    return 0;
}
