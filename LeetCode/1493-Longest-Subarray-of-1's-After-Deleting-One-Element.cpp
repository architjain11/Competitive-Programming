class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int zeroes=0, ans=0;

        int start=0;
        for(int i=0; i<nums.size(); ++i) {
            zeroes+=(nums[i]==0);
            while(zeroes>1) {
                zeroes-=(nums[start]==0);
                start++;
            }
            ans=max(ans, i-start);
        }
        return ans;
    }
};