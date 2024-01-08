# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rangeSumBST(self, root: Optional[TreeNode], low: int, high: int) -> int:
        self.ans = 0

        def dfs(n):
            if not n: return

            if low <= n.val <= high:
                self.ans += n.val
                dfs(n.left)
                dfs(n.right)
            elif n.val > high: dfs(n.left)
            elif n.val < low: dfs(n.right)

        dfs(root)
        return self.ans