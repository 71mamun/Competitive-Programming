#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,a,b;

// C function for extended Euclidean Algorithm
ll gcdExtended(ll a, ll b, ll *x, ll *y)
{
    // Base Case
    if (a == 0)
    {
        *x = 0;
        *y = 1;
        return b;
    }

    ll x1, y1; // To store results of recursive call
    ll gcd = gcdExtended(b%a, a, &x1, &y1);

    // Update x and y using results of recursive
    // call
    *x = y1 - (b/a) * x1;
    *y = x1;

    return gcd;
}


int main()
{
    ll T,c,d,x,k;
    cin>>T;
    while(T--)
    {
        cin>>x>>k;
        ll a = x/k,b = ceil(x/double(k));
        ll g = gcdExtended(a,b,&c,&d);
        cout<<c*(x/g)<<" "<<d*(x/g)<<endl;
    }
}
