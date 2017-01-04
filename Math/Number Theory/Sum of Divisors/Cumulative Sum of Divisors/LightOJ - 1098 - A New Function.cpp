#include<stdio.h>
#include<math.h>
typedef long long ll;

#define     sf              scanf
#define     pf              printf


int main()
{
    int T,t=1,n,rt,nbyi;
    ll ans;
    sf("%d",&T);
    while(T--)
    {
        sf("%d",&n);
        ans = 0;
        rt = sqrt(n);
        for(int i=2;i<=rt;++i)
        {
            nbyi = n/i;
            ans+=((nbyi-1LL)*i+(nbyi*(nbyi+1LL)-(rt)*(rt+1LL))/2);
        }
        pf("Case %d: %lld\n",t++,ans);

    }
    return 0;
}

/**

lets calculate for n = 18. brackets included numbers are the actual divisor of that number.
0(), 1(), 2(), 3(), 4(2), 5(0), 6(2,3), 7(), 8(2,4), 9(3), 10(5,2), 11(), 12(2,3,4), 13(), 14(2,7), 15(3,5), 16(2,4,6), 17(), 18(2,3,6,9).
lets see how 3 contribute to CSOD(18). 3 occurs 18/3 times as a divisor of 0 to 18 numbers among them 3 it self should not be counted
because we are calculating actual divisors. now, 3 has 6 multiple in this range. that means 3*1,3*2,3*4.....,3*6 are the numbers
which is divisible by 3 in this range. thats means this 1 to 6 are contributing with 3. floor(sqrt(18)) = 3. less then this limit will be
calculated by loop but range of 4 to 6 should be added as (sum up to 6 - sum up to 4).

*/
