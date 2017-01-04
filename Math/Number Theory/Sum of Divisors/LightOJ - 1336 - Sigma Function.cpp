#include<stdio.h>
#include<math.h>
#define sf scanf
#define pf printf
#define ll long long
/**
    Lets consider the naive approach to attack the problem. Here, we will have
    to find, how many integers from 1 to n have even value of sigma, where
    sigma(m) is the summation of the divisors of m. It can also be expressed
    by the following:
    sigma(m) = ((p1^(e1+1)-1)/(p1-1))*((p2^(e2+1)-1)/(p2-1))*...*((pk^(ek+1)-1)/(pk-1))
    where, p1, p2, ...,pk are the prime factors of m and and e1,e2,...,ek are
    the corresponding powers of primes.
    Now, let think about one term instead of k. It can be written:
    (p1^(e1+1)-1)/(p1-1) = (p1-1)(p1^e1+p1^(e1-1)+p1^(e1-2)+...+p1^0)/(p1-1)
                                 = (p1^e1+p1^(e1-1)+p1^(e1-2)+...+1)
                                 [because: a^n-b^n = (a-b)(a^(n-1)+(a^(n-2))*(b)+(a^(n-3))*(b^2)+.....+b^(n-1)]
    In sigma(m), if any of the terms become even then sigma(m) would be even.
    At first we would think about primes other than 2. We would think about
    this very first prime later.
    From the expansion of a term, we found that
    (pi^ei+pi^(ei-1)+pi^(ei-2)+...+1) would be even, if ei would be odd.
    Similarly, (pi^ei+pi^(ei-1)+pi^(ei-2)+...+1) would be odd, if ei would be
    even.
    Lets think reversely. sigma(m) would be odd if and only if all of the
    terms in sigma(m) would be odd. If we could find out the number of number
    which have odd sigma value, then we would be able to find out the answer
    by subtracting it from n.
    Now, lets think a number K which may have prime factor having odd power.
    Now, K^2 have the same prime factors as K, but with even powers only.
    The very first prime 2 was out of consideration till now. Now, think
    about the prime 2. The term with this number would always be odd, however
    the power. e.g. 2^0-1=0, 2^1-1=1, 2^2-1=3 etc. So, we have to find out the
    numbers 2^i * K^2, where i ranges 1 to 40 and K is an odd number.
    This solution would work but would have chance to get MLE if not
    implemented optimally.
    However, This problem has a O(1) solution.
    lets n1 is a number which has even power of number 2 in its factorization.
    So, n1 = 2^(2i)*P^2
    n1 = (2^i * P)^2
    2^i * P = n1^0.5 where i ranges from 0 to x.
    lets n2 is a number which has odd power of number 2 in its factorization.
    So, n2 = 2^(2i+1)*P^2
    n2/2 = 2^(2i)*P^2
    n2/2 = (2^i * P)^2
    2^i * P = (n1/2)^0.5 where i ranges from 0 to x.
    So, the answer is n - n1 - n2 = n - (2^i * P)^2 - (2^i * P)^2.


    Example:
    for n = 10
    1 = 2^0*3^0*5^0*7^0     ((2^(2i))*(p)^2 formate)
    2 = 2^1*3^0*5^0*7^0     ((2^(2i+1))*(p)^2 formate)
    3 = 2^0*3^1*5^0*7^0     (solution)
    4 = 2^2*3^0*5^0*7^0     ((2^(2i))*(p)^2 formate)
    5 = 2^0*3^0*5^1*7^0     (solution)
    6 = 2^1*3^1*5^0*7^0     (solution)
    7 = 2^0*3^0*5^0*7^1     (solution)
    8 = 2^0*3^0*5^0*7^0     ((2^(2i+1))*(p)^2 formate)
    9 = 2^0*3^2*5^0*7^0     ((2^(2i))*(p)^2 formate)
    10 = 2^0*3^0*5^0*7^0    (solution)

    total number = 10;
    total number of (2^(2i))*(p)^2 formate numbers sqrt(10) = 3;
    total number of (2^(2i+1))*(p)^2 formate numbers sqrt(10/2) = sqrt(5) = 2;
    ans = 10-3-2=5
*/

int main()
{
    ll n,T,t=1;
    sf("%lld",&T);
    while(T--)
    {
        sf("%lld",&n);
        pf("Case %lld: %lld\n",t++,(ll)n - (ll)sqrt(n*1.0) - (ll)sqrt(n/2.0));
    }
}
