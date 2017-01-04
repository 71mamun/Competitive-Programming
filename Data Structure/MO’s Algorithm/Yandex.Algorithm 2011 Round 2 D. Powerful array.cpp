#include<bits/stdc++.h>
using namespace std;
#define sf scanf
#define pf printf
typedef long long ll;

#define LM 200007
#define QLM 200007
#define RLM 1000007
int n,q,arr[LM],block;
int current_left,current_right,frequency[RLM];
ll ans,res[QLM];

struct info
{
    int l,r,idx;
};


bool cmp(info a,info b)
{
    if(a.l/block!=b.l/block)
        return (a.l/block<b.l/block);
    return a.r<b.r;
}

void add(ll value)
{
    frequency[value]++;
    ans+=value*(2*frequency[value]-1);
}

void eject(ll value)
{
    ans-=value*(2*frequency[value]-1);
    frequency[value]--;
}

info querys[QLM];

int main()
{
    int i;

    sf("%d %d",&n,&q);

    for(i=0;i<n;++i)
    {
        sf("%d",arr+i);
    }

    for(i=0;i<q;++i)
    {
        sf("%d %d",&querys[i].l,&querys[i].r);
        querys[i].idx = i;
        querys[i].l--;
        querys[i].r--;
    }

    ans = 0;
    block = sqrt(n);
    current_left = 0;current_right = -1;
    sort(querys,querys+q,cmp);

    for(i=0;i<q;++i)
    {
        info now = querys[i];

        while(current_left<now.l)
        {
            eject(arr[current_left++]);
        }
        while(current_left>now.l)
        {
            add(arr[--current_left]);
        }
        while(current_right<now.r)
        {
            add(arr[++current_right]);
        }
        while(current_right>now.r)
        {
            eject(arr[current_right--]);
        }

        res[now.idx] = ans;

    }

    for(i=0;i<q;++i)
    {
        pf("%I64d\n",res[i]);
    }

    return 0;
}


/*

8 3
1 1 2 2 1 3 1 1
2 7
1 6
2 7

*/

