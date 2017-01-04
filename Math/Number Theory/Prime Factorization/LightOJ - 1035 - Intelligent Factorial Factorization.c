#include<string.h>
#include<math.h>
#include<stdio.h>
//using namespace std;
int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97,101,};
int pOw[110][110];
int base;
void prime_factor(int n)
{
    int m = n;
    base=0;
    int i;
    for(i=0; primes[i]<=sqrt(n); i++)
    {
        while(n%primes[i]==0)
        {
            n/=primes[i];
            pOw[m][primes[i]]++;
        }
    }
    if(n>1)
    {
        base=n;
        pOw[m][base]++;
    }
}

int ans[110];

int main()
{

    //prime_factor(12);
    int i,j;
    for(i=2; i<=100; i++)
    {
        prime_factor(i);
    }
    int T,t=1,n;
    scanf("%d",&T);
    while(T--)
    {
        memset(ans,0,sizeof(ans));
        scanf("%d",&n);
        for(i=2; i<=n; i++)
        {
            for(j=0; j<26; j++)
            {
                if(pOw[i][primes[j]])ans[primes[j]]+=pOw[i][primes[j]];
            }
        }
        printf("Case %d: %d =",t++,n);
        int cnt = 0;
        for(i=0; i<26; i++)if(ans[primes[i]])cnt++;
        for(j=0; j<26; j++)
        {
            if(ans[primes[j]])
            {
                printf(" %d (%d)",primes[j],ans[primes[j]]);
                cnt--;
                if(cnt)printf(" *");
            }
        }
        printf("\n");
    }
    return 0;
}
