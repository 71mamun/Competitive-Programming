#include<bits/stdc++.h>
#define SIZE 30
using namespace std;
int N,K,Count;
int col[SIZE];
char par[SIZE];

void permutation(int cur_pos)
{
    if(cur_pos==N)
    {
        for(int i=0;i<N;i++)cout<<par[i];
        cout<<endl;
        Count++;
        return;
    }
    for(int i=0; i<N; i++)
    {
        if(Count==K)break;
        if(!col[i])
        {
            col[i]=1;
            par[cur_pos] = (char)('A'+i);
            permutation(cur_pos+1);
            col[i]=0;
        }
    }
}

int main()
{
    int T;
    cin>>T;
    for(int t=1; t<=T; t++)
    {
        printf("Case %d:\n",t);
        Count = 0;
        memset(col,0,sizeof(col));
        cin>>N>>K;
        permutation(0);
    }
    return 0;
}
