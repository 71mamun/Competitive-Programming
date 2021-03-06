#include<iostream>
#include<sstream>
#include<string>
#include<cstdlib>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<cmath>
#include<cctype>
#include<set>
#include<bitset>
#include<algorithm>
#include<list>

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

using namespace std;
#define print1(a)    cout<<a<<endl
#define print2(a,b) cout<<a<<" "<<b<<endl
#define print3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define oo          (1<<30)
#define PI          3.141592653589793
#define pi          2*acos(0)
#define ERR         1e-5
#define PRE         1e-8
#define SZ(a)       (int)a.size()
#define LL          long long
#define ISS         istringstream
#define OSS         ostringstream
#define VS          vector<string>
#define VI          vector<int>
#define VD          vector<double>
#define VLL         vector<long long>
#define SII         set<int>::iterator
#define SI          set<int>
#define mem(a,b)    memset(a,b,sizeof(a))
#define fr(i,a,b)   for(i=a;i<=b;i++)
#define frn(i,a,b)  for(i=a;i>=b;i--)
#define fri(a,b)    for(i=a;i<=b;i++)
#define frin(a,b)   for(i=a;i>=b;i--)
#define frj(a,b)    for(j=a;j<=b;j++)
#define frjn(a,b)   for(j=a;j>=b;j--)
#define frk(a,b)    for(k=a;k<=b;k++)
#define frkn(a,b)   for(k=a;k>=b;k--)
#define frl(a,b)    for(l=a;l<=b;l++)
#define frln(a,b)   for(l=a;l>=b;l--)

#define EQ(a,b)     (fabs(a-b)<ERR)
#define all(a,b,c)  for(int I=0;I<b;I++)    a[I] = c
#define CROSS(a,b,c,d) ((b.x-a.x)*(d.y-c.y)-(d.x-c.x)*(b.y-a.y))
#define sqr(a)      ((a)*(a))
#define FORE(i,a)   for(typeof((a).begin())i=(a).begin();i!=(a).end();i++)
#define BE(a)       a.begin(),a.end()
#define rev(a)      reverse(BE(a));
#define sorta(a)    sort(BE(a))
#define pb          push_back
#define popb        pop_back
#define round(i,a)  i = ( a < 0 ) ? a - 0.5 : a + 0.5;
#define makeint(n,s)  istringstream(s)>>n
#define countbit(mask) __builtin_popcount(musk)
#define mod         1000000007
struct matrix{
     double x[30][30];
};
matrix base,ret,power;

void copy(matrix &a,matrix &b,int n)
{
    int i,j;
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
        a.x[i][j]=b.x[i][j];
}

void matmult(matrix &xx,matrix &a,matrix &b,int n)//m*n and n*r matrix  //1 based
{
    int i,j,k;
    fr(i,1,n)
    fr(j,1,n)
    {
        ret.x[i][j]=0;
        fr(k,1,n)
            ret.x[i][j]=ret.x[i][j]+(a.x[i][k]*b.x[k][j]); //we can reduce complexity here
    }
    copy(xx,ret,n);
}

void bigmod(matrix &xx,matrix &b,long long p,int n) //have to pass n
{
    int i,j;
    //making it identity
    fr(i,1,n)
    fr(j,1,n)
    if(i!=j)  xx.x[i][j]=0;
    else xx.x[i][j]=1;
    copy(power,b,n);
    while(p)
    {
        if((p&1)==1) matmult(xx,xx,power,n);
        matmult(power,power,power,n);
        p/=2;
    }
}

set<string>prv;

int main()
{
    int T,K,M;
    string s,tmp;
    cin>>T;
    while(T--)
    {
        prv.clear();
        cin>>M>>K>>s;

        for(int i=1;i<=26;++i)
        {
            for(int j=1;j<=26;++j)
            {
                cin>>base.x[i][j];
            }
        }

        matrix ans;
        bigmod(ans,base,K,26);

        double as = 0;

        while(M--)
        {
            cin>>tmp;
            if(prv.find(tmp)!=prv.end())continue;
            if(tmp.size()!=s.size())continue;
            double lc = 1;
            for(int i=0;i<s.size();++i)
            {
                lc*=ans.x[s[i]-'a'+1][tmp[i]-'a'+1];
            }
            as+=lc;
            prv.insert(tmp);
        }
        printf("%.12lf\n",as);
    }
    return 0;
}

