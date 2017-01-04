#include<bits/stdc++.h>
using namespace std;
#define sf scanf
#define pf printf
#define pii pair<int,int>
#define mp make_pair
#define fs first
#define sc second
#define inf (1<<30)
#define LM 200007
int n;
int ary[LM];
int ans[LM];
pii tree[4*LM];

void initialize(int node,int b,int e)
{
    if(b==e)
    {
        tree[node] = mp(ary[b],b);
        return;
    }
    int lft = node*2;
    int rgt = lft+1;
    int mid = (b+e)/2;
    initialize(lft,b,mid);
    initialize(rgt,mid+1,e);
    tree[node].fs = min(tree[lft].fs,tree[rgt].fs);
    tree[node].sc = (tree[node].fs==tree[lft].fs?tree[lft].sc:tree[rgt].sc);
}

pii query(int node,int b,int e,int i,int j)
{
    if(i>e||j<b)return mp(inf,inf);
    if(b>=i && e<=j) return tree[node];
    int lft = node*2;
    int rgt = lft+1;
    int mid = (b+e)/2;
    pii Qlft = query(lft,b,mid,i,j);
    pii Qrgt = query(rgt,mid+1,e,i,j);
    int res = min(Qlft.fs,Qrgt.fs);
    int idx = (res==Qlft.fs?Qlft.sc:Qrgt.sc);
    return mp(res,idx);
}

void calculate(int beg,int end)
{
    if(end<0||beg>n-1)return;
    if(beg>end)return;
    pii res = query(1,0,n-1,beg,end);
    int nbeg = max(0,res.sc-1);
    int nend = max(n-1,res.sc+1);
    if(beg==end)
    {
        if(res.sc<inf)ans[1] = max(ans[1],res.fs);
        return;
    }
    int range = end-beg+1;
    if(res.sc<inf)ans[range] = max(ans[range],res.fs);
    else return;
    calculate(beg,res.sc-1);
    calculate(res.sc+1,end);
}


int main()
{
    sf("%d",&n);
    for(int i=0;i<n;++i)
    {
        sf("%d",ary+i);
    }
    initialize(1,0,n-1);
    calculate(0,n-1);
    for(int i=n-1;i>0;--i)
    {
        ans[i] = max(ans[i+1],ans[i]);
    }
    for(int i=1;i<=n;++i)
    {
        pf("%d ",ans[i]);
    }
    pf("\n");
    return 0;
}
