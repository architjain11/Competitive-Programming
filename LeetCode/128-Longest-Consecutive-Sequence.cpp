class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(auto num: nums) s.insert(num);

        int ans=0;
        for(auto num: nums) {
            if(!s.count(num-1)) {
                int currLen=1;
                while(s.count(num+currLen)) ++currLen;
                ans=max(ans, currLen);
            }
        }

        return ans;
    }
};