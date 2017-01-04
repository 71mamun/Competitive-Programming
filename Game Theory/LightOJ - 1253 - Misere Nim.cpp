#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
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

        cout<<"Case "<<t++<<": ";

        if(cnt_one==n)
        {
            cout<<(cnt_one&1?"Bob":"Alice")<<endl;
        }
        else
        {
            cout<<(ans?"Alice":"Bob")<<endl;
        }
    }
    return 0;
}

