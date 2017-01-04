#include<bits/stdc++.h>
using namespace std;
#define LM 1000010

bool status[LM];
int prime[LM];

int seive()
{
    for(int i=0;i<LM;++i)status[i]=true;
    for(int i=2;i<=sqrt(LM);++i)
    {
        if(status[i])
        {
            for(int j=i;j*i<LM;++j)
            {
                status[i*j]=false;
            }
        }
    }
    int idx = 0;
    ///copy the primes in a new array named "prime"
    for(int i=2;i<LM;++i)
    {
        if(status[i])prime[idx++]=i;
    }
    return idx;
}

int main()
{
    int tot = seive(),n;
    bool ans = false;
    while(cin>>n and n)
    {
        for(int i=0;i<tot;++i)
        {
            if(status[n-prime[i]])
            {
                printf("%d = %d + %d\n",n,prime[i],n-prime[i]);
                ans = true;
                break;
            }
        }
    }
    return 0;
}
