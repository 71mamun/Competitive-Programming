#include<bits/stdc++.h>
using namespace std;
#define LM 1007
int T,t=1,n,f[2][LM],c[2][LM],dp[2][LM];

int main() {
    scanf("%d",&T);
    while(T--) {

        scanf("%d",&n);

        for(int i=0; i<n; ++i) {
            scanf("%d",&f[0][i]);
        }

        for(int i=0; i<n; ++i) {
            scanf("%d",&f[1][i]);
        }

        for(int i=0; i<n-1; ++i) {
            scanf("%d",&c[0][i]);
        }

        for(int i=0; i<n-1; ++i) {
            scanf("%d",&c[1][i]);
        }

        //you can visit only one of the left or right side for each floor.
        //so no need to count taken no of fruits. you must take from each floor
        //to full-fill "n" fruits.

        for(int floor = 1; floor<=n; ++floor) {
            for(int tower=0; tower<2; ++tower) {
                dp[tower][floor] = min(dp[tower][floor-1]+f[tower][floor-1],dp[tower^1][floor-1]+f[tower^1][floor-1]+c[tower^1][floor-1]);
            }
        }

        printf("Case %d: %d\n",t++,min(dp[0][n],dp[1][n]));
    }
    return 0;
}
