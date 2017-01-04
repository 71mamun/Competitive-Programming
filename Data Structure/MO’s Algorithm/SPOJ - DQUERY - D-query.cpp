#include<bits/stdc++.h>
using namespace std;
#define sf scanf
#define pf printf

#define LM 30007
#define QLM 200007
#define RLM 1000007
int n,q,arr[LM],block,ans,frequency[RLM];
int current_left,current_right,res[QLM];

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

void add(int value)
{
    frequency[value]++;
    if(frequency[value]==1)ans++;
}

void eject(int value)
{
    frequency[value]--;
    if(frequency[value]==0)ans--;
}

info querys[QLM];

int main()
{
    int i;

    sf("%d",&n);

    for(i=0;i<n;++i)
    {
        sf("%d",arr+i);
    }

    sf("%d",&q);

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
        pf("%d\n",res[i]);
    }

    return 0;
}


/*

5
1 1 2 1 3
3
1 5
2 4
3 5

*/
