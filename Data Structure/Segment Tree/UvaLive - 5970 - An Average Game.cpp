#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <climits>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <numeric>
#include <utility>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <algorithm>

using namespace std;

#define sf scanf
#define pf printf
#define mem(a,b)          memset(a,b,sizeof(a))
#define pb push_back
#define For(i,a,b)        for(int i=a; i<=b; ++i)
#define rFor(i,a,b)        for(int i=a; i>=b; --i)
#define mp(a,b)   make_pair(a,b)
#define fs        first
#define sc        second
#define sz(s)     ((int)s.size())
#define all(a)  a.begin(),a.end()


#define LM 550
#define inf 1e9
//int X[]={1,1,2,2,-1,-1,-2,-2},Y[]={2,-2,1,-1,2,-2,1,-1};//knight move
//int X[]={0,-1,-1,-1,0,1,1,1},Y[]={-1,-1,0,1,1,1,0,-1};//8 move
//int X[]= {-1,0,1,0},Y[]= {0,1,0,-1}; //4 move
#define LMM  10007
#define ll long long
ll n;
ll arr[LMM];
map<ll,int> nextt;
ll posn[LMM];
ll sum[LMM];
ll alv[LMM];
double ans[LMM];
struct tree_node
{
    ll sum,al;
    tree_node()
    {

    }
    tree_node(ll s,ll a)
    {
        sum=s;
        al = a;
    }
};

struct qry
{
    ll L,R,I;
    qry()
    {

    }
    qry(ll a,ll b,ll c)
    {
        L=a,R=b,I=c;
    }
};



bool cmp(qry a,qry b)
{
    if(a.L==b.L)return a.R<b.R;
    return a.L<b.L;
}

vector<qry> queries;

tree_node tree[4*LMM];

void init(int node,int b,int e)
{
    if(b==e)
    {
        tree[node].al = alv[b];
        tree[node].sum = (alv[b]?arr[b]:0);
        return;
    }
    int lft = node*2;
    int rgt = lft+1;
    int mid = (b+e)/2;
    init(lft,b,mid);
    init(rgt,mid+1,e);
    tree[node].al = (tree[lft].al+tree[rgt].al);
    tree[node].sum = (tree[lft].sum+tree[rgt].sum);
    return;
}

tree_node query(int node,int b,int e,int i,int j)
{
    if(i>e||j<b)return tree_node(0,0);
    if(b>=i&&e<=j)return tree[node];
    int lft = node*2;
    int rgt = lft+1;
    int mid = (b+e)/2;
    tree_node p1 = query(lft,b,mid,i,j);
    tree_node p2 = query(rgt,mid+1,e,i,j);
    tree_node ret;
    ret.al = p1.al + p2.al;
    ret.sum = p1.sum + p2.sum;
    return ret;
}

void update(int node,int b,int e,int i,int alive)
{
    if(i>e||i<b)return;
    if(b>=i&&e<=i)
    {
        tree[node].al=alive;
        tree[node].sum = (alive?arr[i]:(-arr[i]));
        return;
    }
    int lft = node*2;
    int rgt = lft+1;
    int mid = (b+e)/2;
    update(lft,b,mid,i,alive);
    update(rgt,mid+1,e,i,alive);
    tree[node].al = tree[lft].al+tree[rgt].al;
    tree[node].sum = tree[lft].sum+tree[rgt].sum;
    return;
}

int main()
{
    ll T,t=1;
    scanf("%lld",&T);
    while(T--)
    {
        mem(tree,0);
        nextt.clear();
        scanf("%lld",&n);
        For(i,1,n)
        {
            scanf("%lld",arr+i);
        }
        rFor(i,n,1)
        {
            if(nextt.count(arr[i]))
            {
                posn[i] = nextt[arr[i]];
                sum[i] = arr[i];
                sum[posn[i]] = 0;
                alv[posn[i]] = 0;
                alv[i] = 1;
            }
            else
            {
                posn[i] = n+1;
                sum[i] = arr[i];
                alv[i] = 1;
            }
            nextt[arr[i]] = i;
        }

        queries.clear();
        ll q,x,y;
        scanf("%lld",&q);
        For(i,0,q-1)
        {
            scanf("%lld %lld",&x,&y);
            queries.pb(qry(x,y,i));
        }
        init(1,1,n);
        sort(all(queries),cmp);
        ll pl=1;
        For(i,0,sz(queries)-1)
        {
            if(pl<queries[i].L)
            {
                For(j,pl,queries[i].L-1)
                {
                    int up = posn[j];
                    if(up>n)continue;
                    update(1,1,n,j,0);
                    update(1,1,n,up,1);
                }
            }
            pl = queries[i].L;
            tree_node a= query(1,1,n,queries[i].L,queries[i].R);
            ans[queries[i].I] = double(a.sum)/double(a.al);
        }
        printf("Case %lld:\n",t++);
        For(i,0,q-1)
        {
            printf("%.6lf\n",ans[i]);
        }
    }
    return 0;
}

/*

2
10
1 2 3 4 4 3 2 1 -1 0
4
1 4
1 10
3 5
8 10
3
1 1 0
1
1 3
*/
