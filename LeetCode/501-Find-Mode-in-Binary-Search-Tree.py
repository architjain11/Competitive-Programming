# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findMode(self, root: Optional[TreeNode]) -> List[int]:
        def dfs(node, count):
            if not node: return

            count[node.val]+=1
            dfs(node.left, count)
            dfs(node.right, count)

        count=defaultdict(int)
        dfs(root, count)
        maxFreq=max(count.values())

        ans=[]
        for key in count:
            if count[key]==maxFreq:
                ans.append(key)

        return ans