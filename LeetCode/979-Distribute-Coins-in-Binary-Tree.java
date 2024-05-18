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
    int moves;

    public int dfs(TreeNode curr) {
        if(curr==null) return 0;
        int l=dfs(curr.left), r=dfs(curr.right);
        moves+=Math.abs(l)+Math.abs(r);
        return curr.val-1+l+r;
    }

    public int distributeCoins(TreeNode root) {
        moves=0;
        dfs(root);
        return moves;
    }
}