#include<iostream>
#include<stdio.h>
#include<string.h>
#include<queue>
#include<map>
#include<vector>

using namespace std;
#define sz 1000000
vector<int>graph[sz];
int main() {
    int N,M;
    priority_queue<int, vector<int>, greater<int> >priority$queue;
    int indegree[sz],u,v;
    vector<int>order;
    while(cin>>N>>M&&N|M) {
        memset(indegree,0,sizeof(indegree));
        order.clear();
        for(int i=0;i<=N;i++)graph[i].clear();
        for(int m=0; m<M; m++) {
            cin>>u>>v;
            graph[u].push_back(v);
            indegree[v]++;
        }
        for(int i=1; i<=N; i++) {
            if(indegree[i]==0)priority$queue.push(i);
        }
        while(!priority$queue.empty()) {
            int now = priority$queue.top();
            priority$queue.pop();
            for(int i=0; i<graph[now].size(); i++) {
                indegree[graph[now][i]]--;
                if(indegree[graph[now][i]]==0)priority$queue.push(graph[now][i]);
            }
            order.push_back(now);
        }
        if(order.size()==N) {
            for(int i=0; i<order.size(); i++) {
                cout<<order[i]<<endl;
            }
        } else cout<<"IMPOSSIBLE"<<endl;
    }
    return 0;
}