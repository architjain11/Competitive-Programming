class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        auto last=unique(nums.begin(), nums.end());
        nums.resize(distance(nums.begin(), last));
        return nums.size();
    }
};