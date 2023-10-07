class Solution {
public:
    int mod=1e9+7;

    int solve(int curr, int length, int largest, int& n, int& m, int& k, vector<vector<vector<int>>>& dp) {
        if(curr==n) {
            if(length==k) return 1;
            return 0;
        }

        if(dp[curr][length][largest]!=-1) return dp[curr][length][largest];

        int cost=0;
        for(int i=1; i<=m; ++i) {
            if(i>largest) cost+=solve(curr+1, length+1, i, n, m, k, dp);
            else cost+=solve(curr+1, length, largest, n, m, k, dp);
            cost%=mod;
        }
        return dp[curr][length][largest]=cost;
        
    }

    int numOfArrays(int n, int m, int k) {
        vector<vector<vector<int>>> dp(51, vector<vector<int>>(51, vector<int>(101, -1)));
        return solve(0, 0, 0, n, m, k, dp);
    }
};