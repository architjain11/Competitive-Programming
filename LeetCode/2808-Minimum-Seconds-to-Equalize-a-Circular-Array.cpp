class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int, vector<int>> indexList;
        for(int i=0; i<n; ++i)
            indexList[nums[i]].push_back(i);

        int ans=INT_MAX;
        for(auto& [k, v]: indexList) {
            int between=0;
            int size=v.size();
            for(int i=1; i<size; ++i) {
                int dist=v[i]-v[i-1]-1;
                between=max(between, dist);
            }
            between=max(between, v[0]+n-v.back()-1);
            ans=min(ans, (between+1)/2);
        }
        return ans;
    }
};