/**
ARRAY
*/

#include<stdio.h>
#include<map>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<sstream>
#define charsetsize 52
#define wordLength 101
#define lineLength 10001
#define SZ 100010
#define sf scanf
#define pf printf
#define casePrint pf("Case %d:\n",t)
using namespace std;
 
struct node
{
    int next[charsetsize];
    int endMark;
    node()
    {
        for(int i = 0; i<charsetsize; i++)next[i] = 0;
        endMark = 0;
    }
}data[SZ];
int counter;
map<char,int>id;
 
void Insert(char *str, int len)
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
 
int Search(char *str, int len)
{
    int curr = 0;
    for(int i=0; i<len; i++)
    {
        int c = id[str[i]];
        if(data[curr].next[c]==0) return 0;
        curr = data[curr].next[c];
    }
    return data[curr].endMark;
}
 
void Delete(void)
{
    memset(data,0,sizeof(data));
}
 
void init(void)
{
    for(int i=0; i<26; i++)id[i+'a'] = i;
    for(int i=0; i<26; i++)id[i+'A'] = i + 26;
}
 
int main()
{
    //freopen("input.txt","r",stdin);
    init();
    char word[wordLength];
    char line[lineLength];
    char tmp[wordLength];
    int T,N,M;
    sf("%d",&T);
    for(int t=1; t<=T; t++)
    {
        counter = 1;
        sf("%d",&N);
        for(int n=0; n<N; n++)
        {
            sf("%s",&word);
            if(strlen(word)>2)sort(word+1,word+(strlen(word)-1));
            Insert(word,strlen(word));
        }
        sf("%d ",&M);
        casePrint;
        for(int m=0; m<M; m++)
        {
            gets(line);
            int ans = 1;
            stringstream ss(line);
            while(ss>>tmp)
            {
                if(strlen(tmp)>2)sort(tmp+1,tmp+(strlen(tmp)-1));
                int o = Search(tmp,strlen(tmp));
                ans*=o;
            }
            pf("%d\n",ans);
        }
        Delete();
    }
    return 0;
}