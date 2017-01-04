#include<bits/stdc++.h>
#define sz 512
using namespace std;
int R,C,N;
char tbl[sz][sz];
int col[sz][sz];
int gor[]= {-1,1,0,0};
int goc[]= {0,0,-1,1};
int t;

void DFS(int sr,int sc)
{
    col[sr][sc]=-1;
    for(int i=0; i<4; i++)
    {
        int ur=sr+gor[i];
        int uc=sc+goc[i];
        if(!col[ur][uc]&&ur>=0&&ur<R&&uc>=0&&uc<C&&tbl[ur][uc]=='.')DFS(ur,uc);
    }
    if(t<N)
    {
        tbl[sr][sc]='X';
        ++t;
    }
    col[sr][sc]=1;
}

int main()
{
    t=0;
    int dorkar=1;
    int srcr,srcc;
    cin>>R>>C>>N;
    for(int r=0; r<R; r++)
    {
        for(int c=0; c<C; c++)
        {
            cin>>tbl[r][c];
            if(tbl[r][c]=='.'&&dorkar)
            {
                srcr=r;
                srcc=c;
                dorkar=0;
            }
        }
    }
    DFS(srcr,srcc);
    for(int r=0; r<R; r++)
    {
        for(int c=0; c<C; c++)
        {
            cout<<tbl[r][c];
        }
        cout<<endl;
    }
    return 0;
}
