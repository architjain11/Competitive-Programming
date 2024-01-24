# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pseudoPalindromicPaths (self, root: Optional[TreeNode]) -> int:
        count = defaultdict(int)
        oddCount = 0

        def solve(node):
            nonlocal oddCount
            if not node: return 0
            count[node.val] += 1
            change = 1 if count[node.val]%2==1 else -1
            oddCount += change
            if not node.left and not node.right:
                ans = 1 if oddCount<=1 else 0
            else:
                ans = solve(node.left) + solve(node.right)

            oddCount -= change
            count[node.val] -= 1

            return ans
        
        return solve(root)