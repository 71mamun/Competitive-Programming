#include<bits/stdc++.h>
using namespace std;
#define sz 120
char G[sz][sz];
bool V[sz][sz];
char arr[120];
int cnt;
int dr[] = {-1, 0, 1, 0, -1, 1, 1, -1};
int dc[] = {0, 1, 0, -1, 1, 1, -1, -1};
void DFS(int r,int c,int R,int C)
{
    char &u = G[r][c];
    if(V[r][c]||u=='L'||r<0||c<0||r==R||c==R)return;
    V[r][c]=true;
    cnt++;
    for(int i=0; i<8; i++)
    {
        DFS(r+dr[i],c+dc[i],R,C);
    }
}

int main(int argc, char** argv)
{
    //freopen("input.txt","r",stdin);
    int T,R,C;
    scanf("%d",&T);
    getchar();
    getchar();
    while(T--)
    {
        int row=0;
        while(gets(arr)&&strlen(arr)>0)
        {
            if(arr[0]=='L'||arr[0]=='W')
            {
                strcpy(G[row++],arr);
            }
            else
            {
                cnt=0;
                int r,c,R,C;
                int col = strlen(G[0]);
                sscanf(arr,"%d %d",&r,&c);
                memset(V,false,sizeof(V));
                DFS(r-1,c-1,row,col);
                cout<<cnt<<endl;
            }
        }
        if(T)cout<<endl;
    }
    return 0;
}
