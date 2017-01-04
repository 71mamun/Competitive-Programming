#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <climits>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <numeric>
#include <utility>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <algorithm>

using namespace std;

#define sf scanf
#define pf printf
#define mem(a,b)          memset(a,b,sizeof(a))
#define pb push_back
#define For(i,a,b)        for(int i=a; i<=b; ++i)


#define LM 550
#define inf 1e9
//int X[]={1,1,2,2,-1,-1,-2,-2},Y[]={2,-2,1,-1,2,-2,1,-1};//knight move
//int X[]={0,-1,-1,-1,0,1,1,1},Y[]={-1,-1,0,1,1,1,0,-1};//8 move
int X[]= {-1,0,1,0},Y[]= {0,1,0,-1}; //4 move

int R,C;
struct node
{
    int r,c,w;
    char ntn;
    node(int a,int b,int cc,char d)
    {
        r = a,c = b,w = cc,ntn = d;
    }
    bool operator< (const node& p)const
    {
        return w>p.w;
    }
};

struct field
{
    char ntn;
    int w;
};

field grid[LM][LM];
priority_queue<node>pq;

int main()
{
//    freopen("in.txt","r",stdin);
    int T;
    cin>>T;
    while(T--)
    {
        cin>>R>>C;
        For(i,0,R-1)
        {
            For(j,0,C-1)
            {
                cin>>grid[i][j].ntn;
                if(grid[i][j].ntn!='.'&&grid[i][j].ntn!='#')
                {
                    grid[i][j].w = 0;
                    pq.push(node(i,j,0,grid[i][j].ntn));
                }
                else
                {
                    grid[i][j].w = inf;
                }
            }
        }


        while(!pq.empty())
        {
            node top = pq.top();
            pq.pop();
            int r = top.r;
            int c = top.c;
            if(grid[r][c].ntn!=top.ntn)continue;
            For(i,0,3)
            {
                int rr = r+X[i];
                int cc = c+Y[i];
                if(rr<0||cc<0||rr>=R||cc>=C)continue;
                if(grid[rr][cc].ntn=='#'||grid[rr][cc].ntn=='*')continue;
                if(grid[rr][cc].ntn==grid[r][c].ntn)continue;
                if(grid[rr][cc].w==grid[r][c].w+1&&grid[rr][cc].ntn!=grid[r][c].ntn)
                {
                    grid[rr][cc].ntn = '*';
                }
                else if(grid[rr][cc].w>grid[r][c].w+1)
                {
                    grid[rr][cc].ntn = grid[r][c].ntn;
                    grid[rr][cc].w=grid[r][c].w+1;
                    pq.push(node(rr,cc,grid[rr][cc].w,grid[rr][cc].ntn));
                }
            }
        }

        For(i,0,R-1)
        {
            For(j,0,C-1)
            {
                cout<<grid[i][j].ntn;
            }
            cout<<endl;
        }
        cout<<endl;


    }
    return 0;
}

/*

5
3 5
#####
a...b
#####
3 4
####
a..b
####
3 3
#c#
a.b
#d#
3 3
#c#
...
a.b
3 5
.....
.#.#.
a...b

*/
