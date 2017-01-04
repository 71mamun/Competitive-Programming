#include <iostream>
#include <stdio.h>
#include <algorithm>
#define sz 100020
using namespace std;

int num[sz];

int main()
{
    int mx=0, n, t, cas=1, pre;
    scanf("%d", &t);
    while(t--)
    {
        num[0]=0;
        mx = 0;
        scanf("%d", &n);
        for (int i = 1; i<=n; i++)
        {
            scanf("%d", &num[i]);
            mx = max(mx, num[i]-num[i-1]);
        }
        pre = mx;

        for (int i = 1; i<=n; i++)
        {
            if(num[i]-num[i-1]==pre) pre--;
            else if (num[i]-num[i-1]>=pre) pre = -1;
        }
        if(pre>=0) printf("Case %d: %d\n",cas++, mx);
        else printf("Case %d: %d\n",cas++, mx+1);

    }
    return 0;
}
