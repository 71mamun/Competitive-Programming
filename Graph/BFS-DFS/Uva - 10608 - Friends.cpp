#include<bits/stdc++.h>
using namespace std;
const int MAXN = 3e4+5;///max nodes needed
const int MAXE = 5e5+5;///max edges needed

/**
last store the last edge of a node.
head store the destination node of the edge
prev store the immediate previous edge of current node
edges is used to indexed the edges
*/

int last[MAXN],prev[MAXE],head[MAXE],edges;

/**
set the index of the first edge as '0'.
set the last edge of every node '-1'(default) to identify that the nodes has no edge at the beginning.
*/

void initialize(int n)
{
    edges = 0;
    memset(last,-1,sizeof(int)*(n+1));
}
/**
adds a edge from 'u' to 'v' at 'edges' index
*/

void addEdge(int u,int v)
{
    head[edges] = v;
    prev[edges] = last[u];
    last[u] = edges++;
}

//EXAMPLE----------------------------------------------------------------------------------------------------------

/**
simple dfs algorithm using the representation.
*/
int col[MAXN];///dfs col array

int dfs(int u)
{
    col[u] = 1;
    int ans = 0;
    for(int e=last[u];e>-1;e=prev[e])
    {
        int v = head[e];
        if(!col[v])ans += dfs(v);
    }
    return ans+1;
}

int main()
{
    int T,u,v,m,n;
    cin>>T;
    while(T--)
    {
        cin>>n>>m;
        initialize(n);
        memset(col,0,sizeof(int)*(n+1));
        while(m--)
        {
            cin>>u>>v;
            addEdge(u,v);
            addEdge(v,u);
        }
        int ans = -1;
        for(int i=1;i<=n;i++)
        {
            if(!col[i])
            {
                ans = max(ans,dfs(i));
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
