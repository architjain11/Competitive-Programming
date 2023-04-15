class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        int n=nums.size();
        vector<long long> conver(n), ans(n);
        
        long long curr_max=INT_MIN;
        for(int i=0; i<n; ++i) {
            curr_max=max<long long int>(curr_max, nums[i]);
            conver[i]=nums[i]+curr_max;
        }
        
        long long running_sum=0;
        for(int i=0; i<n; ++i) {
            running_sum+=conver[i];
            ans[i]=running_sum;
        }
        
        return ans;
    }
};