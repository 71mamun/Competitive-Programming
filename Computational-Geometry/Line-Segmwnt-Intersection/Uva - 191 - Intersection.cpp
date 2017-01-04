#include "stdio.h"
#include "iostream"

using namespace std;
struct tuple{int f,s,t;tuple(){}tuple(int a,int b,int c){f=a,s=b,t=c;}};
int cross_product(tuple a,tuple b){int v=a.f*(b.s-b.t)-a.s*(b.f-b.t)+a.t*(b.f-b.s);return (v==0?0:(v>0?+1:-1));}
tuple make_vector(tuple s,tuple e){tuple a;a.f=e.f-s.f;a.s=e.s-s.s;a.t=e.t-s.t;return a;}

struct Point
{
    int x;
    int y;
};

bool onSegment(Point p, Point q, Point r)
{
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) && q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
        return true;
    return false;
}

int orientation(Point p, Point q, Point r)
{
    int v = cross_product(make_vector(tuple(p.x,p.y,0),tuple(q.x,q.y,0)),make_vector(tuple(q.x,q.y,0),tuple(r.x,r.y,0)));
    if(v==0)return 0;
    if(v>0)return 1;
    return 2;
}

bool incision(Point p1, Point q1, Point p2, Point q2)
{
    int or1 = orientation(p1, q1, p2);
    int or2 = orientation(p1, q1, q2);
    int or3 = orientation(p2, q2, p1);
    int or4 = orientation(p2, q2, q1);

    if (or1 != or2 && or3 != or4)
        return true;

    if (or1 == 0 && onSegment(p1, p2, q1)) return true;

    if (or2 == 0 && onSegment(p1, q2, q1)) return true;

    if (or3 == 0 && onSegment(p2, p1, q2)) return true;

    if (or4 == 0 && onSegment(p2, q1, q2)) return true;

    return false;
}

int main()
{
    Point p1, p2, q1, q2, lt, rb, lb, rt;
    int test;

    scanf("%d",&test);

    while(test--)
    {
        scanf("%d %d %d %d %d %d %d %d",&p1.x,&p1.y,&q1.x,&q1.y,&p2.x,&p2.y,&q2.x,&q2.y);
        lt = p2;
        rb = q2;
        lb.x = p2.x;
        lb.y = q2.y;
        rt.x = q2.x;
        rt.y = p2.y;
        if(incision(p1, q1, lt, lb)) printf("T\n");
        else if(incision(p1, q1, lt, rt)) printf("T\n");
        else if(incision(p1, q1, lb, rb)) printf("T\n");
        else if(incision(p1, q1, lt, rb)) printf("T\n");
        else printf("F\n");
    }
    return 0;
}

