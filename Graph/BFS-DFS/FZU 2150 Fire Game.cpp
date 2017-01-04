#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
#define sz 12
#define sz 12
using namespace std;
int R,C;
char grid[sz][sz];
int dis[sz][sz];
int X[] = {-1,0,1,0};
int Y[] = {0,1,0,-1};
const int inf = 1e9;

struct node
{
    int r,c;
    node(int rr,int cc){r = rr,c= cc;}
};
vector<node>g1;
vector<node>g2;
queue<node>que;

void grid_input()
{
    g1.clear(),g2.clear();
    for(int i=0; i<R; i++)
        for(int j=0; j<C; j++)
            cin>>grid[i][j];
}

void dfs_visit(int ur,int uc,int g)
{
    if(g==1)g1.push_back(node(ur,uc));else g2.push_back(node(ur,uc));
    grid[ur][uc] = '*';
    for(int i=0; i<4; i++)
    {
        int vr = ur+X[i], vc = uc+Y[i];
        if(grid[vr][vc]=='#')dfs_visit(vr,vc,g);
    }
}

int dfs()
{
    int c = 0;
    for(int i=0; i<R; i++)
        for(int j=0; j<C; j++)
        {
            if(grid[i][j]=='#')
            {
                if(c==2)return 3;
                c++;
                dfs_visit(i,j,c);
            }
        }
    return c;
}

void set_dis(node a,node b)
{
    for(int i=0; i<R; i++)
        for(int j=0; j<C; j++)
            dis[i][j] = inf;
    dis[a.r][a.c] = dis[b.r][b.c] = 0;
    que.push(a);que.push(b);
}

int bfs(node a,node b)
{
    set_dis(a,b);
    while(!que.empty())
    {
        node u = que.front();
        que.pop();
        for(int i=0;i<4;i++)
        {
            int vr = u.r+X[i],vc = u.c+Y[i];
            if(dis[vr][vc]>dis[u.r][u.c]+1&&grid[vr][vc]=='*')
            {
                dis[vr][vc]=dis[u.r][u.c]+1;
                que.push(node(vr,vc));
            }
        }
    }
    int ret = -1;
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            if(grid[i][j]=='*')ret = max(ret,dis[i][j]);
        }
    }
    return ret;
}

int main()
{
    int T;
    cin>>T;
    for(int t=1; t<=T; t++)
    {
        cin>>R>>C;
        grid_input();
        printf("Case %d: ",t);
        int sc = dfs();
        if(sc>2)
        {
            cout<<-1<<endl;
            continue;
        }
        int g1sz = g1.size(),g2sz = g2.size(),ans = inf;
        if(sc==2)
        {
            for(int i=0; i<g1sz; i++)
            {
                for(int j=0; j<g2sz; j++)
                {
                    ans = min(ans,bfs(g1[i],g2[j]));
                }
            }
        }
        else
        {
            for(int i=0;i<g1sz;i++)
            {
                for(int j=0;j<g1sz;j++)
                {
                    ans = min(ans,bfs(g1[i],g1[j]));
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
