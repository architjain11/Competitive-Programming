# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def amountOfTime(self, root: Optional[TreeNode], start: int) -> int:
        graph = defaultdict(list)
        st = [(root, None)]

        while st:
            n, p = st.pop()
            if p:
                graph[p.val].append(n.val)
                graph[n.val].append(p.val)

            if n.left: st.append((n.left, n))
            if n.right: st.append((n.right, n))

        ans = -1
        visited = {start}
        q = deque([start])

        while q:
            for _ in range(len(q)):
                u = q.popleft()
                for v in graph[u]:
                    if v not in visited:
                        visited.add(v)
                        q.append(v)
            ans += 1

        return ans