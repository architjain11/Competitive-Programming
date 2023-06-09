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
    int depth(TreeNode* root, int value, int d=0) {
        if(root==NULL) return 0;
        if(root->val==value) return d;

        int ans=depth(root->right, value, d+1);
        if(ans)
            return ans;

        return depth(root->left, value, d+1);
    }

    bool sibling(TreeNode* root, int x, int y) {
        if(root==NULL) return false;
        else if(root->right==NULL || root->left==NULL) {
            return (
                sibling(root->right, x, y) ||
                sibling(root->left, x, y)
            );
        }
        
        return (
            (root->left->val==x && root->right->val==y) || 
            (root->left->val==y && root->right->val==x) ||  
            sibling(root->right, x, y) || 
            sibling(root->left, x, y)
        );
    }

    bool isCousins(TreeNode* root, int x, int y) {
        int a=depth(root, x), b=depth(root, y);
        if(!sibling(root, x, y)) return a==b;
        return false;
    }
};