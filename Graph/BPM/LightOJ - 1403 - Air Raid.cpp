#include<bits/stdc++.h>
using namespace std;

#define LM 2008

int par[LM];
bool c[LM];
vector<int> G[LM];

bool dfs(int u) {
    if(c[u])return false;
    c[u] = true;
    for(int i=0; i<G[u].size(); ++i) {
        int v = G[u][i];
        if(par[v]==-1||dfs(par[v])) {
            par[v]=u;
            return true;
        }
    }
    return false;
}

int max_bpm(int n) {
    int ans = 0;
    memset(par,-1,sizeof(par));
    for(int i=0; i<n; ++i) {
        memset(c,0,sizeof(c));
        if(dfs(i))ans++;
    }
    return ans;
}

int main() {
    int T,t=1,n,m,u,v;
    scanf("%d",&T);
    while(T--) {
        scanf("%d %d",&n,&m);
        for(int i=0; i<=2*n+1; ++i)G[i].clear();
        for(int i=0; i<m; ++i) {
            scanf("%d %d",&u,&v);
            u = 2*u;
            v = 2*v+1;
            G[u].push_back(v);
        }

        printf("Case %d: %d\n",t++,n-max_bpm(2*n+1));
    }
    return 0;
}

/*

input:
1
10 10
1 2
2 3
3 4
5 6
6 7
7 8
9 7
6 2
2 10
7 3
output:
Case 1: 4

*/
