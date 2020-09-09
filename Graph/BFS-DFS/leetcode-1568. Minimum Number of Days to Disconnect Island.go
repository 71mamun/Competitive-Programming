var hi, wi int

var X = [4]int {1,0,-1,0}
var Y = [4]int {0,-1,0,1}

func dfs(x int, y int, grid *[][]int, visit *[][]bool) {
    if x<0 || x>=hi || y<0 || y>=wi || (*grid)[x][y] != 1 || (*visit)[x][y] == true {
        return
    }
    
    (*visit)[x][y] = true
    for i:=0; i<4; i++ {
        nx, ny := x+X[i], y+Y[i]
        dfs(nx,ny,grid,visit)
    }
    
}

func isConnected(grid *[][]int) bool {
    island := 0
    
    visit := make([][]bool,hi)
    for i := 0; i<hi; i++ {
        visit[i] = make([]bool,wi)
    }
    
    for i := 0; i < hi; i++ {
        for j := 0; j < wi; j++ {
            
            if visit[i][j] == true || (*grid)[i][j] == 0 {
                continue
            }
            dfs(i, j, grid, &visit)
            island++
        }
    }
    
    return island==1
}

func minDays(grid [][]int) int {
    hi, wi = len(grid), len(grid[0])
    
    if(isConnected(&grid) == false) {
        return 0;
    }
    
    
    for i := 0; i < hi; i++ {
        for j := 0; j < wi; j++ {
            if grid[i][j] == 1 {
                grid[i][j] = 0
                if(isConnected(&grid) == false) {
                    return 1;
                }
                grid[i][j] = 1
            }
        }
    }
    
    
    return 2;
}