class Solution {
    public int islandPerimeter(int[][] grid) {
        int land = 0, water = 0;

        for(int i=0; i<grid.length; ++i) {
            for(int j=0; j<grid[0].length; ++j) {
                if(grid[i][j] == 1) {
                    land++;
                    if(i-1>=0 && grid[i-1][j]==1) water++;
                    if(j-1>=0 && grid[i][j-1]==1) water++;
                }
            }
        }

        return (land*4) - (water*2);
    }
}