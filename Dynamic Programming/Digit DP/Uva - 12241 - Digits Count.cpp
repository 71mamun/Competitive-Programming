#include<algorithm>
#include<sstream>
#include<iostream>
#include<iomanip>
#include<climits>
#include<cstring>
#include<cassert>
#include<utility>
#include<limits>
#include<cstdio>
#include<string>
#include<vector>
#include<bitset>
#include<stack>
#include<ctime>
#include<queue>
#include<cmath>
#include<map>
#include<set>
using namespace std;
typedef long long ll;
typedef unsigned long long  ull;
#define     mem(a,b)        memset(a,b,sizeof(a))
#define     mp              make_pair
#define     pii             pair<int,int>
#define     fs              first
#define     sc              second
#define     VI              vector<int>
#define     clr(a)          a.clear()
#define     pob             pop_back
#define     pub             push_back
#define     eps             1E-5
#define     sf              scanf
#define     pf              printf
#define     all(a)          a.begin(),a.end()
#define     allr(a)         a.rbegin(),a.rend()
#define     full(a,l)       a,a+l
#define     fread(name)     freopen(name,"r",stdin)
#define     fwrite(name)    freopen(name,"w",stdout)
#define     sz(a)           ((int)a.size())
#define     count_one       __builtin_popcount
#define     count_onell     __builtin_popcountll
#define     fastIO          ios_base::sync_with_stdio(false)
#define     PI              (acos(-1.0))
#define     linf            (1LL<<62)//>4e18
#define     inf             (0x7f7f7f7f)//>2e9
#define     fore(x,i)       for(typeof((x).begin()) i=(x.begin()); i!=(x).end(); ++i)
#define     rfore(x,i)      for(typeof((x).rbegin()) i=(x.rbegin()); i!=(x).rend(); ++i)
#define     For(i,a,b)      for(int i=a;i<=b;++i)
#define     rFor(i,a,b)     for(int i=a;i>=b;--i)
///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//int X[]={1,1,2,2,-1,-1,-2,-2},Y[]={2,-2,1,-1,2,-2,1,-1};
//int X[]={0,-1,-1,-1,0,1,1,1},Y[]={-1,-1,0,1,1,1,0,-1};
//int X[]={-1,0,1,0},Y[]={0,1,0,-1};
///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//ll bigMod(ll a,ll x,ll p){ll r=1;while(x>0){if(x%2!=0){r=(r*a)%p;}a=(a*a)%p;x=(x>>1);}return r;}
//ll modInverse(ll a, ll p){return bigMod(a,p-2,p);}
//ll extGcd(ll a,ll b,ll& x,ll& y){if(b==0){x=1;y=0;return a;}else{int g=extGcd(b,a%b,y,x);y-=a/b*x;return g;}}
template<class T> T pwr(T b, T p){T r=1,x=b;while(p){if(p&1)r*=x;x*=x;p=(p>>1);}return r;}
template<class T> T lcm(T a,T b){return(a/__gcd(a,b))*b;}
template<class T> T sqr(T a){return a*a;}
template<class T> void xswap (T &x,T &y){if(x!=y){x^=y;y^=x;x^=y;}}
///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//struct tuple{double f,s,t;tuple(){}tuple(double a,double b,double c){f=a,s=b,t=c;}};
//int cross_product(tuple a,tuple b){int v=a.f*(b.s-b.t)-a.s*(b.f-b.t)+a.t*(b.f-b.s);return (v==0?0:(v>0?+1:-1));}
//tuple make_vector(tuple s,tuple e){tuple a;a.f=e.f-s.f;a.s=e.s-s.s;a.t=e.t-s.t;return a;}
///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
template<typename T> inline bool isOn(T &mask,int pos){return((mask)&(1LL<<pos));}
template<typename T> inline T setf(T mask,int pos){return mask=((mask)&(~(1LL<<pos)));}
template<typename T> inline T sett(T mask,int pos){return mask=((mask)|(1LL<<pos));}
template<typename T> inline T flip(T mask,int pos){return mask=((mask)^(1LL<<pos));}
///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//double dtor(double x){return x*PI/180.0;}
//double rtod(double x){return x*180.0/PI;}
//double pdis(pdd a,pdd b){return sqrt((double)sqr(a.fs-b.fs)+sqr(a.sc-b.sc));}
//template<class T> double rAng(T a,T b,T c){double d=(sqr(a)+sqr(b)-sqr(c))/(a*b*2);d=(d<-1?-1:(d>1?1:d));return acos(d);}
///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//template<class T> string to_string(T n){ostringstream oss;oss<<n;oss.flush();return oss.str();}
int to_int(string s){int r=0;istringstream sin(s);sin>>r;return r;}
///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
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
#define LM 12
string lo,hi;///দেয়া range এর lowest ও highest value
int low[LM],high[LM],len;///এই value গুলার digit গুলার array
pii dp[4][4][12];///Memoization
bool ted[4][4][12];///true if already calculated

/**
    Parameter:
    a = এখন পর্যন্ত total solution
    b = 'now' digit বসিয়ে পাওয়া no of solution
    now = আমি কোন digit বসিয়ে solution করেছি
    digit = আমি কোন digit টার frequency calculate করতেসি
    return:
        পূর্বের মোট যতগুলা solution ছিল তার সাথে 'now' digit বসিয়ে মোট যত গুলা solution
*/
pii add(pii a,pii b,int now,int digit)
{
    a.sc+=b.sc;
    /// যে digit এর জন্নে solution করতেসি সেইটা now হলে
    ///এখন পর্যন্ত যত গুলা ans তার সাথে now বসিয়ে যত গুলা ভিন্ন ভিন্ন (এইখানে ঠিক ততবার এই digit বসবে)
    ///নাম্বার বানান জায়+now বসিয়ে digit কত বার ব্যাবহার হইসে তার সমষ্টি
    if(now==digit)a.fs+=(b.fs+b.sc);
    else a.fs+=b.fs;
    return a;
}

