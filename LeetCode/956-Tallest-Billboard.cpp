const int offset=5000;
class Solution {
public:
    int solve(int i, int diff, vector<int>&rods, vector<vector<int>>& dp) {
        if(i==rods.size()) {
            if(diff==0) return 0;
            else return INT_MIN;
        }

        if(dp[i][diff+offset]!=-1) return dp[i][diff+offset];

        int c1=solve(i+1, diff, rods, dp);
        int c2=rods[i]+solve(i+1, diff+rods[i], rods, dp);
        int c3=solve(i+1, diff-rods[i], rods, dp);
        return dp[i][diff+offset]=max({c1, c2, c3});
    }

    int tallestBillboard(vector<int>& rods) {
        vector<vector<int>> dp(21, vector<int>(2*offset+1, -1));
        int ans=solve(0, 0, rods, dp);
        return ans;
    }
};