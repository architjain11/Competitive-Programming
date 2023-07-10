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
    int dfs(TreeNode* root) {
        if(!root) return 0;
        if(!root->left) return 1+dfs(root->right);
        else if(!root->right) return 1+dfs(root->left);
        return 1+min(dfs(root->right), dfs(root->left));
    }

    int minDepth(TreeNode* root) {
        return dfs(root);
    }
};