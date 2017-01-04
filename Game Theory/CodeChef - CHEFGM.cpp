///https://www.codechef.com/problems/CHEFGM
#include <cstring>
#include <string>
#include <iostream>
#include <cstdio>
#include <vector>
#include <cassert>
#include <algorithm>

using namespace std;
#define MAXN 55

int t,n,tcase;
int arr[MAXN];

double calculate()
{
    double res = 0;
    double value = 1;
    res = (arr[0]%2==0)?value:-value;
    bool is_changed = false;
    for(int i=1; i<n; ++i)
    {
        assert(arr[i]!=arr[i-1]);
        if(arr[i]%2 != arr[i-1]%2)
        {
            is_changed = true;
        }
        if(is_changed) value /= 2;
        res += (arr[i]%2==0)?value:-value;
//        cout<<value<<" "<<res<<endl;
    }
    return res;
}

int main()
{
    for(scanf("%d",&tcase); tcase; tcase-=1)
    {
        scanf("%d",&t);
        double res = 0;
        for(int i=0; i<t; ++i)
        {
            scanf("%d",&n);
            for(int j=0; j<n; ++j) scanf("%d",&arr[j]);
            sort(arr,arr+n);
            res += calculate();
        }
        if(res > 0 ) printf("EVEN\n");
        else if(res < 0 ) printf("ODD\n");
        else printf("DON'T PLAY\n");
    }
    return 0;
}

/*
2
2
2 3 4
2 4 5
1
3 1 2 3
*/
