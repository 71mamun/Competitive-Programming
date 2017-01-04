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

char a[LM],b[LM],c[LM];

int main()
{
    int T,al,bl,cl,t=1,as,ae,bs,be,cs,ce,l,ans;
    cin>>T;
    while(T--)
    {
        ans = -(1e9);
        SuffixArray sa;
        scanf(" %s %s %s",a,b,c);
        al = strlen(a),bl = strlen(b),cl = strlen(c);
        strcpy(sa.cinp,a);
        strcat(sa.cinp,"#");
        strcat(sa.cinp,b);
        strcat(sa.cinp,"$");
        strcat(sa.cinp,c);
        sa.build_sa();
        sa.callcp();
        as = 0;ae = as+al-1;
        bs = al+1;be = bs+bl-1;
        cs = al+1+bl+1;ce = cs+cl-1;
        for(int i=2;i<sa.n;++i)
        {
            if((as<=sa.sa[i-2]&&sa.sa[i-2]<=ae&&bs<=sa.sa[i-1]&&sa.sa[i-1]<=be&&cs<=sa.sa[i]&&sa.sa[i]<=ce)||
               (as<=sa.sa[i-2]&&sa.sa[i-2]<=ae&&bs<=sa.sa[i]&&sa.sa[i]<=be&&cs<=sa.sa[i-1]&&sa.sa[i-1]<=ce)||
               (as<=sa.sa[i-1]&&sa.sa[i-1]<=ae&&bs<=sa.sa[i]&&sa.sa[i]<=be&&cs<=sa.sa[i-2]&&sa.sa[i-2]<=ce)||
               (as<=sa.sa[i-1]&&sa.sa[i-1]<=ae&&bs<=sa.sa[i-2]&&sa.sa[i-2]<=be&&cs<=sa.sa[i]&&sa.sa[i]<=ce)||
               (as<=sa.sa[i]&&sa.sa[i]<=ae&&bs<=sa.sa[i-1]&&sa.sa[i-1]<=be&&cs<=sa.sa[i-2]&&sa.sa[i-2]<=ce)||
               (as<=sa.sa[i]&&sa.sa[i]<=ae&&bs<=sa.sa[i-2]&&sa.sa[i-2]<=be&&cs<=sa.sa[i-1]&&sa.sa[i-1]<=ce))
            {
                ans = max(ans,min(sa.lcp[i],sa.lcp[i-1]));
            }
        }
        printf("Case %d: %d\n",t++,ans);
    }
    return 0;
}
