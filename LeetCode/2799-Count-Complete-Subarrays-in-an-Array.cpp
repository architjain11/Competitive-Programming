class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> s;
        for(auto num: nums) s.insert(num);
        int unique=s.size();
        
        int ans=0;
        for(int i=0; i<nums.size(); ++i) {
            unordered_set<int> s1;
            for(int j=i; j<nums.size(); ++j) {
                s1.insert(nums[j]);
                if(s1.size()==unique)
                    ans++;
            }
        }
        return ans;
    }
};