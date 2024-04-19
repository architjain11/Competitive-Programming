class Solution {
    int r, c, islands = 0;

    public int numIslands(char[][] grid) {
        r=grid.length; c=grid[0].length;

        for(int i=0; i<r; ++i)
            solve(grid, i);

        return islands;    
    }

    public void solve(char[][] grid, int i) {
        char [] curr=grid[i];
        for(int col=0; col<c; ++col) {
            if(curr[col]=='1') {
                bfs(grid, i, col);
                islands++;
            }
        }
    }

    public void bfs(char[][] grid, int row, int col) {
        grid[row][col]='#';

        if (row > 0 && grid[row - 1][col] == '1')
            bfs(grid, row - 1, col);
        if (row + 1 < r && grid[row + 1][col] == '1')
            bfs(grid, row + 1, col);
        if (col > 0 && grid[row][col - 1] == '1')
            bfs(grid, row, col - 1);
        if (col + 1 < c && grid[row][col + 1] == '1')
            bfs(grid, row, col + 1);
    }
}