class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n=nums.size();
        for(int i=0; i<n-1; i++) {
            if(nums[i]==nums[i+1]) {
                nums[i]*=2;
                nums[i+1]=0;
            }
        }
        vector<int> ans;
        for(auto x: nums) if(x!=0) ans.push_back(x);
        
        int zeroes=n-ans.size();
        for(int i=0; i<zeroes; i++) ans.push_back(0);
        
        return ans;
    }
};