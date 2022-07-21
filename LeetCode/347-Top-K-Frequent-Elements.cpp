class Solution {
public:
    static bool compare(pair<int,int> &a, pair<int,int> &b) {
        return a.second>b.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> m;
        for(auto ele: nums) {
            if(m.count(ele)) {
                m[ele]++;
            }
            else {
                m[ele];
            }
        }
        vector<int> ans;
        vector<pair<int,int>> v(m.begin(),m.end());
        sort(v.begin(), v.end(), compare);
        for(int i=0; i<k; i++) {
            ans.push_back(v[i].first);
        }
        return ans;
    }
};