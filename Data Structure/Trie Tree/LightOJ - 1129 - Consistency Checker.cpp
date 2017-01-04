/**
LINKED LIST
*/

#include<bits/stdc++.h>
using namespace std;
#define SZ 12
bool YES;
 
struct node
{
    int endMark;
    node *next[10];
    node()
    {
        endMark = false;
        for(int i=0; i<10; i++)next[i]=NULL;
    }
};
 
node *root;
 
void Insert(char *str, int len)
{
    node *curr = root;
    for(int i=0; i<len; i++)
    {
        int id = str[i]-'0';
        if(curr->next[id]==NULL)
        {
            curr->next[id] = new node();
            curr->endMark = 1;
        }
        curr = curr->next[id];
        if(curr->endMark==-1)
        {
            YES = false;
            return;
        }
    }
    if(curr->endMark==1)
    {
        YES = false;
        return;
    }
    curr->endMark = -1;
}
 
bool Search(char *str,int len)
{
    node *curr = root;
    for(int i=0; i<len; i++)
    {
        int id = str[i]-'0';
        if(curr->next[id]==NULL) return false;
        curr = curr->next[id];
    }
    return curr->endMark;
}
 
void Delete(node *curr)
{
    for(int i=0; i<10; i++)
    {
        if(curr->next[i]!=NULL)
        {
            Delete(curr->next[i]);
        }
    }
    delete curr;
}
 
int main()
{
    int T,N;
    char arr[SZ];
    scanf("%d",&T);
    for(int t=1; t<=T; t++)
    {
        YES = true;
        root = new node();
        scanf("%d",&N);
        while(N--)
        {
            scanf("%s",&arr);
            if(YES)Insert(arr,strlen(arr));
        }
        printf("Case %d: ",t);
        if(YES)printf("YES\n");
        else printf("NO\n");
        Delete(root);
    }
    return 0;
}