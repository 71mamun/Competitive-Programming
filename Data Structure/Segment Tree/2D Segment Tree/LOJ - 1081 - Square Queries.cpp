#include<cstdio>
#include<algorithm>
using namespace std;
#define     sf              scanf
#define     pf              printf
#define     inf             (0x7f7f7f7f)//>2e9
#define     For(i,a,b)      for(int i=a;i<=b;++i)
#define     rFor(i,a,b)     for(int i=a;i>=b;--i)
#define LM 505
int arr[LM][LM],Q,N,tree[LM*LM*2];

inline int build(int node,int sbr,int sbc,int ser,int sec)
{
    if(sbr>ser or sbc>sec)return -inf;
    if(sbr==ser and sbc==sec)return tree[node]=arr[sbr][sbc];
    int midr = (sbr+ser)>>1;
    int midc = (sbc+sec)>>1;
    int &ans = tree[node];
    ans = -inf;
    int tnode=(node<<2);
    ans = max(ans,build(tnode-2,sbr,sbc,midr,midc));
    ans = max(ans,build(tnode-1,sbr,midc+1,midr,sec));
    ans = max(ans,build(tnode-0,midr+1,sbc,ser,midc));
    ans = max(ans,build(tnode+1,midr+1,midc+1,ser,sec));
    return ans;
}

inline int query(int node,int sbr,int sbc,int ser,int sec,int br,int bc,int er,int ec)
{
    if(sbr>ser or sbc>sec)return -inf;
    if(sbr>er or sbc>ec or ser<br or sec<bc)return -inf;
    if(sbr>=br and sbc>=bc and ser<=er and sec<=ec)return tree[node];
    int midr = (sbr+ser)>>1;
    int midc = (sbc+sec)>>1;
    int ans = -inf;
    int tnode=(node<<2);
    ans = max(ans,query(tnode-2,sbr,sbc,midr,midc,br,bc,er,ec));
    ans = max(ans,query(tnode-1,sbr,midc+1,midr,sec,br,bc,er,ec));
    ans = max(ans,query(tnode-0,midr+1,sbc,ser,midc,br,bc,er,ec));
    ans = max(ans,query(tnode+1,midr+1,midc+1,ser,sec,br,bc,er,ec));
    return ans;
}

int main()
{
    int T,t=1,x,y,d;
    sf("%d",&T);
    while(T--)
    {
        sf("%d %d",&N,&Q);
        For(i,1,N)
        {
            For(j,1,N)
            {
                sf("%d",&arr[i][j]);
            }
        }
        pf("Case %d:\n",t++);
        build(1,1,1,N,N);
        while(Q--)
        {
            sf("%d %d %d",&x,&y,&d);
            pf("%d\n",query(1,1,1,N,N,x,y,x+d-1,y+d-1));
        }
    }
    return 0;
}


