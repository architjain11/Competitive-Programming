class Solution {
public:
    bool canJump(vector<int>& nums) {
        int goal=nums.size()-1;
        for(int i=goal-1; i>=0; i--) {
            int gap=goal-i;
            if(gap<=nums[i]) goal=i;
        }
        return goal==0;
    }
};