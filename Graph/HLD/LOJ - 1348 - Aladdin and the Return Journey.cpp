#include<bits/stdc++.h>
using namespace std;
/*************************************************My Code Starts Here*********************************************************************************/


/**

Works in every based(0/1) index
compexity n(logn)^2

input:
    bidirectional tree
output:
    query: sum of node value between u,v.
    update: change node value of u to v.
*/

#define LM 30007
#define STEP 17  //step=log(#vertices)

vector<int> adj[LM];//adjacency list for the tree

///LCA code
int parent[LM][STEP+3]/*sparse table*/,child[LM]/*#child of a node*/,start[LM],finish[LM];/*starting & finishing time of a node*/
int n/*#node*/,somoy/*time counter*/;

int dfs(int u,int p)
{
    int i,v;
    start[u] = somoy++;

    //calculating the sparse table.
    parent[u][0] = p;
    for(int i=1; i<STEP; ++i)
    {
        parent[u][i] = parent[parent[u][i-1]][i-1];
    }

    child[u] = 1;

    for(int i=0; i<adj[u].size(); ++i)
    {
        v = adj[u][i];
        if(v==p) continue;
        child[u]+=dfs(v,u);
    }

    finish[u] = somoy++;
    return child[u];
}


bool isAnchestor(int u,int v)//Is u ancestor of v including himself
{
    if(start[u]<=start[v] && finish[u]>=finish[v]) return true;
    return false;
}

int lca_query(int u,int v)
{
    int w=-1,temp=u;

    if(isAnchestor(u,v)) w=u;
    if(isAnchestor(v,u)) w=v;

    if(w==-1)
    {
        for(int i=STEP; i>=0; i--)
            if(!isAnchestor(parent[temp][i],v))
                temp=parent[temp][i];
        w=parent[temp][0];
    }
    return w;
}


/// BIT code
int tree[LM];//BIT always 1 base.
int MaxVal;// maximum #vertices.

int queryBIT(int idx)
{
    if(idx<=0) return 0;
    int sum = 0;
    idx =min(idx,MaxVal);
    while (idx > 0)
    {
        sum += tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

void updateBIT(int idx,int val)
{
    if(idx<=0) return;
    while (idx <= MaxVal)
    {
        tree[idx] += val;
        idx += (idx & -idx);
    }
}


int currentIndex[LM]/*BIT index of a node*/,nodeId/*used of indexing*/,firstNode[LM]/*firstNode[u] = staring node of the chain where node u belongs*/;

///HLD code

void hld(int u,int p,int lastNode)
{
    currentIndex[u] = ++nodeId;
    firstNode[u] = lastNode;

    int heavyChild = -1,max_child = -1;

    for(int i=0; i<adj[u].size(); ++i)// searching the heavy child.
    {
        int v = adj[u][i];
        if(v==p)continue;
        if(child[v]>max_child)
        {
            max_child = child[v];
            heavyChild = v;
        }
    }

    if(heavyChild>=0)// calling the heavy child.
    {
        hld(heavyChild,u,lastNode);
    }

    for(int i=0; i<adj[u].size(); ++i)// calling the light childs.
    {
        int v = adj[u][i];
        if(v==p||v==heavyChild)continue;
        hld(v,u,v);
    }

}

int query_up(int u,int v)// u should be upper node(close to root)
{
    int ans = 0,u_idx,v_idx,chainHead;
    while(true)
    {
        chainHead = currentIndex[firstNode[v]];// chain starting node index in BIT.
        u_idx = currentIndex[u];// upper node index in BIT.
        v_idx = currentIndex[v];// lower node index in BIT.

        if(chainHead<=u_idx&&u_idx<=v_idx)
        {
            // upper node is the member of the current chain.
            ans+=queryBIT(v_idx)-queryBIT(u_idx-1);
            break;
        }

        // upper node is not member of the current chain.
        ans+=queryBIT(v_idx)-queryBIT(chainHead-1);
        v = parent[firstNode[v]][0];
    }
    return ans;
}

void initialize()
{
    for(int i=0; i<=n; ++i)
    {
        adj[i].clear();
    }

    MaxVal = n;// BIT highest index.
    somoy  = 0;// to calculate starting and ending time of a node.
    nodeId = 0;// to index the node into the BIT.
}

int value[LM];

int query(int u,int v)
{
    int lcanode = lca_query(u,v);
    return query_up(lcanode,u)+query_up(lcanode,v)-query_up(lcanode,lcanode);
}

void update(int u,int x)
{
    int curval = queryBIT(currentIndex[u])-queryBIT(currentIndex[u]-1);
    x-=curval;// -curval+x update u node. changing value of u to x.
    updateBIT(currentIndex[u],x);
}


int main()
{
    int T,t = 1,u,v,i,q,d;

    scanf("%d",&T);

    while(T--)
    {
        scanf("%d",&n);// #of nodes.

        initialize();

        for(i=0; i<n; i++)
        {
            scanf("%d",&value[i]);// initial values of the nodes.
        }

        for(i=1; i<n; i++)
        {
            scanf("%d %d",&u,&v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(0,0);
        hld(0,0,0);

        for(i=0; i<n; i++)
            update(i,value[i]);// updating initial values.

        scanf("%d",&q);
        printf("Case %d:\n",t++);
        while(q--)
        {
            scanf("%d",&d);
            if(d==0)
            {
                scanf("%d %d",&u,&v);
                printf("%d\n",query(u,v));// sum of node values in path [u,v]
            }
            else
            {
                scanf("%d %d",&u,&v);// change node vaule u to v.
                update(u,v);
            }
        }
    }

    return 0;
}
