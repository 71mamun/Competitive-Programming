#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
#include<bits/stdc++.h>
#include<bits/stdc++.h>

#define     fread(name)             freopen(name,"r",stdin)
#define     fwrite(name)            freopen(name,"w",stdout)
using namespace std;
#define inf 1e9

typedef vector<int> VD;
typedef vector<VD> VVD;
typedef vector<int> VI;

double MinCostMatching(const VVD &cost, VI &Lmate, VI &Rmate)
{
    int n = int(cost.size());

    // construct dual feasible solution
    VD u(n);
    VD v(n);
    for (int i = 0; i < n; i++)
    {
        u[i] = cost[i][0];
        for (int j = 1; j < n; j++) u[i] = min(u[i], cost[i][j]);
    }
    for (int j = 0; j < n; j++)
    {
        v[j] = cost[0][j] - u[0];
        for (int i = 1; i < n; i++) v[j] = min(v[j], cost[i][j] - u[i]);
    }

    // construct primal solution satisfying complementary slackness
    Lmate = VI(n, -1);
    Rmate = VI(n, -1);
    int mated = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (Rmate[j] != -1) continue;
            if (fabs(cost[i][j] - u[i] - v[j]) < 1e-10)
            {
                Lmate[i] = j;
                Rmate[j] = i;
                mated++;
                break;
            }
        }
    }

    VD dist(n);
    VI dad(n);
    VI seen(n);

    // repeat until primal solution is feasible
    while (mated < n)
    {

        // find an unmatched left node
        int s = 0;
        while (Lmate[s] != -1) s++;

        // initialize Dijkstra
        fill(dad.begin(), dad.end(), -1);
        fill(seen.begin(), seen.end(), 0);
        for (int k = 0; k < n; k++)
            dist[k] = cost[s][k] - u[s] - v[k];

        int j = 0;
        while (true)
        {

            // find closest
            j = -1;
            for (int k = 0; k < n; k++)
            {
                if (seen[k]) continue;
                if (j == -1 || dist[k] < dist[j]) j = k;
            }
            seen[j] = 1;

            // termination condition
            if (Rmate[j] == -1) break;

            // relax neighbors
            const int i = Rmate[j];
            for (int k = 0; k < n; k++)
            {
                if (seen[k]) continue;
                const double new_dist = dist[j] + cost[i][k] - u[i] - v[k];
                if (dist[k] > new_dist)
                {
                    dist[k] = new_dist;
                    dad[k] = j;
                }
            }
        }

        // update dual variables
        for (int k = 0; k < n; k++)
        {
            if (k == j || !seen[k]) continue;
            const int i = Rmate[k];
            v[k] += dist[k] - dist[j];
            u[i] -= dist[k] - dist[j];
        }
        u[s] += dist[j];

        // augment along path
        while (dad[j] >= 0)
        {
            const int d = dad[j];
            Rmate[j] = Rmate[d];
            Lmate[Rmate[j]] = j;
            j = d;
        }
        Rmate[j] = s;
        Lmate[s] = j;

        mated++;
    }

    double value = 0;
    for (int i = 0; i < n; i++)
        value += cost[i][Lmate[i]];

    return value;
}

#define LM 500
int cost[LM];
set<int>likes[LM];

int main()
{
    fread("beloved.in");
    fwrite("beloved.out");
    int n;
    cin>>n;
    for(int i=0;i<n;++i)
    {
        cin>>cost[i];
        cost[i] = -cost[i]*cost[i];
    }

    VVD tmp;

    int SZ = n+5;

    tmp.resize(n , vector<int>( n , 0 ) );
    VI lmt,rmt;
    lmt.resize(n);
    rmt.resize(n);
    int m,k;

    for(int i=0;i<n;++i)
    {
        cin>>m;
        while(m--)
        {
            cin>>k;
            tmp[i][k-1] = cost[i];
            likes[i].insert(k-1);
        }
    }

    MinCostMatching(tmp,lmt,rmt);

    for(int i=0;i<n;++i)
    {
        int ans = (likes[i].find(lmt[i])==likes[i].end()?0:lmt[i]+1);
        if(i)cout<<" "<<ans;
        else cout<<ans;
    }
    cout<<endl;
    return 0;
}
