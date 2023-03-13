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
    bool parts(TreeNode* l, TreeNode* r) {
        if(l==NULL || r==NULL) {
            if(l!=r) return false;
            return true;
        }
        cout<<l->val<<r->val<<endl;
        if(l->val==r->val) {
            return (parts(l->left, r->right) && parts(l->right, r->left));
        }
        return false;
    }

    bool isSymmetric(TreeNode* root) {\
        return parts(root, root);
    }
};