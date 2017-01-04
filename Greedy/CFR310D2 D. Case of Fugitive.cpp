#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll ,ll>
#define LM 200007
#define fs first
#define sc second
#define mp make_pair

struct info
{
    ll l,r,i;
    info(ll a,ll b,ll c)
    {
        l = a;r = b,i = c;
    }
};

vector< info >rang;
pii point[LM];
ll output[LM];

set< pii >bridgesz;

bool cmp(info a,info b)
{
    if(a.r!=b.r)return a.r<b.r;
    return a.l<b.l;
}

bool cmp2(pii a,pii b)
{
    if(a.fs!=b.fs)return a.fs<b.fs;
    return a.sc<b.sc;
}

int main()
{
    ll n,m,pl,pr,nl,nr,tmp;
    cin>>n>>m;
    cin>>pl>>pr;
    for(int i=0;i<n-1;++i)
    {
        cin>>nl>>nr;
        ll mn = nl-pr;
        ll mx = nr-pl;
        rang.push_back(info(mn,mx,i));
        pr = nr;
        pl = nl;
    }
    sort(rang.begin(),rang.end(),cmp);

    for(int i=0;i<m;++i)
    {
        cin>>tmp;
        bridgesz.insert(mp(tmp,i));

    }
    int j = 0;
    for(int i=0;i<n-1;++i)
    {
        auto lb = bridgesz.lower_bound(mp(rang[i].l,0));
        if(lb == bridgesz.end() || (*lb).fs>rang[i].r)
        {
            cout<<"No\n";
            return 0;
        }
        output[rang[i].i] = (*lb).sc;
        bridgesz.erase(*lb);
    }

    cout<<"Yes"<<endl;
    for(int i=0;i<n-1;++i)
    {
            cout<<output[i]+1<<" ";
    }

    return 0;
}

/*

3 2
1 4
5 6
8 8
1 3

*/
