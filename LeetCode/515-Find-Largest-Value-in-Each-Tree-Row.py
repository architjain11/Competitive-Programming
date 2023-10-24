# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def largestValues(self, root: Optional[TreeNode]) -> List[int]:
        if not root: return []

        ans=[]
        q=deque([root])
        
        while q:
            rowMax=q[0].val
            for _ in range(len(q)):
                node=q.popleft()
                rowMax=max(rowMax, node.val)
                if node.left: q.append(node.left)
                if node.right: q.append(node.right)

            ans.append(rowMax)

        return ans