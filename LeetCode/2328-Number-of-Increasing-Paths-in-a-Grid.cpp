class Solution {
public:
    int mod=1e9+7;

    int dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if(dp[i][j]!=-1) return dp[i][j];
        
        int ans=1;
        vector<int> dx={0, 0, 1, -1}, dy={1, -1, 0, 0};
        for(int a=0; a<4; ++a) {
            int x=i+dx[a], y=j+dy[a];

            if(x>=0 && x<grid.size() && y>=0 && y<grid[0].size() && grid[x][y]>grid[i][j])
                ans=(ans%mod + dfs(x, y, grid, dp)%mod)%mod;
        }
        return dp[i][j]=ans%mod;
    }


    int countPaths(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));

        long long count=0;
        for(int i=0; i<m; ++i)
            for(int j=0; j<n; ++j)
                count=(count%mod + dfs(i, j, grid, dp)%mod)%mod;
        return (int)count%mod;
    }
};