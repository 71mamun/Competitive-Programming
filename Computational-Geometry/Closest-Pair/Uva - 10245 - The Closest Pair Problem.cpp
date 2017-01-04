#include "stdio.h"
#include "math.h"
#include "algorithm"
#include "iostream"

using namespace std;

#define SZ 10000
const double inf = 1e9;

struct Point
{
    double x;
    double y;
} p[SZ];


int n, t[SZ];
double Min;


bool cmp1(Point a, Point b)
{
    return a.x < b.x;
}

bool cmp2(int a, int b)
{
    return p[a].y < p[b].y;
}

double sqr(double x)
{
    return (double)(x * x);
}

double dist(int i, int j)
{
    return (double)sqrt(sqr(p[i].x - p[j].x) + sqr(p[i].y - p[j].y));
}

double solve(int l, int r)
{
    if (l == r) return inf;
    if (l + 1 == r) return dist(l, r);

    int mid = (l + r) / 2;
    double d = min(solve(l, mid), solve(mid + 1, r));

    int c = 0;

    for (int i = l; i <= r; i++)
        if (fabs(p[mid].x - p[i].x) <= d)
            t[c++] = i;

    sort(t, t + c, cmp2);

    for (int i = 0; i < c; i++)
        for (int j = i + 1; j < c && p[t[j]].y - p[t[i]].y < d; j++)
        {
            double td = dist(t[i], t[j]);
            if (d - td > 1e-9) d = td;
        }

    return d;
}

int main()
{
    int i;
    while (scanf("%d", &n) == 1&&n)
    {
        for(i=0; i<n; i++)
            scanf("%lf %lf", &p[i].x, &p[i].y);

        sort(p, p + n, cmp1);

        Min = solve(0, n - 1);

        if(Min<10000)printf("%.4lf\n",Min);
        else printf("INFINITY\n");
    }
    return 0;
}
