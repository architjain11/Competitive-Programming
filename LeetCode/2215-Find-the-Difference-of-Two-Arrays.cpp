class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1(nums1.begin(), nums1.end()), s2(nums2.begin(), nums2.end());
        vector<int> dis1, dis2;

        for(auto num: s1)
            if(!s2.count(num))
                dis1.push_back(num);

        for(auto num: s2)
            if(!s1.count(num))
                dis2.push_back(num);
        
        return {dis1, dis2};
    }
};