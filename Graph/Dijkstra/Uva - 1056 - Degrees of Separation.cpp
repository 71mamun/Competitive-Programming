#include<bits/stdc++.h>
using namespace std;
#define sz 55
vector<int>G[sz];
vector<int>alu;
int taken[sz];
int dis[sz];
int hakau[sz];
int ans;

bool check(int N)
{
    for(int i= 0;i<N;i++)if(taken[i]!=1)return false;
    return true;
}

void Dijkstra(int src)
{
    queue<int>Q;
    Q.push(src);
    memset(taken,0,sizeof(taken));
    taken[src]=1;
    dis[src]=0;
    while(!Q.empty())
    {
        int u=Q.front();
        Q.pop();
        for(int i=0; i<G[u].size(); i++)
        {
            int v=G[u][i];
            if(!taken[v])
            {
                Q.push(v);
                dis[v]=dis[u]+1;
                taken[v]=1;
                if(dis[ans]<dis[v])ans=v;
            }
        }
    }
}
int main()
{
    int E,N,T=1;
    string u,v;
    map<string,int>vos;
    while(cin>>N>>E&&E+N)
    {
        vos.clear();
        memset(dis,0,sizeof(dis));
        int l=0;
        for(int e=0; e<E; e++)
        {
            cin>>u>>v;
            if(vos.find(u)==vos.end())vos[u]=l++;
            if(vos.find(v)==vos.end())vos[v]=l++;
            G[vos[u]].push_back(vos[v]);
            G[vos[v]].push_back(vos[u]);
        }
        Dijkstra(vos[u]);
        for(int i=0;i<N;i++)
        {
            if(dis[i]==dis[ans])alu.push_back(i);
        }
        int tmp = -1;
        for(int i=0;i<alu.size();i++)
        {
            Dijkstra(alu[i]);
            tmp = max(tmp,dis[ans]);
        }
        if(check(N))
        {
            cout<<"Network "<<T++<<": "<<tmp<<endl<<endl;
        }
        else cout<<"Network "<<T++<<": DISCONNECTED"<<endl<<endl;
        for(int i=0; i<=N; i++)G[i].clear();
        alu.clear();
    }
    return 0;
}
