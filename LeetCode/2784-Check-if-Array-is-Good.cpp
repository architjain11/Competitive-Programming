class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n=nums.size(), maxEle=*max_element(nums.begin(), nums.end());
        if(n!=maxEle+1) return false; 
        int arrSum=accumulate(nums.begin(), nums.end(), 0);
        if(arrSum==(maxEle*(maxEle+1)/2)+maxEle) return true;
        return false;
    }
};