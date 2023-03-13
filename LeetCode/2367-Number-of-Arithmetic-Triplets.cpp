class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        set<int> s;
        for(auto x: nums) s.insert(x);

        int count=0;
        for(auto x: s) {
            if(s.count(x+diff) && s.count(x+2*diff)) count++;
        }

        return count;
    }
};