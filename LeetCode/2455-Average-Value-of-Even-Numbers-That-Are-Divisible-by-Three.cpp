class Solution {
public:
    int averageValue(vector<int>& nums) {
        int total=0, count=0;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i]%3==0 && nums[i]%2==0) {
                total+=nums[i];
                count++;
            }
        }
        return count==0?0:total/count;
    }
};