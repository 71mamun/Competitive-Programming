#include<algorithm>
#include<sstream>
#include<iostream>
#include<iomanip>
#include<climits>
#include<cstring>
#include<cassert>
#include<utility>
#include<limits>
#include<cstdio>
#include<string>
#include<vector>
#include<bitset>
#include<stack>
#include<ctime>
#include<queue>
#include<cmath>
#include<map>
#include<set>
using namespace std;
typedef long long ll;
typedef unsigned long long  ull;
#define     mem(a,b)        memset(a,b,sizeof(a))
#define     sf              scanf
#define     pf              printf
#define     inf             (0x7f7f7f7f)//>2e9
#define     fore(x,i)       for(typeof((x).begin()) i=(x.begin()); i!=(x).end(); ++i)
#define     rfore(x,i)      for(typeof((x).rbegin()) i=(x.rbegin()); i!=(x).rend(); ++i)
template<typename T> inline bool is_set(T &mask,int pos){return((mask)&(1LL<<pos));}
template<typename T> inline T setf(T mask,int pos){return mask=((mask)&(~(1LL<<pos)));}
template<typename T> inline T sett(T mask,int pos){return mask=((mask)|(1LL<<pos));}
template<typename T> inline T flip(T mask,int pos){return mask=((mask)^(1LL<<pos));}
///HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
int N;
int MXR,MNC;
int row_mask[20];
int dp[20][20][20];

int sol(int r,int pmask,int gvn);

int gen(int r,int c,int pmask,int cmask,int gvn)
{
    if(c==MNC)return sol(r+1,cmask,gvn);
    int ans = inf;
    int bad = 0;
    if(c>0 and is_set(cmask,c-1))bad++;
    if(is_set(pmask,c))bad++;
    ans = min(ans,gen(r,c+1,pmask,sett(cmask,c),gvn-1)+bad);
    ans = min(ans,gen(r,c+1,pmask,cmask,gvn));
    return ans;
}

int sol(int r,int pmask,int gvn)
{
    if(r==MXR) return (gvn==0?0:inf);
    int &ans = dp[r][pmask][gvn];
    if(~ans)return ans;
    return ans = gen(r,0,pmask,row_mask[r],gvn);
}

int main()
{
//    fread("in.in");
//    fwrite("out.out");
    int T,R,C,t=1;
    sf("%d",&T);
    while(T--)
    {
        mem(dp,-1);
        mem(row_mask,0);
        sf("%d %d %d",&R,&C,&N);
        MNC = min(R,C);
        MXR = max(R,C);
        pf("Case #%d: %d\n",t++,sol(0,0,N));
    }
    return 0;
}


