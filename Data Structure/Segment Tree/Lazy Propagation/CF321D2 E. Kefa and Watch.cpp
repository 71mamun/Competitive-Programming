/********************************************************\
 *****In the name of ALLAH the gracious the merciful*****
 **              Mohammad Mamun Hossain                **
 **                     CSE,SUST                       **
 **                71.mamun@gmail.com                  **
\********************************************************/

#include<bits/stdc++.h>
using namespace std;
#define     int                     long long
#define     ull                     unsigned long long
#define     mem(a,b)                memset(a,b,sizeof(a))
#define     mp                      make_pair
#define     pii                     pair<int,int>
#define     fs                      first
#define     sc                      second
#define     VI                      vector<int>
#define     clr(a)                  a.clear()
#define     pb                      push_back
#define     eps                     1E-5
#define     sf                      scanf
#define     pf                      printf
#define     all(a)                  a.begin(),a.end()
#define     fread(name)             freopen(name,"r",stdin)
#define     fwrite(name)            freopen(name,"w",stdout)
#define     sz(a)                   (int)a.size()
#define     cone                    __builtin_popcountll
#define     endl                    "\n"
#define     PI                      (acos(-1.0))
#define     linf                    (1e18+7)
#define     inf                     (1e9+7)
#define     FOR(I,A,B)              for(int I = (A); I <= (B); ++I)
#define     REP(I,N)                FOR(I,0,N)
#define     sqr(a)                  ((a)*(a))
#define     lcm(a,b)                ({(a)/__gcd(a,b)*(b);})
#define     is_set(mask,pos)        ((mask)&(1LL<<pos))
#define     rset(mask,pos)          ((mask)&(~(1LL<<pos)))
#define     set(mask,pos)           ((mask)|(1LL<<pos))
#define     flip(mask,pos)          ((mask)^(1LL<<pos))
#define     $                       <<" "<<
#define     putv(v)                 for(int i=0;i<sz(v);++i)(!i?cout<<v[i]:cout<<" "<<v[i]);cout<<endl;
#define     puta(arr,l)             for(int i=0; i<l; i++)(!i?cout<<arr[i]:cout<<" "<<arr[i]);cout<<endl;
#define deb(a...)          {cerr<<"#"<<__LINE__<<" -> ";dbg,a; cerr<<endl;}
struct debugger { template<typename T> debugger& operator , (const T v) { cerr<<v<<" "; return *this; } } dbg;

///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//int X[]={1,1,2,2,-1,-1,-2,-2},Y[]={2,-2,1,-1,2,-2,1,-1};
//int X[]={0,-1,-1,-1,0,1,1,1},Y[]={-1,-1,0,1,1,1,0,-1};
//int X[]={-1,0,1,0},Y[]={0,1,0,-1};
///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//int bigMod(int a,int x,int p){int r=1;while(x>0){if(x%2!=0){r=(r*a)%p;}a=(a*a)%p;x=(x>>1);}return r;}
//int modInverse(int a, int p){return bigMod(a,p-2,p);}
//int extGcd(int a,int b,ll& x,ll& y){if(b==0){x=1;y=0;return a;}else{int g=extGcd(b,a%b,y,x);y-=a/b*x;return g;}}
//template<class T> T pwr(T b, T p){T r=1,x=b;while(p){if(p&1)r*=x;x*=x;p=(p>>1);}return r;}
///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//struct triple{double f,s,t;triple() {} triple(double a,double b,double c){f=a,s=b,t=c;}};
//int cross_product(triple a,triple b){int v=a.f*(b.s-b.t)-a.s*(b.f-b.t)+a.t*(b.f-b.s);return (v==0?0:(v>0?+1:-1));}
//triple make_vector(triple s,triple e){triple a;a.f=e.f-s.f;a.s=e.s-s.s;a.t=e.t-s.t;return a;}
///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//double pdis(pdd a,pdd b){return sqrt((double)sqr(a.fs-b.fs)+sqr(a.sc-b.sc));}
//template<class T> double rAng(T a,T b,T c){double d=(sqr(a)+sqr(b)-sqr(c))/(a*b*2);d=(d<-1?-1:(d>1?1:d));return acos(d);}
///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//template<class T> string to_string(T n){ostringstream oss;oss<<n;oss.flush();return oss.str();}
//int to_int(string s){int r=0;istringstream sin(s);sin>>r;return r;}
///HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
#define LM 100007

/**
    tree[node] segment tree data structure array.
    lazy[node] lazy value of a node which should be updated to its(this node's) childs.
    is_lazy[node] if this node needs lazy update then true else false.
    BP[] = {1,239,239^2,239^3,239^4...}   hash value er power array.
    CSBP[] = {1,1+239,1+239+239^2...}  cumulative sum of BP.

    in segment tree every node keeps the calculated hash value of its range.
    for example if the number is 122 then segment tree will look like this

    1(0,2)  node 1 with range index 0 to 2.
     [v]    segment tree value of this node.

                    1(0,2)
              [1*239^2+1*239+2]
                    /   \
                2(0,1)  3(2,2)
              [239*1+1]   [2]
                /   \
            4(0,0)  5(1,1)
              [1]    [1]
*/

