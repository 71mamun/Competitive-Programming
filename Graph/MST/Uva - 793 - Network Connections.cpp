#include<bits/stdc++.h>
using namespace std;
#define sz 100000
int par[sz];

void init_rep(int range)
{
    for(int i=0; i<=range; i++)par[i]=i;
}

int find_rep(int r)
{
    return par[r]==r?r:par[r]=find_rep(par[r]);
}

void uniOn(int a,int b)
{
    int u = find_rep(a);
    int v = find_rep(b);
    if(u==v)return;
    else par[u]=v;
}

bool comp_rep(int a,int b)
{
    int u = find_rep(a);
    int v = find_rep(b);
    if(u==v)return true;
    else return false;
}

int main()
{
    int T,N,yes,no;
    char input[50],op;
    int u,v;
    cin>>T;
    getchar();
    getchar();
    while(T--)
    {
        yes=no=0;
        cin>>N;
        getchar();
        init_rep(N);
        while(gets(input)&&strlen(input)>4)
        {
            sscanf(input,"%c %d %d",&op,&u,&v);
            if(op=='c')uniOn(u,v);
            else
            {
                if(comp_rep(u,v))yes++;
                else no++;
            }
        }
        cout<<yes<<","<<no<<endl;
        if(T)cout<<endl;
    }
    return 0;
}
