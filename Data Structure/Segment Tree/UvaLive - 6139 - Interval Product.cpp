#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
#define SZ 500005
int data[SZ];
int tree[4*SZ];
void init(int b,int e,int node)
{
    if(b==e)
    {
        if(data[b]>0)
            tree[node]=1;
        else if(data[b]<0)
            tree[node]=-1;
        else tree[node]=0;
        return;
    }
    int mid=(b+e)/2;
    int left=node*2;
    int right=node*2+1;
    init(b,mid,left);
    init(mid+1,e,right);
    tree[node]=tree[left]*tree[right];
}
void update(int b,int e,int i,int node,int val)
{
    if(i<b||i>e)return;
    else if(b>=i&&e<=i)
    {
        if(val>0)
            tree[node]=1;
        else if(val<0)
            tree[node]=-1;
        else tree[node]=0;
        return;
    }
    int mid=(b+e)/2;
    int left=node*2;
    int right=node*2+1;
    update(b,mid,i,left,val);
    update(mid+1,e,i,right,val);
    tree[node]=tree[left]*tree[right];
}
int query(int b,int e,int i,int j,int node)
{
    if(j<b||i>e)return 1;
    else if(b>=i&&e<=j)
        return tree[node];
    int mid=(b+e)/2;
    int left=node*2;
    int right=node*2+1;
    int lans=query(b,mid,i,j,left);
    int rans=query(mid+1,e,i,j,right);
    return lans*rans;
}
int main()
{
    //freopen("input.txt","r",stdin);
    int n,k,x,y;
    char ch;
    while(scanf("%d %d",&n,&k)==2)
    {
        memset(data,0,sizeof(data));
        memset(tree,0,sizeof(tree));
        for(int i=1; i<=n; i++)
            scanf("%d",&data[i]);
        init(1,n,1);
        for(int j=0; j<k; j++)
        {
            scanf("\n%c %d %d",&ch,&x,&y);
            if(ch=='C')update(1,n,x,1,y);
            if(ch=='P')
            {
                int ans=query(1,n,x,y,1);
                if(ans>0)printf("+");
                else if(ans<0)printf("-");
                else if(ans==0) printf("0");
            }
        }
        printf("\n");
    }
    return 0;
}
