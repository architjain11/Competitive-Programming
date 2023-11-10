class Solution:
    def restoreArray(self, adjacentPairs: List[List[int]]) -> List[int]:
        adj=defaultdict(list)
        for u, v in adjacentPairs:
            adj[u].append(v)
            adj[v].append(u)

        def dfs(node, prev, ans):
            ans.append(node)
            for u in adj[node]:
                if u!=prev:
                    dfs(u, node, ans)

        start=None
        for node in adj:
            if len(adj[node])==1:
                start=node
                break
        
        ans=[]
        dfs(start, None, ans)
        return ans