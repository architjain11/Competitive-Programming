class Solution {
public:
    int helper(map<pair<int, int>, int>& dp, int prev, int curr, vector<int>& arr1, vector<int>& arr2) {
        if(curr==arr1.size()) return 0;
        if(dp[{curr, prev}]) return dp[{curr, prev}];

        int ans=INT_MAX/2;
        int id=upper_bound(arr2.begin(), arr2.end(), prev)-arr2.begin();
        if(prev<arr1[curr])
            ans=min(ans, helper(dp, arr1[curr], curr+1, arr1, arr2));
        if(id<arr2.size())
            ans=min(ans, helper(dp, arr2[id], curr+1, arr1, arr2)+1);
        
        return dp[{curr, prev}]=ans;
    }

    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());
        map<pair<int, int>, int> dp;
        int ans=helper(dp, INT_MIN, 0, arr1, arr2);
        return ans>=INT_MAX/2?-1:ans;
    }
};