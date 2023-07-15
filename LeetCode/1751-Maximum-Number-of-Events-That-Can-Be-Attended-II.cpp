class Solution {
public:
    int solve(vector<vector<int>>& dp, vector<vector<int>>& events, int n, int curr, int k) {
        if(curr>=n || k==0) return 0;
        if(dp[curr][k]!=-1) return dp[curr][k];

        vector<int> temp={events[curr][1], INT_MAX, INT_MAX};
        int i=upper_bound(events.begin()+curr+1, events.end(), temp)-events.begin();
        
        return dp[curr][k]=max(solve(dp, events, n, curr+1, k), events[curr][2]+solve(dp, events, n, i, k-1));
    }

    int maxValue(vector<vector<int>>& events, int k) {
        int n=events.size();
        sort(events.begin(), events.end());
        vector<vector<int>> dp(n+1, vector<int>(k+1, -1));
        return solve(dp, events, n, 0, k);
    }
};