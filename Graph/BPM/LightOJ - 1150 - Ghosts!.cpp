#include<bits/stdc++.h>
using namespace std;

#define LM 30
#define pii pair<int,int>
#define mp make_pair
#define fs first
#define sc second
#define inf (1e9)
#define pb push_back
#define sz size()

int par[LM*LM],n;
bool c[LM*LM];
char grid[LM][LM];
int dis[LM][LM];
vector<int> G[LM*LM];
vector<int> W[LM*LM];
int X[]= {-1,0,1,0},Y[]= {0,1,0,-1};

int get_node(int r,int c) {
    return r*n+c;
}

pii get_row_col(int u) {
    return mp(u/n,u%n);
}

bool dfs(int u,int max_dis) {
    if(c[u])return false;
    c[u] = true;
    for(int i=0; i<G[u].size(); ++i) {
        int v = G[u][i];
        pii pp = get_row_col(u),cc = get_row_col(v);
        if(2*W[u][i]+2>max_dis)continue;
        if(par[v]==-1||dfs(par[v],max_dis)) {
            par[v]=u;
            return true;
        }
    }
    return false;
}

int max_bpm(int n,int max_dis) {
    int ans = 0;
    memset(par,-1,sizeof(par));
    for(int i=0; i<n; ++i) {
        memset(c,0,sizeof(c));
        if(dfs(i,max_dis))ans++;
    }
    return ans;
}

struct node {
    int  r,c,w;
    node(int  a,int  b,int ww) {
        r=a;
        c=b;
        w=ww;
    }
    bool operator<(const node& p)const {
        return w>p.w;
    }
};

void dijsktra(int  sr,int sc) {
    priority_queue<node>Q;

    for(int  i=0; i<n; i++)
        for(int  j=0; j<n; j++)
            dis[i][j]=inf;

    dis[sr][sc]=0;
    Q.push(node(sr,sc,dis[sr][sc]));

    while(!Q.empty()) {
        node top = Q.top();
        Q.pop();
        int  ur = top.r, uc = top.c;
        for(int  i=0; i<4; i++) {
            int  vr = ur+X[i], vc = uc+Y[i];

            if(vr<0||vr>=n||vc<0||vc>=n||grid[vr][vc]=='#')continue;
            if(dis[vr][vc]>dis[ur][uc]+1) {
                dis[vr][vc]=dis[ur][uc]+1;
                Q.push(node(vr,vc,dis[vr][vc]));
            }
        }
    }

    int u = get_node(sr,sc);

    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j) {
            if(grid[i][j]=='H') {
                int v = get_node(i,j);
                G[u].pb(v);
                W[u].pb(dis[i][j]);
            }
        }
    }
}


int main() {
    int T,t=1,m,u,v;
    scanf("%d",&T);
    while(T--) {

        int human = 0;
        scanf("%d",&n);

        for(int i=0; i<n; ++i) {
            for(int j=0; j<n; ++j) {
                scanf(" %c",&grid[i][j]);
                if(grid[i][j]=='H')human++;
            }
        }

        for(int i=0; i<n; ++i) {
            for(int j=0; j<n; ++j) {

                if(grid[i][j]=='G') {
                    dijsktra(i,j);
                }
            }
        }

        int hi = 200,lo = 0,ans = inf;
        while(lo<=hi){
            int mid = (hi+lo)/2;
            int loc = max_bpm(n*n,mid);

            if(loc==human){
                ans = mid;
                hi = mid-1;
            }
            else {
                lo = mid+1;
            }
        }

        if(ans<500)printf("Case %d: %d\n",t++,ans);
        else printf("Case %d: Vuter Dol Kupokat\n",t++);

        for(int i=0;i<n*n;++i)G[i].clear();
        for(int i=0;i<n*n;++i)W[i].clear();

    }
    return 0;
}

/*
2
2
H.
.G
4
GGGG
GHGG
GGGG
GGGG
*/
