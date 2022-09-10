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
    int helper(TreeNode* root, int& ans) {
        if(root==NULL) return 0;
        int l=helper(root->left, ans);        
        int r=helper(root->right, ans);
        int single=max(max(l,r)+root->val, root->val);
        int full=max(single, l+r+root->val);
        ans=max(ans, full);
        return single;

    }
    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        helper(root, ans);
        return ans;        
    }
};