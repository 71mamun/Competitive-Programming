#include<bits/stdc++.h>
using namespace std;
#define     ll                      long long
#define     ull                     unsigned long long
#define     mems(a,b)               memset(a,b,sizeof(a))
#define     mp                      make_pair
#define     pii                     pair<int,int>
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

//*************************************************My Code Starts Here*********************************************************************************
// nlogn complexity
// memory complexity 12n
/* application
   1. multiplying two arrays.
   2. multiplying two long(string) numbers.
*/
// i-th index mean coefficient2 of i-th power
#define pi acos(-1)
typedef complex <double> base ;

void fft ( vector < base > & a, bool invert ) {  //invert=true means inverse FFT
	int n = ( int ) a. size ( ) ;

	for ( int i = 1 , j = 0 ; i < n ; ++ i ) {
		int bit = n >> 1 ;
		for ( ; j >= bit ; bit >>= 1 )
			j -= bit ;
		j += bit ;
		if ( i < j )
			swap ( a [ i ] , a [ j ] ) ;
	}

	for ( int len = 2 ; len <= n ; len <<= 1 ) {
		double ang = 2 * pi / len * ( invert ? - 1 : 1 ) ;
		base wlen ( cos ( ang ) , sin ( ang ) ) ;
		for ( int i = 0 ; i < n ; i += len ) {
			base w ( 1 ) ;
			for ( int j = 0 ; j < len / 2 ; ++ j ) {
				base u = a [ i + j ] ,  v = a [ i + j + len / 2 ] * w ;
				a [ i + j ] = u + v ;
				a [ i + j + len / 2 ] = u - v ;
				w *= wlen ;
			}
		}
	}
	if ( invert )
		for ( int i = 0 ; i < n ; ++ i )
			a [ i ]/= n ;
}

void multiply ( vector < int > & a, vector < int > & b, vector < int > & res ) {
	vector < base > fa ( a. begin ( ) , a. end ( ) ) ,  fb ( b. begin ( ) , b. end ( ) ) ;
	size_t n = 1 ;
	while ( n < max ( a. size ( ) , b. size ( ) ) )  n <<= 1 ; //making it a power of 2
	n <<= 1 ; //making double size(2*n)
	fa. resize ( n ) ,  fb. resize ( n ) ;

	fft ( fa, false ) ,  fft ( fb, false ) ;
	for ( size_t i = 0 ; i < n ; ++ i )
		fa [ i ] *= fb [ i ] ;
	fft ( fa, true ) ; //inverse fft

	res. resize ( n ) ;
	for ( size_t i = 0 ; i < n ; ++ i )
		res [ i ] = int ( fa [ i ] . real ( ) + 0.5 ) ;
}

void carryoperation( vector < int > & res )  //multiplying two long(string) numbers.(normalizing)
{
    int n=res.size();
    int carry = 0 ;
	for ( size_t i = 0 ; i < n ; ++ i ) {
		res [ i ] += carry ;
		carry = res [ i ] / 10 ;
		res [ i ] %= 10 ;
	}

	if(carry>0)res.push_back(carry);

}
#define LM 300007
char a[LM],b[LM];

int main()
{
    vector<int>as,bs,rs;
    int T;
    sf("%d",&T);
    while(T--)
    {
        as.clear();
        bs.clear();
        rs.clear();
        sf(" %s %s",a,b);

        int al = strlen(a);
        int bl = strlen(b);

        for(int i=0;i<al;++i)
        {
            as.pb(a[i]-'0');
        }

        for(int j=0;j<bl;++j)
        {
            bs.pb(b[j]-'0');
        }

        multiply(as,bs,rs);

//        debv(rs);
        rs.resize(al+bl-1);
//        debv(rs);

        reverse(rs.begin(),rs.end());

        carryoperation(rs);

        reverse(rs.begin(),rs.end());

        for(int i=0;i<rs.size();++i)
        {
            cout<<rs[i];
        }

        cout<<endl;

    }
    return 0;
}
















