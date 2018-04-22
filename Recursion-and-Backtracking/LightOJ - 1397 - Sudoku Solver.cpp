#include<cstdio>
#include<vector>
using namespace std;
#define LM 10
char board[LM][LM];

vector < vector<int> > res(LM, vector<int>(LM, 0));

int row_mask[LM],col_mask[LM],block_mask[LM];
const int tot_row = 9,tot_col = 9;

pair<int,int> positionOfLowestOptions(vector< vector<int> > &grid) {
    int best = 100,row,col;
    for(int r=0; r<9; ++r) {
        for(int c=0; c<9; c++) {
            if(grid[r][c]!=0)continue;
            int block = (r/3)*3+c/3;
            int cur_mask = row_mask[r]|col_mask[c]|block_mask[block];
            if(9-__builtin_popcount(cur_mask)<best){
                best = 9-__builtin_popcount(cur_mask);
                row = r;col = c;
            }
        }
    }
    return {row,col};
}

bool isCompleted(vector< vector<int> >grid)
{
    for(int i=0;i<9;++i){
        for(int j=0;j<9;++j){
            if(grid[i][j]==0)return false;
        }
    }
    return true;
}

bool solution(vector< vector<int> > &grid) {

    if(isCompleted(grid)) {
        return true;
    }

    pair<int,int> best_choice = positionOfLowestOptions(grid);
    int i = best_choice.first;
    int j = best_choice.second;

    int block = (i/3)*3+j/3;
    int cur_mask = row_mask[i]|col_mask[j]|block_mask[block];

    for(int digit=9; digit>=1; --digit) {
        if(cur_mask&(1<<digit)) continue;
        int update_mask = (1<<digit);

        row_mask[i]|=update_mask;
        col_mask[j]|=update_mask;
        block_mask[block]|=update_mask;
        grid[i][j] = digit;

        if(solution(grid)) {
            return true;
        }

        grid[i][j] = 0;
        row_mask[i]&=(~update_mask);
        col_mask[j]&=(~update_mask);
        block_mask[block]&=(~update_mask);
    }

    return false;
}

int main() {
    int T,t=1;
    scanf("%d",&T);
    while(T--) {
        for (int i=0; i<9; i++) {
            scanf("%s",board[i]);
            row_mask[i]=col_mask[i]=block_mask[i]=0;
        }

        printf("Case %d:\n",t++);

        for(int i=0; i<9; ++i) {
            for(int j=0; j<9; ++j) {
                if(board[i][j]!='.') {
                    int digit = board[i][j]-'0';
                    res[i][j] = digit;
                    row_mask[i]|=(1<<digit);
                    col_mask[j]|=(1<<digit);
                    block_mask[(i/3)*3+j/3]|=(1<<digit);
                } else {
                    res[i][j] = 0;
                }
            }
        }

        if(solution(res)) {
            for(int k=0; k<tot_row; ++k) {
                for(int l=0; l<tot_col; ++l) {
                    printf("%c",res[k][l]+'0');
                }
                printf("\n");
            }
        } else {
            printf("-1\n");
        }
    }
    return 0;
}
