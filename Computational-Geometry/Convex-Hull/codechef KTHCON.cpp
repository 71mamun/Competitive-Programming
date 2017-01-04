#include<bits/stdc++.h>
using namespace std;
#define     ll                      long long
#define     ull                     unsigned long long
#define     mems(a,b)               memset(a,b,sizeof(a))
#define     mp                      make_pair
#define     pii                     pair<ll,ll>
#define     pdd                     pair<double,double>
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
#define     fastIO                  ios_base::sync_with_stdio(false)
#define     cintie                  cin.tie(NULL)
#define     endl                    "\n";
#define     PI                      (acos(-1.0))
#define     linf                    (1LL<<62)
#define     inf                     (0x7f7f7f7f)
#define     sqr(a)                  ((a)*(a))
#define     lcm(a,b)                ({(a)/__gcd(a,b)*(b);})
#define     is_set(mask,pos)        ((mask)&(1LL<<pos))
#define     rset(mask,pos)          ((mask)&(~(1LL<<pos)))
#define     set(mask,pos)           ((mask)|(1LL<<pos))
#define     flip(mask,pos)          ((mask)^(1LL<<pos))
#define     debv(v)                 for(int i=0;i<sz(v);++i)(!i?cout<<v[i]:cout<<" "<<v[i]);cout<<endl;
#define     deba(arr,l)             for(int i=0; i<l; i++)(!i?cout<<arr[i]:cout<<" "<<arr[i]);cout<<endl;
#define     deb(a...)               {cerr<<"#"<<__LINE__<<" -> ";dbg,a; cerr<<endl;}
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
#define vpii vector<pii>
ll n;
vpii pnts,innerConvex,outerConvex;
set< pii >innerPoints;

ll cross(pii o, pii a, pii b)
{
    return (a.fs-o.fs)*(b.sc-o.sc)-(a.sc-o.sc)*(b.fs-o.fs);
}

vpii convexHull(vpii pnts)
{
    int n = sz(pnts),k=0;
    vpii H(2*n);
    sort(all(pnts));

    for(int i=0;i<n;++i)
    {
        while(k>=2&&cross(H[k-2],H[k-1],pnts[i])<=0)k--;
        H[k++] = pnts[i];
    }

    for(int i=n-1,t=k+1;i>=0;--i)
    {
        while(k>=t&&cross(H[k-2],H[k-1],pnts[i])<=0)k--;
        H[k++] = pnts[i];
    }
    H.resize(k);
    return H;
}

ll area(vpii hull)///first point and last point should be same.
{
    ll ans = 0;
    for(int i=1;i<hull.size();++i)
    {
        ans+=((hull[i-1].fs*hull[i].sc)-(hull[i-1].sc*hull[i].fs));
    }
    return abs(ans);
}

ll triangleArea(pii a, pii b, pii c)
{
    return area({a,b,c,a});
}

int main()
{
    int T,x,y;
    cin>>T;
    while(T--)
    {
        innerConvex.clear();
        outerConvex.clear();
        innerPoints.clear();

        cin>>n;
        for(int i=0;i<n;++i)
        {
            cin>>x>>y;
            outerConvex.pb(mp(x,y));
            innerPoints.insert(mp(x,y));
        }

        outerConvex = convexHull(outerConvex);

        ll ans = area(outerConvex);

        for(auto it: outerConvex)
        {
            innerPoints.erase(it);
        }


        for(auto it:innerPoints)
        {
            innerConvex.pb(it);
        }

        if(innerConvex.empty())
        {
            cout<<-1<<endl;
            continue;
        }

        innerConvex = convexHull(innerConvex);


        pii start;ll minArea = (1LL<<60),insideIndex;

        for(int i=0;i<innerConvex.size();++i)
        {
            ll nowArea = triangleArea(outerConvex[0],outerConvex[1],innerConvex[i]);
//            deb(nowArea,minArea);
            if(minArea>nowArea)
            {
                insideIndex = i;
                minArea = nowArea;
            }
        }

        for(int i=2;i<outerConvex.size();++i)
        {
            while(triangleArea(outerConvex[i],outerConvex[i-1],innerConvex[insideIndex])>triangleArea(outerConvex[i],outerConvex[i-1],innerConvex[insideIndex+1]))insideIndex = (insideIndex+1)%innerConvex.size();
            minArea = min(minArea,triangleArea(outerConvex[i],outerConvex[i-1],innerConvex[insideIndex]));
        }


        cout<<(ans-minArea)<<endl;

    }
}
