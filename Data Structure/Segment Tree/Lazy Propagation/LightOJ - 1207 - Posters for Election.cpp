#include<bits/stdc++.h>
using namespace std;
#define LM 100007
int n;
int tree[8*LM],lazy[8*LM],islazy[8*LM];
set<int>ss;

void push_down(int node,int l,int r,int value)
{
    int lft = (node<<1);
    int rgt = (lft|1);
    if(l!=r)
    {
        lazy[lft] = value;
        lazy[rgt] = value;
        islazy[lft] = islazy[rgt] = true;
    }
    if(l==r)tree[node] = value;
    lazy[node] = 0;
    islazy[node] = false;
}

void update(int node,int l,int r,int i,int j,int value)
{
//    cout<<node<<" "<<l<<" "<<r<<endl;
    if(islazy[node])push_down(node,l,r,lazy[node]);
    if(i>r||j<l)return;
    if(i<=l&&r<=j)
    {
        push_down(node,l,r,value);
        return;
    }
    int mid = ((l+r)>>1);
    int lft = (node<<1);
    int rgt = (lft|1);
    update(lft,l,mid,i,j,value);
    update(rgt,mid+1,r,i,j,value);
}

int qry(int node,int l,int r,int i,int j)
{
    if(islazy[node])push_down(node,l,r,lazy[node]);
    if(i>r || j<l)return 0;
    if(i<=l && r<=j)return tree[node];
    int mid = (l+r)/2;
    int lq = qry(node*2,l,mid,i,j);
    int rq = qry(node*2+1,mid+1,r,i,j);
    return max(lq,rq);
}

int main()
{
    int T,l,r,t=1;
    scanf("%d",&T);
    while(T--)
    {
        memset(tree,0,sizeof(tree));
        ss.clear();
        scanf("%d",&n);
        for(int i = 1;i<=n;++i)
        {
            scanf("%d %d",&l,&r);
            update(1,1,2e5+3,l,r,i);
        }
        for(int i=1;i<=2e5+3;++i)
        {
            int r = qry(1,1,2e5+3,i,i);
            if(r)
            {
                ss.insert(r);
            }
        }
        printf("Case %d: %d\n",t++,ss.size());
    }
    return 0;
}
