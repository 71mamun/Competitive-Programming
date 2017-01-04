#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define pb push_back
#define all(a) a.begin(),a.end()
#define sz(a) (int)a.size()

#define LM 120007
int tree[LM],t=1;

struct info
{
    int x,y1,y2,st,idx;
};

int T,x,y,x_1,y_1,x_2,y_2,p,q,n;
vector<int>ys;
vector<info>pnts;
map<int,int>idx;

bool com(info a,info b)
{
    if(a.x!=b.x)return a.x<b.x;
    return a.st<b.st;
}

int query(int i)
{
    int sum=0;
    while(i>0)
    {
        sum+=tree[i];
        i-=(i&(-i));
    }
    return sum;
}

int update(int i,int value)
{
    while(i<=n)
    {
        tree[i]+=value;
        i+=(i&(-i));
    }
}

int qry(int y1,int y2)
{
    return query(idx[y2])-query(idx[y1]-1);
}

int ans[LM];

int main()
{
    int i;
    scanf(" %d",&T);
    while(T--)
    {
        scanf(" %d %d",&p,&q);

        for(i=0;i<p;++i)
        {
            scanf(" %d %d",&x,&y);
            ys.push_back(y);
            pnts.push_back({x,y,0,0,-1});
        }

        for(i=0;i<q;++i)
        {
            scanf(" %d %d %d %d",&x_1,&y_1,&x_2,&y_2);
            ys.push_back(y_1);
            ys.push_back(y_2);
            pnts.pb({x_1,y_1,y_2,-1,i});
            pnts.pb({x_2,y_1,y_2,+1,i});
        }

        sort(all(ys));
        ys.resize(unique(all(ys))-ys.begin());
        sort(all(pnts),com);
        n = sz(ys)+1;

        for(i=0;i<sz(ys);++i)
        {
            idx[ys[i]] = i+1;
        }

        for(i=0;i<sz(pnts);++i)
        {
            switch(pnts[i].st)
            {
                case 0:
                    update(idx[pnts[i].y1],1);
                    break;
                case -1:
                    ans[pnts[i].idx] -= qry(pnts[i].y1,pnts[i].y2);
                    break;
                case +1:
                    ans[pnts[i].idx] += qry(pnts[i].y1,pnts[i].y2);
                    break;
            }
        }

        printf("Case %d:\n",t++);

        for(i=0;i<q;++i)
        {
            printf("%d\n",ans[i]);
        }

        if(T)
        {
            ys.clear();
            pnts.clear();
            idx.clear();

            for(i=0;i<=n;++i)
            {
                tree[i] = 0;
            }

            for(i=0;i<=q;++i)
            {
                ans[i] = 0;
            }
        }
    }
    return 0;
}
