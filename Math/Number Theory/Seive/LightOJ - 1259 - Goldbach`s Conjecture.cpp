#include<bits/stdc++.h>
using namespace std;
#define LM 664580
#define PLM 10000003
#define For(i,a,b) for(int i=a;i<=b;++i)

bitset<PLM>status;
int prime[LM];

int seive()
{
    status.set();
    For(i,2,sqrt(PLM))
    {
        if(status[i])
        {
            for(int j=i;j*i<PLM;++j)
                status.reset(i*j);
        }
    }
    int idx = 0;
    For(i,2,PLM-1)
    {
        if(status[i])prime[idx++]=i;
    }
    return idx;
}

int main()
{
    int tot = seive(),T,t=1,n;
    scanf("%d",&T);
    while(T--)
    {
        int ans = 0;
        scanf("%d",&n);
        for(int i=0;prime[i]<=n/2;++i)
        {
            if(status[n-prime[i]])ans++;
        }
        printf("Case %d: %d\n",t++,ans);
    }
    return 0;
}
