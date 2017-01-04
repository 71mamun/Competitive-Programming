#include<bits/stdc++.h>
using namespace std;
#define sz 10010
#define SZ 110

struct point
{
    double x,y;
} plt[sz];

double dis(point a,point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

struct edge
{
    int u,v;
    double w;
    bool operator < (const edge& p) const
    {
        return w<p.w;
    }
};

vector<edge>e;
int par[SZ];

int get_par(int r)
{
    return (par[r]==r?r:par[r]=get_par(par[r]));
}

double MST(int N)
{
    sort(e.begin(),e.end());
    for(int i=0; i<=N; i++)
        par[i]=i;
    int c=0;
    double s=0;
    for(int i=0; i<e.size(); i++)
    {
        int u=get_par(e[i].u);
        int v=get_par(e[i].v);
        if(u!=v)
        {
            par[u]=v;
            c++;
            s+=e[i].w;
            if(c==N-1)break;
        }
    }
    return s;
}

int main()
{
    edge get;
    int T,N;
    double d;
    cin>>T;
    while(T--)
    {
        cin>>N;
        for(int n=0; n<N; n++)
        {
            cin>>plt[n].x>>plt[n].y;
        }

        for(int i=0; i<N; i++)
        {
            for(int j=0; j<N; j++)
            {
                if(i!=j)
                {
                    get.u=i;
                    get.v=j;
                    get.w=dis(plt[i],plt[j]);
                    e.push_back(get);
                }
            }
        }
        printf("%.2lf\n",MST(N));
        if(T)cout<<endl;
        e.clear();
    }
    return 0;
}