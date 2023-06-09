class Solution {
public:
    // int maxm=INT_MIN;
    
    // APPROACH 2- TLE
    // void traverse(vector<vector<int>>& grid, vector<pair<int, int>> possible, int col=0) {
    //     if(col==grid[0].size()-1) {
    //         maxm=max(maxm, col);
    //         return;
    //     }
        
    //     vector<pair<int, int>> newPossible;
    //     for(auto [i, j]: possible) {
    //         if(i>0 && grid[i-1][j+1]>grid[i][j]) newPossible.push_back({i-1, j+1});
    //         if(grid[i][j+1]>grid[i][j]) newPossible.push_back({i, j+1});
    //         if(i<grid.size()-1 && grid[i+1][j+1]>grid[i][j]) newPossible.push_back({i+1, j+1});
    //     }
        
    //     if(!newPossible.empty()) traverse(grid, newPossible, col+1);
    //     else maxm=max(maxm, col);
    //     return;        
    // }
    
//     APPROACH 1- TLE
//     void traverse(vector<vector<int>>& grid, int i, int j, int currMoves) {
//         if(j==grid[0].size()-1) {
//             maxm=max(maxm, currMoves);
//             return;
//         }
        
//         if(i>0 && grid[i-1][j+1]>grid[i][j]) traverse(grid, i-1, j+1, currMoves+1);        
//         if(grid[i][j+1]>grid[i][j]) traverse(grid, i, j+1, currMoves+1);
//         if(i<grid.size()-1 && grid[i+1][j+1]>grid[i][j]) traverse(grid, i+1, j+1, currMoves+1);
//         maxm=max(maxm, currMoves);
//         return;
//     }
    
    int maxMoves(vector<vector<int>>& grid) {
        // APPROACH 1- TLE
        // TLE
        // for(int i=0; i<grid.size(); ++i)
        //     traverse(grid, i, 0, 0);
        
        // APPROACH 2- TLE
        // vector<pair<int, int>> possible;
        // for(int i=0; i<grid.size(); ++i) possible.push_back({i, 0});
        // traverse(grid, possible);
        // return maxm;

        int m=grid.size(), n=grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int i=0; i<m; ++i)
            dp[i][0]=1;

        for(int j=0; j<n-1; ++j) {
            for(int i=0; i<m; ++i) {
                if(dp[i][j]) {
                    if(i>0 && grid[i-1][j+1]>grid[i][j]) dp[i-1][j+1]++;
                    if(grid[i][j+1]>grid[i][j]) dp[i][j+1]++;
                    if(i<m-1 && grid[i+1][j+1]>grid[i][j]) dp[i+1][j+1]++;
                }
            }
        }
        
        for(int j=n-1; j>=0; --j) {
            for(int i=0; i<m; ++i) {
                if(dp[i][j]) {
                    return j;
                }
            }
        }

        return 0;
    }
};