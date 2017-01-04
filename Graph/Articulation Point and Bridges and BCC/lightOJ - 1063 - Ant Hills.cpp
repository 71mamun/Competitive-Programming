#include<bits/stdc++.h>
using namespace std;
#define SZ 10005

///stores the information of bridges between 'u' and 'v'.
vector< pair<int,int> >bridge;//stores bridges
set<int>articulationPoint;//stores articulation point
vector<int>G[SZ];//store the total graph
int visitMark[SZ];//marks if a node is already visited or not
int discoveryTime[SZ];//store the discovery time of a node
int lowestTime[SZ];//store the lowest discovery time of a group if it is in a group else only the nodes
int dfsCount;//time counter
int n;// total number of node

///dfs to calculate articulation point and bridges. 'u' is the current node whose parent is 'p'
///and 'root' is the node from which the dfs is called as root.
void dfs(int u,int p,int root)
{
    int cnt=0;//count distinct call from node u
    visitMark[u]=0;//marks u as visited
    discoveryTime[u]=lowestTime[u]=++dfsCount;//initialize the discovery time and lowest discovery time of the node
    int l = G[u].size();// total l number of node are connected with 'u'
    for(int i=0; i<l; i++)// traverse all node which is connected with 'u'
    {
        int v = G[u][i];//'v' is the current node to calculate

        /** this is the most important condition I always forgot*/
        if(v==p)continue;// if 'v' is parent of 'u' just ignore

        if(visitMark[v]==-1)//if v is not visited
        {
            cnt++;//increase number of distinct call form 'u'
            dfs(v,u,root);//call dfs for node 'v' with parent 'u' and root as 'root'
            lowestTime[u] = min(lowestTime[u],lowestTime[v]);//update lowest time 'u' with reference of 'v'
            if(lowestTime[v]>=discoveryTime[u]&&u!=root)articulationPoint.insert(u);//condition to be a articulation point
            if(lowestTime[v]>discoveryTime[u])bridge.push_back(make_pair(u,v));//condition to be a bridge
        }
        else
        {
            lowestTime[u] = min(lowestTime[u],discoveryTime[v]);//update lowest time 'u' with reference of 'v'
        }
    }
    if(u==root&&cnt>1)//the condition to be a articulation point as root
    {
        articulationPoint.insert(u);
    }
}

///calculate the articulation points and bridges of graph 'G'.
void calculateArticulationPointAndBridge()
{
    ///setting all as default
    //no need to memset discoveryTime and lowestTime.
    memset(visitMark,-1,sizeof(visitMark));
    articulationPoint.clear();
    bridge.clear();
    dfsCount = -1;
    ///needed if the graph is disconnected
    for(int i=1; i<=n; i++)
    {
        if(visitMark[i]==-1)
        {
            dfs(i,-1,i);
        }
    }
}

int main()
{
    int T,t=1,m,u,v;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d",&n,&m);
        for(int i=0; i<=n; i++)G[i].clear();
        for(int i=0; i<m; i++)
        {
            scanf("%d %d",&u,&v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        calculateArticulationPointAndBridge();
        printf("Case %d: %d\n",t++,(int)articulationPoint.size());
    }
    return 0;
}