/**
    Parameter:
    agrt = দেয়া range এর lowest value থেকে already বড় বানিয়ে থাকলে true
    ales = দেয়া range এর highest value থেকে already ছোট বানিয়ে থাকলে true
    pos = আমি কোন position এ digit বসাবো
    digit = আমি কোন digit টার frequency calculate করতেসি
    return:
    'pos' position এ সম্ভাব্য সকল ডিজিট বসিয়ে মোট solution
        * দেয়া range এর ভিতর inclusively(imp) সব নাম্বার তৈরি করার জন্নে
*/
pii solve(bool agrt, bool ales,int pos,int digit)
{
    if(pos>=len)return mp(0,1);
    pii &ans = dp[agrt][ales][pos];
    if(ted[agrt][ales][pos])return ans;
    ted[agrt][ales][pos]=true;
    ans = mp(0,0);
    if(agrt && ales)/// আমি already দেয়া range lowest থেকে বড় ও highest থেকে ছোট বানিয়ে ফেলেছি
    {
        For(i,0,9)///আমি যেকোনো digit বসালেও range এর ভিতর থাকবে
        {
            ans=add(ans,solve(true,true,pos+1,digit),i,digit);
        }
    }
    else if(!agrt && !ales)///range এর lowest থেকে বড় ও highest থেকে ছোট কোনটায় করি নি
    {
        if(low[pos]==high[pos])///সমান হলে একটা digit ই শুধু বসাতে পারব
        {
            ans=add(ans,solve(false,false,pos+1,digit),low[pos],digit);
        }
        else
        {
            ///বড় করি নাই কিন্তু ছোট করেছি*
            ans=add(ans,solve(false,true,pos+1,digit),low[pos],digit);
            For(i,low[pos]+1,high[pos]-1)
            {
                ///বড় ছোট ২ টায় করেছি*
                ans=add(ans,solve(true,true,pos+1,digit),i,digit);
            }
            ///ছোট করিনাই কিন্তু বড় করেছি*
            ans=add(ans,solve(true,false,pos+1,digit),high[pos],digit);
        }
    }
    else if(!agrt)///শুধু মাত্র বড় করিনাই*
    {
        ///বড় না করে কল করলাম*
        ans=add(ans,solve(false,true,pos+1,digit),low[pos],digit);
        ///বড় করে কল করলাম আর আগের থেকে ছোট আছে*
        For(i,low[pos]+1,9)ans=add(ans,solve(true,true,pos+1,digit),i,digit);
    }
    else///শুধু মাত্র ছোট করিমাই*
    {
        ///ছোট না করে কল*
        ans=add(ans,solve(true,false,pos+1,digit),high[pos],digit);
        ///ছোট করে কল আর আগের থেকে বড় আছে*
        For(i,0,high[pos]-1)ans=add(ans,solve(true,true,pos+1,digit),i,digit);
    }
    return ans;
}

int main()
{
    ///lo<hi
    while(tk(lo,hi) and lo!="0" and hi!="0")
    {
        int zer=0;
        zer = hi.size()-lo.size();
        len = sz(hi);
        For(i,0,len-1)high[i]=hi[i]-'0';///ডিজিট এর array বানালাম
        For(i,0,len-1)
        {
            ///lo আর hi সমান ডিজিট এর না হলে lo এর সামনে '0' যোগ কে hi এর সমান ডিজিট ওলা বানাব
            if(i+sz(lo)>=len)low[i]=lo[i-(len-sz(lo))]-'0';
            else low[i] = 0;
        }
        For(i,0,9)
        {
            mem(ted,false);
            if(i==0)/// সামনে '0' ওলা solution বাদ দেয়ার জন্নে
            {
                if(zer)///সামনে highest 'zer' টা 0 থাকতে পারে
                {
                    /**
                                                ৪৫ ৩৪৫২ এর জন্নে ৪৫ থেকে ৯৯ পর্যন্ত প্রতেক টার আগে ২ টা করে ০ আছে
                                                ১০০ থেকে ৯৯৯ পর্যন্ত পরতেকটার আগে ১ টা করে ০ আছে এর পরে প্রথমে ০ আছে এমন সংখ্যা নায়।
                    */
                    string ext = "",rext = "1";
                    For(j,0,sz(lo)-1)ext+="9";
                    For(j,0,sz(lo)-2)rext+="0";
                    int badde = zer*(to_int(ext)-(to_int(lo)-1));
                    rFor(j,zer-1,1)
                    {
                        ext+="9";rext+="0";
                        badde+=(j)*(to_int(ext)-(to_int(rext)-1));
                    }
                    cout<<solve(0,0,0,0).fs-badde;
                }
                else
                    cout<<solve(0,0,0,0).fs;/// বাদ দেয়ার দরকার নাই, hi lo same length
            }
            else cout<<" "<<solve(0,0,0,i).fs;
        }
        cout<<endl;
    }
    return 0;
}

/**
with front 0:
45 3452
1991 2081 2081 1533 1038 984 981 981 981 981
with out front 0:
1991-(99-45+1)*2-(999-100+1)*1=981
45 3452
981 2081 2081 1533 1038 984 981 981 981 981
*/

