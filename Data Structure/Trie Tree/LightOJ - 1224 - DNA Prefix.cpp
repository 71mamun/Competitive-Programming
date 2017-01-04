/**
LINKED LIST
*/

#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
using namespace std;
#define SZ 53
#define sf scanf
#define pf printf
#define casePrint pf("Case %d: ",t)
 
map<char,int>id;
 
struct node
{
    node *next[4];
    int n;
    node()
    {
        for(int i=0; i<4; i++)next[i] = NULL;
        n = 0;
    }
};
 
node *root;
 
void Insert(char *str, int len)
{
    node *curr = root;
    for(int i=0; i<len; i++)
    {
        int c = id[str[i]];
        if(curr->next[c]==NULL)
        {
            curr->next[c] = new node();
        }
        curr = curr->next[c];
        curr->n++;
    }
}
 
void Delete (node *curr)
{
    for(int i=0; i<4; i++)
    {
        if(curr->next[i]!=NULL)
        {
            Delete(curr->next[i]);
        }
    }
    delete curr;
}
 
int solve(node *curr, int len)
{
    if(curr==NULL) return 0;
    int Max = len*curr->n;
    for(int i=0; i<4; i++)
    {
        Max = max(Max,solve(curr->next[i],len+1));
    }
    return Max;
}
 
int main()
{
    id['A'] =0;
    id['C'] =1;
    id['G'] =2;
    id['T'] =3;
    int T,N;
    char arr[SZ];
    sf("%d",&T);
    for(int t =1; t<=T; t++)
    {
        root = new node();
        sf("%d",&N);
        for(int n=0; n<N; n++)
        {
            sf("%s",&arr);
            Insert(arr,strlen(arr));
        }
        casePrint;
        pf("%d\n",solve(root,0));
        Delete(root);
    }
    return 0;
}