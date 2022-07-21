class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        int prod=1;
        
        for(auto ele: nums) {
            prod*=ele;
            ans.push_back(prod);
        }
        prod=1;
        for(int i=nums.size()-1; i>0; i--) {
            ans[i] = prod*ans[i-1];
            prod*=nums[i];
        }
        ans[0]=prod;
        return ans;
    }
};