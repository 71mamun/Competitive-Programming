    #include<bits/stdc++.h>
    #define SZ 503
    #define inf 99999999
     
    using namespace std;
     
    struct node
    {
        int u,w;
        node(int a,int b){u=a;w=b;}
        bool operator<(const node&p)const{return w>p.w;}
    };
     
    vector<int>G[SZ];
    vector<int>C[SZ];
    int D[SZ];
    int par[SZ];
     
    void dijsktra(int src)
    {
        priority_queue<node>Q;
        memset(par,-1,sizeof(par));
        for(int i=0; i<SZ; i++)D[i]=inf;
        D[src]=0;
        Q.push(node(src,D[src]));
        while(!Q.empty())
        {
            node top = Q.top();
            Q.pop();
            int u = top.u;
            for(int i=0; i<G[u].size(); i++)
            {
                int v = G[u][i];
                if(D[v]>max(D[u],C[u][i]))
                {
                    D[v]=max(D[u],C[u][i]);
                    par[v]=u;
                    Q.push(node(v,D[v]));
                }
            }
        }
    }
     
    int main()
    {
        int T,u,v,w,N,M,src;
        scanf("%d",&T);
        for(int t=1; t<=T; t++)
        {
            scanf("%d %d",&N,&M);
            for(int m=0; m<M; m++)
            {
                scanf("%d %d %d",&u,&v,&w);
                G[u].push_back(v);
                G[v].push_back(u);
                C[u].push_back(w);
                C[v].push_back(w);
            }
            scanf("%d",&src);
            dijsktra(src);
            printf("Case %d:\n",t);
            for(int i=0; i<N; i++)
            {
                if(D[i]==inf)printf("Impossible\n");
                else printf("%d\n",D[i]);
            }
            for(int n=0; n<N; n++)
            {
                G[n].clear();
                C[n].clear();
            }
        }
        return 0;
    }
     
