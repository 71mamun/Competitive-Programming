#include<bits/stdc++.h>
using namespace std;
#define SZ 510
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
vector<edge>ans;
vector<edge>e;
long long par[SZ];

long long get_par(long long r)
{
    return (par[r]==r?r:par[r]=get_par(par[r]));
}

void MST(long long N)
{
    for(long long i=0; i<=N; i++)
        par[i]=i;
    sort(e.begin(),e.end());
    for(long long i=0; i<e.size(); i++)
    {
        long long u=get_par(e[i].u);
        long long v=get_par(e[i].v);
        if(u!=v)
        {
            par[u]=v;
            ans.push_back(e[i]);
        }
    }
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        edge get;
        long long N,M;
        cin>>M>>N;

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
        MST(N);
        sort(ans.begin(),ans.end());
        reverse(ans.begin(),ans.end());
        printf("%.2lf\n",ans[M-1].w);
        ans.clear();
        e.clear();
    }
    return 0;
}
