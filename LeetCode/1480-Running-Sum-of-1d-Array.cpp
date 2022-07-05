class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> ans;
        int running_sum = 0, n = nums.size();
        for(int i=0; i<n; i++) {
            running_sum += nums[i];
            ans.push_back(running_sum);
        }
        return ans;
    }
};