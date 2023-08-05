/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> generate(int left, int right, map<pair<int, int>, vector<TreeNode*>> cache) {
        if(left>right) return {NULL};
        if(cache.count({left, right})) return cache[{left, right}];

        vector<TreeNode*> ans;
        for(int val=left; val<=right; ++val) {
            vector<TreeNode*> leftTrees=generate(left, val-1, cache);
            for(auto leftTree: leftTrees) {
                vector<TreeNode*> rightTrees=generate(val+1, right, cache);
                for(auto rightTree: rightTrees) {
                    TreeNode* root=new TreeNode(val, leftTree, rightTree);
                    ans.push_back(root);
                }
            }
        }

        return cache[{left, right}]=ans;
    }

    vector<TreeNode*> generateTrees(int n) {
        map<pair<int, int>, vector<TreeNode*>> cache;
        return generate(1, n, cache);
    }
};