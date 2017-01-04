#include<bits/stdc++.h>
using namespace std;
#define sz 30
vector<int>G[sz];
int col[sz];

void DFS(int src)
{
    if(col[src]!=0)return;
    col[src]=-1;
    for(int i=0; i<G[src].size(); i++)
    {
        DFS(G[src][i]);
    }
    col[src]=1;
}



int main()
{
    int T;
    char tmp;
    char tempu[4];
    cin>>T;
    while(T--)
    {
        cin>>tmp;
        getchar();
        int H = tmp-'A';
        while(gets(tempu)&&strlen(tempu)>0)
        {
            int u = tempu[0]-'A';
            int v = tempu[1]-'A';
            G[u].push_back(v);
            G[v].push_back(u);
        }
        int ans = 0;
        for(int i=0; i<=H; i++)
        {
            if(col[i]==0)
            {
                DFS(i);
                ans++;
            }
        }
        cout<<ans<<endl;
        if(T)cout<<endl;
        for(int i=0; i<=H; i++)G[i].clear();
        memset(col,0,sizeof(col));
    }
    return 0;
}
