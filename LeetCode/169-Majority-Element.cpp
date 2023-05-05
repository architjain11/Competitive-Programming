class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res=0, count=0;
        for(auto num: nums) {
            if(count==0) res=num;
            count+=(num==res)?1:-1;
        }
        return res;
    }
};