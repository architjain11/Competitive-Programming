class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        int ans, max_count=INT_MIN;
        
        for(auto divisor: divisors) {
            int count=0;
            for(auto num: nums) {
                if(num%divisor==0)
                    count++;
            }
            if(count==max_count) ans=min(ans, divisor);
            else if(count>max_count) {
                ans=divisor;
                max_count=count;
            }
        }
        return ans;
    }
};