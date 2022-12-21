class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i=0;
        for(auto ele: nums) {
            if(ele!=val) {
                nums[i]=ele;
                i++;
            }
        }
        return i;
    }
};