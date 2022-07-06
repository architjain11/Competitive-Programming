class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        vector<vector<int>> ans;
        int i=0, j=1, k=size-1;
        for(int i=0; i<size-2; i++) {
            if(i>0 && nums[i]==nums[i-1])
                continue;
            j=i+1;
            k=size-1;
            while(j<k) {
                if(nums[i]+nums[j]+nums[k]<0) {
                    j++;
                }

                else if(nums[i]+nums[j]+nums[k]>0) {
                    k--;
                }
                else {
                    ans.insert(ans.end(), { nums[i], nums[j], nums[k] });
                    k--;
                    while(j<k && nums[k]==nums[k+1])
                        k--;
                }
            }
        }
        return ans;
    }
};