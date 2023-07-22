class Solution {
public:    
    long long helper(vector<int>& nums, int x, bool prev, int i, map<pair<bool, int>, long long>& dp) {
        if(i==nums.size()) return 0;
        
        if(dp[{prev, i}]) return dp[{prev, i}];
        
        bool curr=nums[i]%2==0;
        if(curr==prev) {
            return dp[{prev, i}]=nums[i]+helper(nums, x, curr, i+1, dp);
        }
        
        return dp[{prev, i}]=max(helper(nums, x, prev, i+1, dp), helper(nums, x, curr, i+1, dp)-x+nums[i]);
    }
    
    long long maxScore(vector<int>& nums, int x) {
        map<pair<bool, int>, long long> dp;
        return nums[0]+helper(nums, x, nums[0]%2==0, 1, dp);
    }
};