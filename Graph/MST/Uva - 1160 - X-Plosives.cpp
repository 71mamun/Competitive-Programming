#include<bits/stdc++.h>
using namespace std;
#define sz 100010
int par[sz];

int get_par(int r)
{
    return (par[r]==r?r:par[r]=get_par(par[r]));
}

int main()
{
    //freopen("input.txt","r",stdin);
    int a,b;
    while(cin>>a)
    {
        if(a==-1)continue;
        cin>>b;
        for(int i=0; i<sz; i++)par[i]=i;
        par[a]=b;
        int c=1,e=1;
        while(cin>>a&&a!=-1)
        {
            cin>>b;
            int u = get_par(a);
            int v = get_par(b);
            if(u!=v)
            {
                par[u]=v;
                c++;
            }
            e++;
        }
        cout<<e-c<<endl;
    }
    return 0;
}

