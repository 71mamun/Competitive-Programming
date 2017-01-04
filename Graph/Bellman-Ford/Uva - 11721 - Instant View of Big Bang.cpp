
#include<bits/stdc++.h>
using namespace std;
#define sz 1010
#define inf (2<<20)
vector<int>G[sz];
int dis[sz];
int col[sz];
int T,N,M,t=1,a,b,c;
struct edge {
    int u,v,w;
    edge(int _, int __, int ___) {
        u=_;
        v=__;
        w=___;
    }
};
vector<edge>edg;

void DFS(int src) {
    col[src]=1;
    for(int i=0; i<G[src].size(); i++) {
        if(!col[G[src][i]])DFS(G[src][i]);
    }
}

bool Bellman_Ford(void) {
    int a,b,c;
    for(int i=1; i<N; i++) {
        for(int j=0; j<M; j++) {
            a=edg[j].u;
            b=edg[j].v;
            c=edg[j].w;
            if(dis[a]+c<dis[b])
                dis[b]=dis[a]+c;
        }
    }
    bool flag = false;
    for(int j=0; j<M; j++) {
        a=edg[j].u;
        b=edg[j].v;
        c=edg[j].w;
        if(dis[a]+c<dis[b])
            if(!col[a])DFS(a),flag = true;
    }
    return flag;
}

int main() {
    scanf("%d",&T);
    while(T--) {
        scanf("%d%d",&N,&M);
        memset(col,0,sizeof(col));
        for(int n=0; n<=N; n++)dis[n]=inf,G[n].clear();
        edg.clear();
        for(int m=0; m<M; m++) {
            scanf("%d%d%d",&a,&b,&c);
            G[b].push_back(a);
            edg.push_back(edge(b,a,c));
        }
        printf("Case %d:",t++);
        if(Bellman_Ford()) {
            for(int i=0; i<N; i++) {
                if(col[i])printf(" %d",i);
            }
            puts("");
        } else puts(" impossible");
    }
    return 0;
}
