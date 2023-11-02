# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def averageOfSubtree(self, root: Optional[TreeNode]) -> int:
        ans=0

        def dfs(root):
            if not root: return 0, 0
            nonlocal ans

            lsum, lcount=dfs(root.left)
            rsum, rcount=dfs(root.right)

            Sum=root.val+lsum+rsum
            count=1+lcount+rcount

            if root.val==Sum//count: ans+=1
            return Sum, count

        dfs(root)
        return ans
        