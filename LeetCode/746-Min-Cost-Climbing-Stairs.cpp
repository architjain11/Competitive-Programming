class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp;
        dp.push_back(cost[0]);       
        dp.push_back(cost[1]);
        
        int n=cost.size();
        for(int i=2; i<n; i++) {
            dp.push_back(cost[i]+(min(dp[i-1], dp[i-2])));
        }
        return min(dp[n-1], dp[n-2]);

    }
};