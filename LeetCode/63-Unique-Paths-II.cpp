class Solution {
public:
    int dfs(int r, int c, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        int m=grid.size(), n=grid[0].size();
        if(r==m || c==n || grid[r][c]) return 0;
        if(dp[r][c]!=-1) return dp[r][c];

        return dp[r][c]=dfs(r+1, c, grid, dp)+dfs(r, c+1, grid, dp);
    }

    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        dp[m-1][n-1]=1;
        return dfs(0, 0, grid, dp);
    }
};