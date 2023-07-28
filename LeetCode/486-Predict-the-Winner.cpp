class Solution {
public:
    int maxDiff(int l, int r, vector<int>& nums) {
        if(l==r) return nums[l];
        int leftScore=nums[l]-maxDiff(l+1, r, nums);
        int rightScore=nums[r]-maxDiff(l, r-1, nums);

        return max(leftScore, rightScore);
    }

    bool PredictTheWinner(vector<int>& nums) {
        return maxDiff(0, nums.size()-1, nums)>=0;
    }
};