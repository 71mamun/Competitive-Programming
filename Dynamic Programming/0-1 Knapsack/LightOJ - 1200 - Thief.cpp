#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>

using namespace std;

#define PTC printf("Case %d: ",t)
#define PB(r) push_back(r)
#define maxObj 105
#define maxWeight 10005

struct item
{
    int price;
    int must;
    int weight;
};

vector<item>obj;
int n,W;
int DP[maxObj][maxWeight];


int solve(int i,int avil)
{
    if(i>=n)return 0;
    int &ret = DP[i][avil];
    if(ret!=-1)return ret;
    int takenProfit = 0;
    int repetProfit = 0;
    if(obj[i].weight<=avil)
    {
        repetProfit = obj[i].price + solve(i,avil-obj[i].weight);
        takenProfit = obj[i].price + solve(i+1,avil-obj[i].weight);
    }
    int ignoreProfit = solve(i+1,avil);
    return ret = max(takenProfit,max(ignoreProfit,repetProfit));
}

int main()
{
    int T;
    item tmp;
    int mustWeight;
    cin>>T;
    for(int t=1; t<=T; t++)
    {
        memset(DP,-1,sizeof(DP));
        obj.clear();
        mustWeight = 0;
        scanf("%d%d",&n,&W);
        for(int i=0; i<n; i++)
        {
            scanf("%d%d%d",&tmp.price,&tmp.must,&tmp.weight);
            mustWeight += tmp.must*tmp.weight;
            obj.PB(tmp);
        }
        if(mustWeight>W)
        {
            PTC;
            printf("Impossible\n");
            continue;
        }
        int w=W-mustWeight;
        PTC;
        printf("%d\n",solve(0,w));
    }
    return 0;
}

