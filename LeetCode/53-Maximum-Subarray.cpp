class Solution {
public:
    int maxSubArray(vector<int>& nums) {        
        vector<int> maxsumhere(nums.size());
        maxsumhere[0]=nums[0];
        for(int i=1; i<nums.size(); i++) {
            if(maxsumhere[i-1]>0)
                maxsumhere[i] = maxsumhere[i-1]+nums[i];
            else
                maxsumhere[i] = nums[i];
        }
        return *max_element(maxsumhere.begin(), maxsumhere.end());
    }
};