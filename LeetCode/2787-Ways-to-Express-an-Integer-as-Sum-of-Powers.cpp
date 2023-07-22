class Solution {
public:
    int mod=1e9+7;

    int helper(int remaining, int x, int curr, vector<vector<int>>& dp) {
        if(remaining<0) return 0;
        if(dp[curr][remaining]!=-1) return dp[curr][remaining];

        int val=pow(curr, x);
        if(val>remaining) return 0;
        if(val==remaining) return 1;

        int pick=helper(remaining-val, x, curr+1, dp),
            notPick=helper(remaining, x, curr+1, dp);
        return dp[curr][remaining]=(pick%mod+notPick%mod)%mod;
    }

    int numberOfWays(int n, int x) {
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return helper(n, x, 1, dp);
    }
};