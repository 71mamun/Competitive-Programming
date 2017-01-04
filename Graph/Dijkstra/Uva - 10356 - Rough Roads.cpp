#include<bits/stdc++.h>
#define SZ 510
#define inf (1<<28)

using namespace std;

struct node {
    int u, w;

    node(int a, int b) {
        u = a;
        w = b;
    }

    bool operator<(const node& p)const {
        return w > p.w;
    }
};

vector<int>graph[SZ];
vector<int>cost[SZ];
int disbyc[SZ];
int diswalk[SZ];

void dijsktra(int src, int camebycycle) {
    priority_queue<node>Q;
    for (int i = 0; i < SZ; i++)disbyc[i] = diswalk[i] = inf;
    if (camebycycle)disbyc[src] = 0;
    else diswalk[src] = 0;
    Q.push(node(src, disbyc[src]));
    while (!Q.empty()) {
        node top = Q.top();
        Q.pop();
        int u = top.u;
        for (int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i];
            if (disbyc[v] > diswalk[u] + cost[u][i]) {
                disbyc[v] = diswalk[u] + cost[u][i];
                Q.push(node(v, disbyc[v]));
            }
            if (diswalk[v] > disbyc[u] + cost[u][i]) {
                diswalk[v] = disbyc[u] + cost[u][i];
                Q.push(node(v, diswalk[v]));
            }
        }
    }
}

int main() {
    int N, E, u, v, w, T = 1;
    while (cin >> N >> E) {
        for (int i = 0; i <= N; i++) {
            graph[i].clear();
            cost[i].clear();
        }
        for (int e = 0; e < E; e++) {
            cin >> u >> v>>w;
            graph[u].push_back(v);
            graph[v].push_back(u);
            cost[u].push_back(w);
            cost[v].push_back(w);
        }
        dijsktra(0, 1);
        cout << "Set #" << T++ << endl;
        if (disbyc[N - 1] < inf)cout << disbyc[N - 1] << endl;
        else cout << "?" << endl;
    }
    return 0;
}
