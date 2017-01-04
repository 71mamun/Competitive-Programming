#include<bits/stdc++.h>
using namespace std;
#define     For(i,a,b)  for(int i=a;i<=b;++i)
#define     pub         push_back
#define     sf          scanf
#define     pf          printf
#define     inf         (1<<29)
#define     mem(a,b)    memset(a,b,sizeof(a))

template<class T1> void put(T1 e){cout<<e<<endl;}
template<class T1,class T2> void put(T1 e1,T2 e2){cout<<e1<<" "<<e2<<endl;}
template<class T1,class T2,class T3> void put(T1 e1,T2 e2,T3 e3){cout<<e1<<" "<<e2<<" "<<e3<<endl;}
template<class T1,class T2,class T3,class T4> void put(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;}
template<class T1,class T2,class T3,class T4,class T5> void put(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<endl;}
template<class T1> void putv(vector<T1>e1){for(int i=0;i<sz(e1);i++)(!i?cout<<e1[i]:cout<<" "<<e1[i]);cout<<endl;}
template<class T1> void puta(T1 arr[],int l){for(int i=0;i<l;i++)(!i?cout<<arr[i]:cout<<" "<<arr[i]);cout<<endl;}
///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
template<class T1> bool tk(T1 &e1){return(cin>>e1?true:false);}
template<class T1,class T2> bool tk(T1 &e1,T2 &e2){return(cin>>e1>>e2?true:false);}
template<class T1,class T2,class T3> bool tk(T1 &e1,T2 &e2,T3 &e3){return(cin>>e1>>e2>>e3?true:false);}
template<class T1,class T2,class T3,class T4> bool tk(T1 &e1,T2 &e2,T3 &e3,T4 &e4){return(cin>>e1>>e2>>e3>>e4?true:false);}
///HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
#define LM 105
vector<int>G[LM];
int N,K,w[LM],chooseDp[LM][LM][LM],solveDp[LM][LM];
int solve(int u,int p,int k);

int choose(int u,int p,int k,int b)
{
    int l = G[u].size();
    if(b>=l)return (k?-inf:0);
    int &ret = chooseDp[u][k][b];
    if(~ret) return ret;

    int v = G[u][b];
    ret=-inf;
    if(p==v) return choose(u,p,k,b+1);
    For(i,0,k)ret = max(ret,solve(v,u,i)+choose(u,p,k-i,b+1));

    return ret;
}

int solve(int u,int p,int k)
{
    if(k==0)return 0;
    int &ret = solveDp[u][k];
    if(~ret)return ret;

    int l = G[u].size();
    ret = -inf;
    if(k==K)
    {
        For(i,0,l-1)
        {
            int v = G[u][i];
            if(p==v)continue;
            ret = max(ret,solve(v,u,k));
        }
    }

    ret = max(ret,choose(u,p,k-1,0)+w[u]);

    return ret;
}

int main()
{
    int u,v;
    while(tk(N,K))
    {
        mem(solveDp,-1);
        mem(chooseDp,-1);
        For(i,0,N)G[i].clear();

        For(i,1,N)
        {
            tk(w[i-1]);
        }

        For(i,1,N-1)
        {
            tk(u,v);
            G[u].pub(v);
            G[v].pub(u);
        }

        put(solve(0,-1,K));
    }
    return 0;
}
