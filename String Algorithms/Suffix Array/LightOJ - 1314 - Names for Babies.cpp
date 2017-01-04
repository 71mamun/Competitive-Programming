#include<bits/stdc++.h>
using namespace std;

typedef long long  int ll;
const int LM = 100007;
const int MOD = 1000000007;

struct SuffixArray
{
    int sa[LM], lcp[LM], n;
    char cinp[LM];

    int w[LM], ta[LM], tb[LM];
    void sort(int *x, int *y, int m)
    {
        static int i ;
        for(i=0; i<m; i++) w[i] = 0;
        for(i=0; i<n; i++) w[x[y[i]]]++;
        for(i=1; i<m; i++) w[i] += w[i-1];
        for(i=n-1; i>=0; i--) sa[--w[x[y[i]]]] = y[i];
    }
    bool comp(int *r, int a, int b, int l)
    {
        if(r[a]==r[b])
        {
            if(a+l>=n || b+l>=n) return false;
            return r[a+l]==r[b+l];
        }
        return false;
    }
    void callcp()
    {
        int i, j, k;
        for(i=0; i<n; i++) ta[sa[i]] = i;
        for(i=0; i<n; i++)
        {
            if(ta[i]==0)
            {
                lcp[ta[i]] = 0;
                continue;
            }
            if(i==0 || lcp[ta[i-1]]<=1) k = 0;
            else k = lcp[ta[i-1]] - 1;
            while(cinp[sa[ta[i]-1]+k]==cinp[sa[ta[i]]+k]) k++;
            lcp[ta[i]] = k;
        }
    }
    void build_sa()
    {
        int i, k, m = 128, p;
        int *x = ta, *y = tb, *z;
        n = strlen(cinp);
        x[n] = 0;
        for(i=0; i<n; i++) x[i] = cinp[i], y[i] = i;
        sort(x,y,m);
        for(k=1, p=1; p<n; k*=2, m= p)
        {
            for(p=0, i=n-k; i<n; i++) y[p++] = i;
            for(i=0; i<n; i++)
            {
                if(sa[i]>=k)
                {
                    y[p++] = sa[i] - k;
                }
            }
            sort(x,y,m);
            z = x, x = y, y = z;
            for(i=1, p=1, x[sa[0]] =0; i<n; i++)
                x[sa[i]] = comp(y,sa[i-1],sa[i],k) ? p - 1: p++;
        }
    }
};

int main()
{
    int T,lo,hi,t=1;
    cin>>T;
    while(T--)
    {
        SuffixArray sa;
        scanf(" %s",sa.cinp);
        scanf("%d %d",&lo,&hi);
        sa.build_sa();
        sa.callcp();
        int ans = max(0,(min((sa.n-sa.sa[0]),hi)-max(lo-1,sa.lcp[0])));
        for(int i=1;i<sa.n;++i)
        {
            ans += max(0,(min((sa.n-sa.sa[i]),hi)-max(lo-1,sa.lcp[i])));
        }
        printf("Case %d: %d\n",t++,ans);
    }
    return 0;
}
