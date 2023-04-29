class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int ans=0, maxele=*max_element(nums.begin(), nums.end());
        while(k--) ans+=maxele++;
        return ans;
    }
};