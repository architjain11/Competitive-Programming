class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        for(int i=0; i<n; ++i) {
            if(nums[i]%2==0) nums[i]=0;
            else nums[i]=1;
        }
        unordered_map<int, int> m;
        int ans=0, sum=0;
        m[0]=1;
        for(auto num: nums) {
            sum+=num;
            ans+=m[sum-k];
            m[sum]++;
        }
        return ans;
    }
};