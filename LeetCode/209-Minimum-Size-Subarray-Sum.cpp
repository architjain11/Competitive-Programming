class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int start=0, currSum=0, ans=INT_MAX;
        
        for(int end=0; end<nums.size(); ++end) {
            currSum+=nums[end];
            while(currSum>=target) {
                ans=min(ans, end-start+1);
                currSum-=nums[start];
                start++;
            }
        }

        return (ans==INT_MAX?0:ans);
    }
};