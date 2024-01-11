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
    void helper(TreeNode* root, int& ans, int minval, int maxval) {
        if(!root) return;

        int val=root->val;
        ans = max(ans, max(abs(minval-val), abs(maxval-val)));
        minval = min(minval, val);
        maxval = max(maxval, val);

        helper(root->left, ans, minval, maxval);
        helper(root->right, ans, minval, maxval);
    }

    int maxAncestorDiff(TreeNode* root) {
        int ans=0;
        int minval=root->val, maxval=root->val;
        helper(root, ans, minval, maxval);
        return ans;
    }
};