class Solution {
public:
    vector<vector<int>> ans;

    void solve(int num, vector<int>& curr, int total, int k) {
        if(curr.size()==k) {
            ans.push_back(curr);
            return;
        }

        for(int i=num; i<=total; ++i) {
            curr.push_back(i);
            solve(i+1, curr, total, k);
            curr.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> curr;
        solve(1, curr, n, k);
        return ans;
    }
};