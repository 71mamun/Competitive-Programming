#include<bits/stdc++.h>
#define SZ 100005
#define inf 999999999999999

using namespace std;

struct node
{
    long long u,w;
    node(long long a,long long b)
    {
        u=a;
        w=b;
    }
    bool operator<(const node& p)const
    {
        return w>p.w;
    }
};

vector<long long>graph[SZ];
vector<long long>cost[SZ];
long long par[SZ];
long long dis[SZ];

void dijsktra(long long src)
{
    priority_queue<node>Q;
    for(long long i=0; i<SZ; i++)dis[i]=inf;
    memset(par,-1,sizeof(par));
    dis[src]=0;
    Q.push(node(src,dis[src]));
    while(!Q.empty())
    {
        node top = Q.top();
        Q.pop();
        long long u=top.u;
        for(long long i=0; i<graph[u].size(); i++)
        {
            long long v=graph[u][i];
            if(dis[v]>dis[u]+cost[u][i])
            {
                dis[v]=dis[u]+cost[u][i];
                par[v]=u;
                Q.push(node(v,dis[v]));
            }
        }
    }
}

int main()
{
    long long N,E,x,y,z,T=1;
    while(cin>>N&&N)
    {

        for(long long j=1; j<=N; j++)
        {
            cost[j].clear();
            graph[j].clear();
            cin>>E;
            for(long long i=0; i<E; i++)
            {
                cin>>y>>z;
                graph[j].push_back(y);
                cost[j].push_back(z);
            }
        }
        long long  src,finish;
        cin>>src>>finish;
        dijsktra(src);
        vector<long long>ans;
        printf("Case %lld: Path = ",T++);
        long long n=finish;
        ans.push_back(n);
        while(par[n]!=-1)
        {
            ans.push_back(par[n]);
            n=par[n];
        }
        reverse(ans.begin(),ans.end());
        for(long long i=0; i<ans.size(); i++)
        {
            if(i<ans.size()-1)
                cout<<ans[i]<<" ";
            else cout<<ans[i];
        }
        printf("; %lld second delay\n",dis[finish]);
    }
    return 0;
}
