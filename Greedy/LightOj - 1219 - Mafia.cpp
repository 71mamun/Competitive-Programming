#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<string.h>
#include<math.h>
using namespace std;
#define sf scanf
#define pf printf
#define pb push_back
#define ms(a,b) memset(a,b,sizeof(a))
const int SZ = 10005;
vector<int>edge[SZ];
bool col[SZ];
int Boys[SZ];
int res;
void init()
{
    ms(col,false);
    for(int i=0;i<SZ;i++)edge[i].clear();
    res = 0;
}

vector<int> DFS(int src)
{
    vector<int>ans;
    vector<int>tmp;
    if(col[src])
    {
        tmp.pb(0);tmp.pb(0);
        return tmp;
    }
    ans.pb(0);ans.pb(0);
    col[src]=true;
    for(int i=0;i<edge[src].size();i++)
    {
        tmp = DFS(edge[src][i]);
        ans[0]+=tmp[0];
        ans[1]+=tmp[1];
    }
    ans[0] = ans[0]+1;
    ans[1] = ans[1]+Boys[src];
    res+=abs(ans[0]-ans[1]);
    tmp.clear();
    return ans;
}


int main()
{
    int T,N,from,boy,m,to;
    sf("%d",&T);
    for(int t=1; t<=T; t++)
    {
        init();
        sf("%d",&N);
        for(int i=0; i<N; i++)
        {
            sf("%d %d %d",&from,&boy,&m);
            for(int j=0; j<m;j++)
            {
                sf("%d",&to);
                edge[from].pb(to);
                edge[to].pb(from);
            }
            Boys[from] = boy;
        }
        DFS(1);
        pf("Case %d: %d\n",t,res);
    }
    return 0;
}
