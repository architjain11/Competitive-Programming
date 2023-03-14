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
    int ans=0;
    void calculate(TreeNode* root, int number) {
        if(root==NULL) return;
        if(root->right==NULL && root->left==NULL) {
            ans+=(number*10+root->val);
            return;
        }
        calculate(root->right, number*10+root->val);
        calculate(root->left, number*10+root->val);
        return;
    }

    int sumNumbers(TreeNode* root) {
        calculate(root, 0);
        return ans;
    }
};