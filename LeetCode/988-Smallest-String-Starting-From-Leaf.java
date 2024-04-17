/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    String ans = "";

    public String smallestFromLeaf(TreeNode root) {
        dfs(root, "");
        return ans; 
    }

    void dfs(TreeNode root, String curr) {
        if(root == null) return;

        curr = (char)(root.val+'a') + curr;

        if(root.left == null && root.right == null) {
            if(ans.isEmpty() || ans.compareTo(curr)>0)
                ans = curr;
        }

        if(root.left != null) dfs(root.left, curr);
        if(root.right != null) dfs(root.right, curr);
    }
}