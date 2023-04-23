class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int n=nums.size();
        vector<int> freq(101), ans;
        for(int i=0; i<k-1; ++i) freq[nums[i]+50]++;

        for(int i=k-1; i<n; ++i) {
            freq[nums[i]+50]++;
            int count=0, xth=0;
            for(int j=0; j<101; ++j) {
                if(freq[j]>0) count+=freq[j];
                if(count>=x) {
                    xth=j-50;
                    break;
                }
            }
            ans.push_back(xth<0?xth:0);
            freq[nums[i-k+1]+50]--;
        }
        return ans;
    }
};