#include<bits/stdc++.h>
using namespace std;
#define sz 30
vector<int>G[sz];
vector<int>ans;
bool c[sz];
bool present[sz];

void topsort_dfs(int u)
{
    if(c[u]) return;
    c[u]=true;
    for(int i=0; i<G[u].size(); i++) topsort_dfs(G[u][i]);
    ans.push_back(u);
}

int main()
{
    ans.clear();
    memset(c,false,sizeof(c));
    memset(present,false,sizeof(present));
    for(int i=0;i<sz;i++)G[i].clear();
    string pre_line,now_line;
    cin>>pre_line;
    while(cin>>now_line&&now_line!="#")
    {
        int mIn = min(pre_line.size(),now_line.size());
        for(int i=0;i<mIn;i++)
        {
            if(pre_line[i]!=now_line[i])
            {
                G[pre_line[i]-'A'].push_back(now_line[i]-'A');
                present[pre_line[i]-'A']=present[now_line[i]-'A']=true;
                break;
            }
        }
        pre_line = now_line;
    }
    for(int i=0;i<sz;i++)
    {
        if(!c[i]&&present[i])topsort_dfs(i);
    }
    for(int i=ans.size()-1;i>=0;i--)cout<<(char)(ans[i]+'A');
    cout<<endl;
    return 0;
}
