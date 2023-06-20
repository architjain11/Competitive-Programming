class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n=nums.size();
        if(k==0) return nums;

        vector<int> ans(n, -1);
        if(2*k+1>n) return ans;
        
        long sum=0;
        for(int i=0; i<2*k+1; ++i)
            sum+=nums[i];
        ans[k]=sum/(2*k+1);
        for(int i=2*k+1; i<n; ++i) {
            sum+=nums[i]-nums[i-(2*k+1)];
            ans[i-k]=sum/(2*k+1);
        }

        return ans;
    }
};