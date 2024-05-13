class Solution {
    public int matrixScore(int[][] grid) {
        int n=grid.length, m=grid[0].length;

        for(int i=0; i<n; i++) {
            if(grid[i][0] == 0){
                for(int j=0; j<m; j++) {
                    grid[i][j] = 1 - grid[i][j];
                }
            }
        }

        for(int j=1; j<m; j++) {
            int count = 0;
            for(int i=0; i<n; i++) {
                if(grid[i][j] == 1)
                    count++;
            }
            if(count*2<n) {
                for(int i=0; i<n; i++) {
                    grid[i][j] = 1 - grid[i][j];
                }
            }
        }

        int sum = 0;

        for(int i=0; i<n; i++) {
            int row = 0;
            for(int j=0; j<m; j++)
                row = row*2 + grid[i][j];
            sum+=row;
        }

        return sum;
    }
}