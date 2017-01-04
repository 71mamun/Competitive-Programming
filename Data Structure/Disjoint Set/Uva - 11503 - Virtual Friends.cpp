#include<bits/stdc++.h>
using namespace std;
#define sz 100000
int rip[sz];
int mem[sz];
int i;

void init_set(void)
{
    for(int i=0;i<sz;i++)
    {
        rip[i]=i;
        mem[i]=1;
    }
}

int find_rip(int a)
{
    return (rip[a]==a?a:rip[a] = find_rip(rip[a]));
}
int make_frnd(int a,int b)
{
    int u = find_rip(a);
    int v = find_rip(b);
    if(u!=v)
    {
        rip[u]=v;
        mem[u]=mem[v]=mem[u]+mem[v];
    }
    return mem[u];
}
int main()
{
    int T,M;
    string u,v;
    map<string,int>vos;
    cin>>T;
    while(T--)
    {
        init_set();
        vos.clear();
        cin>>M;
        i=0;
        while(M--)
        {
            cin>>u>>v;
            if(vos.find(u)==vos.end())vos[u]=i++;
            if(vos.find(v)==vos.end())vos[v]=i++;
            cout<<make_frnd(vos[u],vos[v])<<endl;
        }
    }
    return 0;
}
