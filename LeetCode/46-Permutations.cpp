class Solution {
public:
    void backtrack(vector<int>& nums, vector<int>& curr, vector<vector<int>>& ans) {
        if(nums.size()==curr.size()) {
            ans.push_back(curr);
            return;
        }

        for(auto num: nums) {
            if(find(curr.begin(), curr.end(), num)==curr.end()) {
                curr.push_back(num);
                backtrack(nums, curr, ans);
                curr.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> curr;
        vector<vector<int>> ans;
        backtrack(nums, curr, ans);
        return ans;
    }
};