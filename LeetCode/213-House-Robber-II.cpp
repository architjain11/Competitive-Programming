class Solution {
public:
    int helper(vector<int> nums) {
        vector<int> dp(nums.size(), 0);
        dp[0]=nums[0];
        dp[1]=max(nums[0], nums[1]);

        for(int i=2; i<dp.size(); i++)
            dp[i]=max(dp[i-2]+nums[i], dp[i-1]);
        return dp[dp.size()-1];
    }
    
    int rob(vector<int>& nums) {
        if(nums.size()<2) return nums[0];
        if(nums.size()==2) return max(nums[0], nums[1]);
        vector<int> copy=nums;
        copy.erase(copy.begin());
        nums.erase(nums.end()-1);
        return max(helper(nums), helper(copy));
        
    }
};