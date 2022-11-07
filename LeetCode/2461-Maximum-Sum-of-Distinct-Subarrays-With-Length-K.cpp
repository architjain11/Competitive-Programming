class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_set<int> s;
        int left=0;
        long long ans=0, curr=0;
        for(int right=0; right<nums.size(); right++)
        {
            while(left<right && (s.count(nums[right]) || s.size() >= k))
            {
                curr-=nums[left];
                s.erase(nums[left]);
                left++;
            }
            curr+=nums[right];
            s.insert(nums[right]);

            if (s.size() == k)
                ans = max(ans, curr);
        }
        return ans;
    }
};