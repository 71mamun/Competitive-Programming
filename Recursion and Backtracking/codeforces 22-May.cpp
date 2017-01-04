#include<bits/stdc++.h>
using namespace std;
int N;
int col[7];
int par[7];
int tbl[7][7];
int ans;

int get()
{
    int sum = 0;
    for(int i=0; i<=N-2; i++)
    {
        for(int j=i; j<N-1; j+=2)
        {
            sum+=tbl[par[j]][par[j+1]];
            sum+=tbl[par[j+1]][par[j]];
        }
    }
    return sum;
}
int c = 0;
void permutation(int cur_pos)
{
    if(cur_pos==N)
    {
        ans = max(ans,get());
        return;
    }
    for(int i=0; i<N; i++)
    {
        if(!col[i])
        {
            col[i]=1;
            par[cur_pos] = i;
            permutation(cur_pos+1);
            col[i]=0;
        }
    }
}

int main()
{
    ans = -1;
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            cin>>tbl[i][j];
        }
    }
    N=5;
    permutation(0);
    cout<<ans<<endl;
    return 0;
}

