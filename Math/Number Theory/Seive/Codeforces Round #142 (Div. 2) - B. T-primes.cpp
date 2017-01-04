#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>
using namespace std;
#define SZ 1000005
bool flag[SZ];
vector<int>primes;

void seive()
{
    int l = sqrt(SZ)+1;
    for(int i=2; i<SZ; i++)flag[i] = true;
    for(int i=2; i<l; i++)
    {
        if(flag[i])
        {
            for(int j=i; j*i<=SZ; j++)
            {
                flag[i*j] = false;
            }
        }
    }
    for(int i=2,ind = 0; i<=SZ; i++)
    {
        if(flag[i])
        {
            primes.push_back(i);
        }
    }
}

int main()
{
    int n;
    long long tmp;
    cin>>n;
    seive();
    for(int i=0; i<n; i++)
    {
        cin>>tmp;
        double sr = sqrt((double)tmp);
        if(sr==(int)sr&&binary_search(primes.begin(),primes.end(),sr))
        {
            cout<<"YES"<<endl;
        }
        else cout<<"NO"<<endl;
    }
    return 0;
}
