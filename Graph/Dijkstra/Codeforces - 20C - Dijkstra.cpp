#include<bits/stdc++.h>
#define SZ 100005
#define inf 999999999999999

using namespace std;

struct node
{
    long long u,w;
    node(long long a,long long b){u=a;w=b;}
    bool operator<(const node& p)const{return w>p.w;}
};

vector<int>graph[SZ];
vector<int>cost[SZ];
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
    long long N,E,x,y,z;
    cin>>N>>E;
    for(long long i=0; i<E; i++)
    {
        cin>>x>>y>>z;
        graph[x].push_back(y);
        graph[y].push_back(x);
        cost[x].push_back(z);
        cost[y].push_back(z);
    }
    dijsktra(1);
    vector<int>ans;
    if(par[N]==-1)
    {
        cout<<-1<<endl;
    }
    else
    {
        long long n=N;
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
    }
    return 0;
}