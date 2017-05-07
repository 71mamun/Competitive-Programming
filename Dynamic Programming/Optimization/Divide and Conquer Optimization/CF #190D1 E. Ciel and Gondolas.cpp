#include <stdio.h>
#include <algorithm>
#include <cassert>
using namespace std;
#define LM 4007
int n,k,cost[LM][LM];

int mem[2][LM];
int final_cost[LM][LM];

int cal_mid_opt(int turn,int mid,int l_opt,int r_opt) {
    int ret;
    mem[turn][mid] = 1e9;
    for(int l=l_opt; l<=min(r_opt,mid); ++l) {
        int price = mem[turn^1][l]+final_cost[l][mid];
        if(mem[turn][mid]>price) {
            mem[turn][mid] = price;
            ret = l;
        }
    }
    return ret;
}

void divide_conquer(int turn,int l,int r,int l_opt,int r_opt,int level) {
    r_opt = min(r_opt,r);
    if(l>r)return;
    if(l==r) {
        cal_mid_opt(turn,l,l_opt,r_opt);
    } else if(l_opt==r_opt) {
        for(int i=l;i<=r;++i){
            cal_mid_opt(turn,i,l_opt,r_opt);
        }
    } else {
        int mid = ((l+r)>>1);

        int mid_opt = cal_mid_opt(turn,mid,l_opt,r_opt);

        divide_conquer(turn,l,mid-1,l_opt,mid_opt,level+1);
        divide_conquer(turn,mid+1,r,mid_opt,r_opt,level+1);
    }
}


int main() {

    char str[LM+LM];
    scanf("%d %d ",&n,&k);

    for(int i = 1; i <= n; i++){
        gets(str);
        for(int j = 1; j <= n; j++){
            cost[i][j] = str[j*2-2]-'0';
            cost[i][j]=cost[i][j]+cost[i][j-1]+cost[i-1][j]-cost[i-1][j-1];
        }
    }

    for(int i=0;i<=n;++i){
        mem[0][i] = 1e9;
    }

    mem[0][0] = 0;

    for(int i=0;i<=n;++i){
        for(int j=i;j<=n;++j){
            final_cost[i][j] = final_cost[j][i] =
            cost[j][j]+cost[i][i]-
            cost[i][j]-cost[j][i];
        }
    }

    int turn = 1;
    for(int i=1; i<=k; ++i) {
        divide_conquer(turn,1,n,0,n,0);
        turn^=1;
    }

    printf("%d\n",mem[turn^1][n]>>1);

    return 0;
}
