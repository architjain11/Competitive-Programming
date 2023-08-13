class Solution {
public:
    bool dfs(int i, vector<int>& nums, unordered_map<int, bool>& dp) {
        int n=nums.size();
        if(i==n) return true;
        if(dp.count(i)) return dp[i];
        
        bool ans=false;
        if(i<n-1 && nums[i]==nums[i+1])
            ans|=dfs(i+2, nums, dp);

        if(i<n-2)
            if((nums[i]==nums[i+1] && nums[i]==nums[i+2]) || (nums[i]+2==nums[i+1]+1 && nums[i]+2==nums[i+2]))
                ans|=dfs(i+3, nums, dp);

        return dp[i]=ans;
    }

    bool validPartition(vector<int>& nums) {
        unordered_map<int, bool> dp;
        return dfs(0, nums, dp);
    }
};