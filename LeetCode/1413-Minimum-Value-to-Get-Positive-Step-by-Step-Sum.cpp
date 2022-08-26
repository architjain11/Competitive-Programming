class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int x=1;
        reverse(nums.begin(), nums.end());
        for(auto val: nums) {
            x-=val;
            if(x<1) x=1;
        }
        return x;
    }
};