class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<pair<int, int>> dp(nums.size()); //{pos sum, neg sum}
        dp[0].first=nums[0];        
        dp[0].second=nums[0];

        for(int i=1; i<nums.size(); i++) {
            int n1=nums[i]*dp[i-1].first, n2=nums[i]*dp[i-1].second;
            if(n1<n2) swap(n1, n2);
            dp[i].first = max(n1, nums[i]);
            dp[i].second = min(n2, nums[i]);
        }
        int mx=INT_MIN;
        for(auto x: dp) mx=max(mx, x.first);
        
        return mx;
    }
};