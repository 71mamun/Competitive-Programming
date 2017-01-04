#include<bits/stdc++.h>
#define SZ 10010
using namespace std;
int M,N,A;
struct edge {
    int u,v,w;
    edge(int _,int __,int ___) {
        u=_;v=__;w=___;
    }
    bool operator < (const edge& p) const {
        return w<p.w;
    }
};

vector<edge>e;
set<int>dif;
int par[SZ];

int get_par(int r) {
    return (par[r]==r?r:par[r]=get_par(par[r]));
}

int MST(int N) {
    sort(e.begin(),e.end());
    for(int i=0; i<=N; i++)
        par[i]=i;
    int s=0;
    for(int i=0; i<e.size(); i++) {
        int u=get_par(e[i].u);
        int v=get_par(e[i].v);
        if(u!=v&&e[i].w<A) {
            par[u]=v;
            s+=e[i].w;
        }
    }
    return s;
}

int main() {
    int u,v,w,T,t=1;
    cin>>T;
    while(T--) {
        cin>>N>>M>>A;
        for(int m=0; m<M; m++) {
            cin>>u>>v>>w;
            e.push_back(edge(u,v,w));
        }
        int ans=MST(N);
        int tmp;
        for(int i=1; i<=N; i++) {
                tmp = get_par(i);
            if(dif.find(tmp)==dif.end()) {
                dif.insert(tmp);
            }
        }
        cout<<"Case #"<<t++<<": "<<dif.size()*A+ans<<" "<<dif.size()<<endl;
        e.clear();dif.clear();
    }
    return 0;
}
