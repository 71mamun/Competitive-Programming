#include<bits/stdc++.h>
using namespace std;
#define SZ 50003
#define ms(a,b) memset(a,b,sizeof(a))
const int inf = (1<<28);
int N,C;
vector<int>G[SZ];//stores main graph
vector<int>RG[SZ];//stores reverse graph
vector<int>sorted;//stores sorted order for making scc
vector<int>dag[SZ];//stores dag of the given graph
int comp_num[SZ];//stores component num of a node
int comp_mem[SZ];//stores total node in component
int min_mem[SZ];//stores min node number in a component
bool col[SZ];//stores visited/unvisited flag for each node
int posibl_from_node[SZ];//stores how many node can be reached from a component
/**
set default value of all variables.
*/
void clear_all()
{
    ms(col,false);
    ms(posibl_from_node,-1);
    for(int i=0; i<SZ; i++)
    {
        RG[i].clear();
        G[i].clear();
        min_mem[i]= inf;
        dag[i].clear();
    }
    sorted.clear();
}
/**
dfs for top sort
*/
void top_sort_dfs(int src)
{
    col[src] = true;
    for(int i=0; i<G[src].size(); i++)
    {
        if(col[G[src][i]]==false)top_sort_dfs(G[src][i]);
    }
    sorted.push_back(src);
}
/**
top sort to make the sorted vector for the order of the scc().
*/
void top_sort()
{
    for(int i=1; i<=N; i++)
    {
        if(col[i]==false)top_sort_dfs(i);
    }
}
/**
dfs for scc
*/

int scc_dfs(int src, int com)
{
    col[src]=true;
    int child = 0;
    for(int i=0; i<RG[src].size(); i++)
    {
        if(col[RG[src][i]]==false)child+=scc_dfs(RG[src][i],com);
    }
    comp_num[src]=com;
    return child+1;
}
/**
strongly connected component
*/
int scc()
{
    C=1;
    for(int i=sorted.size()-1; i>=0; i--)
    {
        int chld=0;
        if(col[sorted[i]]==false)
        {
            chld = scc_dfs(sorted[i],C++);
            comp_mem[C-1]=chld;
        }
    }
    return C-1;
}
/**
making dag cycle less graph
*/

void create_dag()
{
    for(int i=1; i<=N; i++)
    {
        int u = comp_num[i];
        min_mem[u] = min(i,min_mem[u]);
        for(int j=0; j<G[i].size(); j++)
        {
            int v = comp_num[G[i][j]];
            if(u==v)continue;
            else
            {
                dag[u].push_back(v);
            }
        }
    }
}

/**
checks how many node are reachable from src component.
*/

int check_solution(int src)//dynamic programing
{
    int &ret = posibl_from_node[src];
    if(ret!=-1)return ret;
    int ret1 = 0;
    for(int i=0; i<dag[src].size(); i++)
    {
        ret1+=check_solution(dag[src][i]);
    }
    return ret = ret1+comp_mem[src];
}

int main()
{
    int T,U,V;
    scanf("%d",&T);
    for(int t=1; t<=T; t++)
    {
        scanf("%d",&N);
        clear_all();
        for(int i=0; i<N; i++)
        {
            scanf("%d %d",&U,&V);
            G[U].push_back(V);
            RG[V].push_back(U);
        }
        top_sort();
        ms(col,false);
        int totl_com = scc();
        create_dag();
        int max_visitible  = 0;
        int cal_min = 10000000;
        for(int i=1; i<=totl_com; i++)
        {
            int visitible;
            if(posibl_from_node[i]==-1)
            {
                visitible = check_solution(i);
                if(visitible>=max_visitible)
                {
                    cal_min = min(cal_min,min_mem[i]);
                    max_visitible = visitible;
                }
            }
        }
        printf("Case %d: %d\n",t,cal_min);
    }
    return 0;
}

/*
4
4
1 2
2 1
3 2
4 3
*/
