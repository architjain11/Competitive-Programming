class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m; //sum->freq
        int ans=0, sum=0;
        m[sum]=1;
        for(auto x: nums) {
            sum+=x;
            ans+=m[sum-k];
            m[sum]++;
        }
        return ans;
    }
};