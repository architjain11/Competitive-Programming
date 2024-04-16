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
    public TreeNode solve(TreeNode root, int val, int depth) {
        if(root == null) return null;
        
        if(depth == 1) {
            TreeNode l = root.left, r = root.right;
            root.left = new TreeNode(val);
            root.right = new TreeNode(val);
            root.left.left = l;
            root.right.right = r;
            return root;
        }

        root.left = solve(root.left, val, depth-1);
        root.right = solve(root.right, val, depth-1);
        return root;
    }

    public TreeNode addOneRow(TreeNode root, int val, int depth) {
        if(depth == 1) {
            TreeNode root2 = new TreeNode(val);
            root2.left = root;
            return root2;
        }

        return solve(root, val, depth-1);
    }
}