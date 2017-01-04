#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    int n,T,tmp,t=1,cnt_one;
    cin>>T;
    while(T--)
    {
        cnt_one = 0;
        cin>>n;
        int ans = 0;
        for(int i=0;i<n;++i)
        {
            cin>>tmp;
            if(tmp==1)
            {
                cnt_one++;
            }
            ans^=tmp;
        }

        if(cnt_one==n)
        {
            cout<<(cnt_one&1?"Second":"First")<<endl;
        }
        else
        {
            cout<<(ans?"First":"Second")<<endl;
        }
    }
    return 0;
}

