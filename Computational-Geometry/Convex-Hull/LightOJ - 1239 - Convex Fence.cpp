/**
    Bismillah hir-Rahman nir-Raheem
    In the name of Allah, the Most Gracious, the Ever Merciful.
*/
#include<stdio.h>
#include<iostream>
#include<sstream>
#include<math.h>
#include<limits.h>
#include<limits>
#include<string.h>
#include<string>
#include<algorithm>
#include<stack>
#include<set>
#include<ctime>
#include<queue>
#include<vector>
#include<map>
#include<stdlib.h>
#include<deque>
#include<utility>
#include <assert.h>
#include <ctime>

using namespace std;

#define sf scanf
#define pf printf
#define ll long long
#define psb push_back
#define ppb pop_back
#define ms(a,b) memset(a,b,sizeof(a))
#define TestCase pf("Case %d: ",t++)

const double pi = acos(-1.0);

struct point
{
    ll x,y;
    bool operator <(const point &p) const
    {
        return x<p.x||(x==p.x&&y<p.y);
    }
};

vector<point>vec;
vector<point>convx;

ll cross(point o, point a,point b)
{
    return (a.x-o.x)*(b.y-o.y)-(a.y-o.y)*(b.x-o.x);
}

vector<point> convexHull()
{
    int n = vec.size(),k=0;
    vector<point> H(2*n);
    sort(vec.begin(),vec.end());
    int x=vec[0].x,y=vec[0].y;

    for(int i=0; i<n; i++)
    {
        while(k>=2&&cross(H[k-2],H[k-1],vec[i])<=0)k--;
        H[k++] = vec[i];
    }
    for(int i=n-1,t = k+1; i>=0; i--)
    {
        while(k>=t&&cross(H[k-2],H[k-1],vec[i])<=0)k--;
        H[k++] = vec[i];
    }
    H.resize(k);
    return H;
}

double getDistance(point a, point b)
{
    return sqrt((double)((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)));
}

void setDef()
{
    vec.clear();
    convx.clear();
}

int main()
{
    int T,t=1,N,d;
    point p;
    sf("%d",&T);
    while(T--)
    {
        sf("%d %d",&N,&d);
        for(int i=0;i<N;i++)
        {
            sf("%ld %lld",&p.x,&p.y);
            vec.psb(p);
        }
        convx = convexHull();
        int l = convx.size();
        double sum = 0;
        for(int i=0;i<l-1;i++)
        {
            sum+=getDistance(convx[i],convx[i+1]);
        }
        TestCase;
        pf("%.6lf\n",sum+2*pi*d);
        setDef();
    }
    return 0;
}
