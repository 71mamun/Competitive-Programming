#include <bits/stdc++.h>


#define ms(a,b) memset(a,b,sizeof(a))
#define inf 1<<30
#define mp make_pair
#define pi acos(-1)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pli pair<ll,int>
#define pil pair<int,ll>
#define fs first
#define sc second
#define cffi ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define make_flush  cout << flush; //    fflush(stdout);
#define pob pop_back
#define vec_ vector
#define clr(a) a.clear()
#define pb push_back
#define eps 1E-7
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define sz(a) (int)a.size()
#define ll long long
#define ull unsigned long long
#define dd double
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define repa(i,n) for(auto i: n)
#define fop freopen("codecoder.in","r",stdin);freopen("codecoder.out","w",stdout);
using namespace std;

template<class T1> void deb(T1 e)
{
    cout<<e<<endl;
}
template<class T1,class T2> void deb(T1 e1,T2 e2)
{
    cout<<e1<<" "<<e2<<endl;
}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3)
{
    cout<<e1<<" "<<e2<<" "<<e3<<endl;
}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4)
{
    cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;
}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5)
{
    cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<endl;
}
template<class T1,class T2,class T3,class T4,class T5,class T6> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6)
{
    cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<endl;
}


//double dur(int x1,int y1,int x2,int y2)
//{
//    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
//}
//template<class T> string toString(T n){ostringstream oss;oss<<n;oss.flush();return oss.str();}
//int toInt(string s){int r=0;istringstream sin(s);sin>>r;return r;}
//template <class T> T lcm(T a, T b){return (a/__gcd(a,b)) * b;}
//ll bigmod(ll B,ll P,ll M){ll R=1;while(P>0){if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;}return R;}
//int X[]={0,-1,-1,-1,0,1,1,1};
//int Y[]={-1,-1,0,1,1,1,0,-1};
//int X[]={-1,0,1,0};
//int Y[]={0,1,0,-1};


#define mt 100010
#define mod

struct maan
{
    int a,b,ind;
};

vec_<maan>v;

bool cmp1(maan a,maan b)
{
    return a.a<b.a;
}

bool cmp2(maan a,maan b)
{
    return a.b<b.b;
}


int ans[mt];
//int seg[4*mt];

//int ml,mr,pos;

//void update(int node,int l,int r)
//{
//    seg[node]++;
//    if(l==r)
//        return;
//    int mid=l+r >> 1;
//    int b= node << 1;
//    if(pos<=mid)
//        update(b,l,mid);
//    else
//        update(b|1,mid+1,r);
//}
//
//int solve(int node,int l,int r)
//{
//    if(r<ml || l>mr)
//        return 0;
//    if(l>=ml && r<=mr)
//        return seg[node];
//    int mid=l+r >> 1;
//    int b = node << 1;
//    return solve(b,l,mid)+solve(b|1,mid+1,r);
//}

int main ()
{
    cffi;
//    fop;
    int n,a,b;
    cin>>n;
    rep1(i,n)
    {
        cin>>a>>b;
        v.pb({a,b,i});
    }

    sort(all(v),cmp1);

    rep(i,sz(v))
    v[i].a=i+1;

    sort(all(v),cmp2);

    rep(i,sz(v))
    v[i].b=i+1;

    sort(all(v),cmp1);

    maan nm;
//    ml=1;
    rep(i,n)
    {
//        deb(i,"shuru");
        nm=v[i];
//        mr=nm.b-1;
        ans[nm.ind]=max(nm.a-1,nm.b-1);
//        pos=nm.b;
//        update(1,1,n);
//        deb(i,"shesh");
    }

    rep1(i,n)
    deb(ans[i]);

    return 0;
}


