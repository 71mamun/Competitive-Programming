#include<bits/stdc++.h>
using namespace std;
#define SZ 800
long long done;

struct point
{
    double x,y;
} plt[SZ];

double dis(point a,point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

struct edge
{
    long long u,v;
    double w;
    bool operator < (const edge& p) const
    {
        return w<p.w;
    }
};

vector<edge>e;
long long par[SZ];

long long get_par(long long r)
{
    return (par[r]==r?r:par[r]=get_par(par[r]));
}

void uniOn(long long a,long long b)
{
    long long u = get_par(a);
    long long v = get_par(b);
    if(u!=v)
    {
        par[u]=v;
    }
}

double MST(long long N)
{
    sort(e.begin(),e.end());
    long long c=N-1;
    double s=0;
    for(long long i=0; i<e.size(); i++)
    {
        long long u=get_par(e[i].u);
        long long v=get_par(e[i].v);
        if(u!=v)
        {
            par[u]=v;
            c--;
            s+=e[i].w;
            if(!c)break;
        }
    }
    return s;
}

int main()
{
    edge get;
    long long N,M;
    double d;
    while(cin>>N)
    {
        for(long long n=0; n<N; n++)
        {
            cin>>plt[n].x>>plt[n].y;
        }

        for(long long i=0; i<N; i++)
        {
            for(long long j=0; j<N; j++)
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
        cin>>M;
        long long u,v;
        done = 0;
        for(long long i=0; i<=N; i++)
            par[i]=i;
        for(long long m=0; m<M; m++)
        {
            cin>>u>>v;
            u--;
            v--;
            uniOn(u,v);
            done++;
        }
        printf("%.2lf\n",MST(N));
        e.clear();
    }
    return 0;
}
