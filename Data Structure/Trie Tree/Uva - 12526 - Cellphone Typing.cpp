/**
    "In the name of Allah, the Most Gracious, the Most Merciful."
*/
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <math.h>
#include <limits.h>
#include <limits>
#include <string.h>
#include <string>
#include <algorithm>
#include <stack>
#include <set>
#include <ctime>
#include <queue>
#include <vector>
#include <map>
#include <assert.h>
#include <utility>
#include <iomanip>
#define ms(a,b) memset(a,b,sizeof(a))
#define inf (1<<28)
#define mp make_pair
#define pii pair<int,int>
#define fs first
#define sc second
#define pob pop_back
#define vec_ vector
#define clr(a) a.clear()
#define pb push_back
#define eps 1E-7
#define sf scanf
#define pf printf
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define fop   freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define scch(a) scanf(" %c",&a)
#define scll1(a) scanf(" %I64d",&a)
#define scll2(a,b) scanf(" %I64d %I64d",&a,&b)
#define scll3(a,b,c) scanf(" %I64d %I64d %I64d",&a,&b,&c)
#define sci1(a) scanf(" %d",&a)
#define sci2(a,b) scanf(" %d %d",&a,&b)
#define sci3(a,b,c) scanf(" %d %d %d",&a,&b,&c)
#define scd1(a) scanf(" %lf",&a)
#define scd2(a,b) scanf(" %lf %lf",&a,&b)
#define scd3(a,b,c) scanf(" %lf %lf %lf",&a,&b,&c)
#define sz(a) a.size()
#define ll long long
#define ull unsigned long long
#define dd double
#define count_one __builtin_popcount;
#define count_onell __builtin_popcountll;

using namespace std;

//1.template<class T1> void deb(T1 e){cout<<e<<endl;}
//2.template<class T1,class T2> void deb(T1 e1,T2 e2){cout<<e1<<" "<<e2<<endl;}
//3.template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3){cout<<e1<<" "<<e2<<" "<<e3<<endl;}
//4.template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;}
//5.template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<endl;}
//6.template<class T1,class T2,class T3,class T4,class T5,class T6> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<endl;}
//template <class T> T lcm(T a, T b){return (a/__gcd(a,b)) * b;}
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
//ll power(ll x, ll y){if( y == 0)return 1;ll temp = power(x, y/2);return (y%2==0?temp*temp:x*temp*temp);}
//int X[]={1,1,2,2,-1,-1,-2,-2};//knight move//
//int Y[]={2,-2,1,-1,2,-2,1,-1};//knight move//
//int X[]={0,-1,-1,-1,0,1,1,1};
//int Y[]={-1,-1,0,1,1,1,0,-1};
//int X[]={-1,0,1,0};
//int Y[]={0,1,0,-1};
#define charSetSize 28
#define maxWordLength 83
#define SZ 1000010  //edit_needed


struct node
{
    int next[charSetSize];
    int endMark;
    node()
    {
        for(int i=0; i<charSetSize; i++)next[i]=0;
        endMark = 0;
    }
};

node data[SZ];
int counter;
map<char,int>id;
int N;


void Insert(char *str,int len)
{
    int curr = 0;
    for(int i=0; i<len; i++)
    {
        int c = id[str[i]];
        if(data[curr].next[c]==0)
        {
            data[curr].next[c] = counter++;
        }
        curr = data[curr].next[c];
    }
    data[curr].endMark++;
}

void Delete()
{
    ms(data,0);
}

void init()
{
    for(int i=0; i<26; i++)id[i+'a'] = i;
}
vector<char>prnt;

void print_prnt()
{
    for(int i =0; i<prnt.size(); i++)
    {
        cout<<prnt[i];
    }
    cout<<endl;
}


void print_dic(int curr)
{
    if(data[curr].endMark!=0)
    {
        print_prnt();
    }
    for(int i=0; i<26; i++)
    {
        if(data[curr].next[i]==0)continue;
        prnt.push_back(i+'a');
        print_dic(data[curr].next[i]);
        prnt.pop_back();
    }
}

int sum;

void print_org_dic(int curr,int click)
{
    if(data[curr].endMark!=0)
    {
        sum+=click;
        for(int i=0; i<26; i++)
        {
            if(data[curr].next[i]==0)continue;
            print_org_dic(data[curr].next[i],click+1);
        }
        return;
    }
    int child = 0;
    for(int i=0; i<26; i++)
    {
        if(data[curr].next[i]==0)continue;
        child++;
    }
    if(child<=0)return;
    if(child==1&&curr!=0)
    {
        for(int i=0; i<26; i++)
        {
            if(data[curr].next[i]==0)continue;
            print_org_dic(data[curr].next[i],click);
        }
    }
    else
    {
        for(int i=0; i<26; i++)
        {
            if(data[curr].next[i]==0)continue;
            print_org_dic(data[curr].next[i],click+1);
        }
    }
}

int main()
{
    char word[maxWordLength];
    init();
    while(cin>>N)
    {
        counter = 1;
        for(int i=0; i<N; i++)
        {
            cin>>word;
            Insert(word,strlen(word));
        }
        sum=0;
        //print_dic(0);
        print_org_dic(0,0);
        printf("%.2lf\n",((double)sum)/N);
        Delete();
    }
    return 0;
}
