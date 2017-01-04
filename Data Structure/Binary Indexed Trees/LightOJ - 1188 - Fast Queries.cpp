#include<stdio.h>
#include<cstring>
#include<algorithm>
using namespace std;
#define     mem(a,b)        memset(a,b,sizeof(a))
#define     fs              first
#define     sc              second
#define     sf              scanf
#define     pf              printf
#define     For(i,a,b)      for(int i=a;i<=b;++i)
#define     rFor(i,a,b)     for(int i=a;i>=b;--i)
struct tuple{int f,s,t;tuple(){}tuple(int a,int b,int c){f=a,s=b,t=c;}};
///HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
#define LM 100002
#define QLM 50002
tuple pp[QLM];
int already[LM];
int ans[QLM];
int arr[LM];
int tree[LM];
int child[LM];
int last_pos[LM];
int n;

int query(int idx)
{
    int sum=0;
    while(idx>0)
    {
        sum+=tree[idx];
        idx-=(idx&(-idx));
    }
    return sum;
}

void update(int idx,int value)
{
    while(idx<=n)
    {
        tree[idx]+=value;
        idx+=(idx&(-idx));
    }
}

bool cmp(tuple a,tuple b)
{
    if(a.f==b.f)return a.s<b.s;
    return a.f<b.f;
}

int main()
{
    int T,t=1,q,u,v;
    sf("%d",&T);
    while(T--)
    {
        mem(last_pos,0);
        mem(already,0);
        For(i,0,n)child[i]=tree[i]=0;
        sf("%d %d",&n,&q);
        For(i,1,n)
        {
            sf("%d",arr+i);
            if(!already[arr[i]])
            {
                already[arr[i]]=1;
                update(i,1);
            }
            if(last_pos[arr[i]]==0)
            {
                last_pos[arr[i]] = i;
            }
            else
            {
                child[last_pos[arr[i]]] = i;
                last_pos[arr[i]] = i;
            }
        }
        For(i,0,q-1)
        {
            sf("%d %d",&u,&v);
            pp[i] = tuple(u,v,i);
        }
        sort(pp,pp+q,cmp);
        int qno = 0;
        For(i,1,n)
        {
            while(pp[qno].f==i)
            {
                ans[pp[qno].t] = query(pp[qno].s)-query(pp[qno].f-1);
                qno++;
            }
            if(child[i]!=0)
            {
                update(child[i],1);
                update(i,-1);
                child[i]=0;
            }
        }
        pf("Case %d:\n",t++);
        For(i,0,q-1)
        {
            pf("%d\n",ans[i]);
        }
    }
    return 0;
}

/**

8 5
1 1 1 2 3 5 1 2
1 4
1 8
3 3
3 4
3 5

*/
