//http://codeforces.com/contest/750/problem/D
#include<bits/stdc++.h>
using namespace std;
#define LM 303
int n,t[LM],col[LM][LM];
int vis[LM][LM][10][33];
int X[] = {0, 1, 1, 1, 0, -1, -1, -1};
int Y[] = {1, 1, 0, -1, -1, -1, 0, 1};

int dfs(int cr,int cc,int dir,int level)
{
    if(vis[cr][cc][dir][level])return 0;
    vis[cr][cc][dir][level] = 1;
    if(level>=n)return 0;
    int ans = 0,nr,nc;

    for(int i=0; i<t[level]; ++i)
    {
        nr=cr+i*X[dir],nc = cc+i*Y[dir];
        if(col[nr][nc]==0)
        {
            ans++;
            col[nr][nc] = 1;
        }
    }

    int dir1 = (dir+1)%8;
    int r1 = nr+X[dir1];
    int c1 = nc+Y[dir1];
    ans+=dfs(r1,c1,dir1,level+1);

    int dir2 = ((dir-1)%8+8)%8;
    int r2 = nr+X[dir2];
    int c2 = nc+Y[dir2];
    ans+=dfs(r2,c2,dir2,level+1);

    return ans;
}

int main()
{
    scanf("%d",&n);
    for(int i=0; i<n; ++i)
    {
        scanf("%d",t+i);
    }

    cout<<dfs(150,150,6,0)<<endl;

    return 0;
}
