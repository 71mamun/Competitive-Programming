#include<bits/stdc++.h>
using namespace std;
#define SZ 100010
#define sz 9600
int primes[sz];
int tmp[SZ];
int pOw[100003];
int base;

int power(int b ,int p)
{
    int ans=1;
    for(int i=0;i<p;i++)
    {
        ans *= b;
    }
    return ans;
}


void seive(void)
{
    tmp[1]=tmp[0]=1;
    for(int i=2; i<SZ; i++)
    {
        if(!tmp[i])
        {
            for(int j=2; j*i<SZ; j++)
            {
                tmp[j*i]=1;
            }
        }
    }
    int k=0;
    for(int i=0; i<SZ; i++)
    {
        if(!tmp[i])primes[k++]=i;
    }
}


void prime_factor(int n)
{
    base=0;
    memset(pOw,0,sizeof(pOw));
    for(int i=0; primes[i]<=sqrt(n); i++)
    {
        while(n%primes[i]==0)
        {
            n/=primes[i];
            pOw[primes[i]]++;
        }
    }
    if(n>1)
    {
        base=n;
    }
}

int phi(int n)
{
    prime_factor(n);
    int ans=1;
    for(int i=0; primes[i]<=sqrt(n); i++)
    {
        if(pOw[primes[i]])
        {
            ans*=(primes[i]-1);
            ans*=power(primes[i],(pOw[primes[i]]-1));
        }
    }
    if(base){ans*=(base-1);}
    return ans;
}

int main()
{
    int n;
    seive();
    while(cin>>n&&n)
    {
        cout<<phi(n)<<endl;
    }
    return 0;
}
