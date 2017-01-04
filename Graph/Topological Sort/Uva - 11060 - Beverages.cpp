#include<iostream>
#include<stdio.h>
#include<string.h>
#include<queue>
#include<map>
#include<vector>

using namespace std;
#define sz 220
int main()
{
    priority_queue<int, vector<int>, greater<int> >priority$queue;
    map<string,int> beverage_valu;
    int N,indegree[sz],graph[sz][sz];
    string beverage_name,low_alcohol,high_alcohol,strings[sz];
    vector<string>order;
    int T=1;
    while(cin>>N)
    {
        order.clear();
        beverage_valu.clear();
        memset(indegree,0,sizeof(indegree));
        memset(graph,0,sizeof(graph));
        for(int n=0; n<N; n++)
        {
            cin>>beverage_name;
            beverage_valu[beverage_name]=n;
            strings[n]=beverage_name;
        }
        int M;
        cin>>M;
        for(int m=0; m<M; m++)
        {
            cin>>low_alcohol>>high_alcohol;
            if(graph[beverage_valu[low_alcohol]][beverage_valu[high_alcohol]]==0)
            {graph[beverage_valu[low_alcohol]][beverage_valu[high_alcohol]]=1;
            indegree[beverage_valu[high_alcohol]]++;}
        }
        for(int i=0; i<N; i++)if(indegree[i]==0)priority$queue.push(i);
        while(!priority$queue.empty())
        {
            int now = priority$queue.top();
            priority$queue.pop();
            for(int i=0; i<N; i++)
            {
                if(graph[now][i]==1)
                {
                    graph[now][i]=0;
                    indegree[i]--;
                    if(indegree[i]==0)priority$queue.push(i);
                }
            }
            order.push_back(strings[now]);
        }
        printf("Case #%d: Dilbert should drink beverages in this order:",T++);
        for(int i=0; i<order.size(); i++)
        {
            if(i==(order.size()-1))cout<<" "<<order[i]<<"."<<endl<<endl;
            else cout<<" "<<order[i];
        }
    }
    return 0;
}