class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        int n=nums.size();
        vector<int> ans;
        for(auto total: queries) {
            int sum=0, count=0;
            for(int i=0; i<n && sum<=total; i++) {
                sum+=nums[i];
                if(sum<=total) count++;
            }
            ans.push_back(count);
        }
        return ans;
    }
};