int tree[4*LM],BP[LM],CSBP[LM],lazy[4*LM],is_lazy[4*LM];
string str;
const int BASE = 239,MOD = 1e9+9;/// hashing value,hashing mod.
int n,m,k;

void init(int node,int l,int r)
{
    if(l>r)return;///sometime gives runtime error for this
    if(l==r)
    {
        tree[node] = str[l]-'0';/// a single digit who has the hash value like
                                /// it self so no hash value calculation.
        return;
    }

    int mid = (l+r)/2;
    init(node*2,l,mid);
    init(node*2+1,mid+1,r);
    tree[node] = (((tree[node*2]*BP[r-mid])%MOD)+tree[node*2+1])%MOD;
    /**
        raising the right as right*base to the power number of digit in the left part.
        for the given segment tree on the top for node 1 the hash value will be updated as follows.
                    (1*239+1)*239+(2)      = 1*239^2+1*239+2
                    /         /     \
                left    right has   right
                        only one
                        digit so 239^1
    */

}

void push_down(int node,int l,int r,int value)
{
    if(l!=r)/// this is not a leaf node and  updating its child node's lazy.
    {
        lazy[node*2] = value;
        lazy[node*2+1] = value;
        is_lazy[node*2] = is_lazy[node*2+1] = true;
    }

    ///Releasing the lazy of this node.
    tree[node] = (value*CSBP[r-l])%MOD;
    lazy[node] = 0;
    is_lazy[node] = false;
}

int qry(int node,int l,int r,int i,int j)
{
    if(is_lazy[node])push_down(node,l,r,lazy[node]);
    if(i>r || j<l)return 0;
    if(i<=l && r<=j)return tree[node];
    int mid = (l+r)/2;
    int lq = qry(node*2,l,mid,i,j);
    int rq = qry(node*2+1,mid+1,r,i,j);
    return (((lq*BP[max(0LL,min(j,r)-mid)])%MOD)+rq)%MOD;

    /**
        right is alrady raised to its power.
        left should be raised to minimum of this segment end index and the query end index.
        lowest power should be 0 so maximum of previous line result and 0.
        three example is given below.
        1st:
            the query is (0 ,6) we are in the segment (0,8)right is (0,4) left is (5,8)
            from right we get the value of (5,6) and from left(0,4). left should be multiplied
            by 239^(6-4) = 239^2;  max(0,min(6,8)-4)
        2nd:
            the query is (0 ,6) we are in the segment (0,4)right is (0,2) left is (3,4)
            from right we get the value of (3,4) and from left(0,2). left should be multiplied
            by 239^(4-2) = 239^2;  max(0,min(6,4)-2)
        3rd:
            the query is (0 ,2) we are in the segment (0,8)right is (0,4) left is (5,8)
            from right we get the value of (0,2) and from left 0. left should be multiplied
            by 239^0;   max(0,min(2,8)-4)

    */

}

void update(int node,int l,int r,int i,int j,int value)
{
    if(is_lazy[node])push_down(node,l,r,lazy[node]);/// updating the lazy of the node.
    if(i>r || j<l)return;
    if(i<=l && r<=j)
    {
        push_down(node,l,r,value);
        return;
    }
    int mid = (l+r)/2;
    update(node*2,l,mid,i,j,value);
    update(node*2+1,mid+1,r,i,j,value);
    tree[node] = (((tree[node*2]*BP[r-mid])%MOD)+tree[node*2+1])%MOD;/// same as the init.
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int opr,u,v,value,d;

    BP[0]=1;
    CSBP[0]=1;
    FOR(i,1,LM-4)BP[i] = (BP[i-1]*BASE)%MOD;
    FOR(i,1,LM-4)CSBP[i] = (CSBP[i-1]+BP[i])%MOD;
    cin>>n>>m>>k;
    cin>>str;
    init(1,0,n-1);
    FOR(i,1,m+k)
    {
        cin>>opr;
        if(opr==2)
        {
            cin>>u>>v>>d;
            u--;v--;
            int x = qry(1,0,n-1,u,v-d);
            int y = qry(1,0,n-1,u+d,v);

            /**
                abcdef will be a period of 2 if and only if abcd == cdef is true
                because if abcd==cdef then
                a=c,b=d,c=e,d=f;
                so, a=c=e
                    b=d=f
                so, abcdef
                    ababab   thus abcdef has a period of 2 if and only if abcd == cdef.
            */

            if(x==y)cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
        else
        {
            cin>>u>>v>>value;
            u--;v--;
            update(1,0,n-1,u,v,value);
        }
    }
    return 0;
}

/**
    given a string.
    two types of query
    1 l r с That means that Kefa changed all the digits from the l-th to the r-th to be c.
    2 l r d is substring l to r has a period of d?if it is print "YES" otherwise print "NO".
    (P.S. if string s has period of d then there is a string x for which s = xx...d times.)

*/


