#include<iostream>
#include<string>
#define SZ 17
using namespace std;
char grid[SZ][SZ];
int wx,wy;
int R,C,T=1;
string data;
void go(int x,int y,char dir);

int c_n_c(int x,int y)
{
    if(grid[x][y]=='B'||grid[x][y]=='b'||grid[x][y]=='#')return 0;
    else
    {
        if(grid[x][y]=='.')return 1;
        else return 2;
    }
}

bool check(void)
{
    int flag=1;
    for(int i=0; i<R; i++)
    {
        for(int j=0; j<C; j++)
        {
            if(grid[i][j]=='b')
            {
                flag=0;
                break;
            }
        }
    }
    if(flag)return true;
    else return false;
}

int main()
{
    while(cin>>R>>C&&R+C)
    {
        data.clear();
        for(int i=0; i<R; i++)
        {
            for(int j=0; j<C; j++)
            {
                cin>>grid[i][j];
                if(grid[i][j]=='W'||grid[i][j]=='w')
                {
                    wx=i;
                    wy=j;
                }
            }
        }
        cin>>data;
        for(int i=0; i<data.size()&&(!check()); i++)
        {
            if(data[i]=='U')
            {
                go(wx-1,wy,'U');
            }
            else if(data[i]=='D')
            {
                go(wx+1,wy,'D');
            }
            else if(data[i]=='L')
            {
                go(wx,wy-1,'L');
            }
            else if(data[i]=='R')
            {
                go(wx,wy+1,'R');
            }
        }
        if(check())cout<<"Game "<<T++<<": complete"<<endl;
        else cout<<"Game "<<T++<<": incomplete"<<endl;
        for(int i=0; i<R; i++)
        {
            for(int j=0; j<C; j++)
            {
                cout<<grid[i][j];
            }
            cout<<endl;
        }
    }
    return 0;
}

void go (int x, int y,char dir)
{
    int tmp,col;
    if(grid[x][y]=='.')
    {
        grid[x][y]='w';
        if(grid[wx][wy]=='w')grid[wx][wy]='.';
        else grid[wx][wy]='+';
        wx=x;
        wy=y;
    }
    if(grid[x][y]=='B'||grid[x][y]=='b')
    {
        if(grid[x][y]=='B')col=1;
        else col=0;
        if(dir=='U')
        {
            tmp=c_n_c(x-1,y);
            if(tmp)
            {
                if(tmp==1)
                {
                    grid[x-1][y]='b';
                }
                else grid[x-1][y]='B';
                if(col)
                {
                    grid[x][y]='W';
                }
                else grid[x][y]='w';
                if(grid[wx][wy]=='W')grid[wx][wy]='+';
                else grid[wx][wy]='.';
                wx=x;
                wy=y;
            }
        }
        else if(dir=='D')
        {
            tmp=c_n_c(x+1,y);
            if(tmp)
            {
                if(tmp==1)
                {
                    grid[x+1][y]='b';
                }
                else grid[x+1][y]='B';
                if(col)
                {
                    grid[x][y]='W';
                }
                else grid[x][y]='w';
                if(grid[wx][wy]=='W')grid[wx][wy]='+';
                else grid[wx][wy]='.';
                wx=x;
                wy=y;
            }
        }
        else if(dir=='L')
        {
            tmp=c_n_c(x,y-1);
            if(tmp)
            {
                if(tmp==1)
                {
                    grid[x][y-1]='b';
                }
                else grid[x][y-1]='B';
                if(col)
                {
                    grid[x][y]='W';
                }
                else grid[x][y]='w';
                if(grid[wx][wy]=='W')grid[wx][wy]='+';
                else grid[wx][wy]='.';
                wx=x;
                wy=y;
            }
        }
        else if(dir=='R')
        {
            tmp=c_n_c(x,y+1);
            if(tmp)
            {
                if(tmp==1)
                {
                    grid[x][y+1]='b';
                }
                else grid[x][y+1]='B';
                if(col)
                {
                    grid[x][y]='W';
                }
                else grid[x][y]='w';
                if(grid[wx][wy]=='W')grid[wx][wy]='+';
                else grid[wx][wy]='.';
                wx=x;
                wy=y;
            }
        }
    }
}
