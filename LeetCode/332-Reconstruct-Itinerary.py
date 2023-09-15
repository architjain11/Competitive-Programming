class Solution:
    def findItinerary(self, tickets: List[List[str]]) -> List[str]:
        adj={ src:[] for src, dest in tickets }
        tickets.sort()
        for src, dest in tickets: adj[src].append(dest)

        ans=["JFK"]

        def dfs(src):
            if len(ans)==len(tickets)+1: return True
            if src not in adj: return False

            tmp=list(adj[src])
            for i, v in enumerate(tmp):
                adj[src].pop(i)
                ans.append(v)

                if dfs(v): return True

                adj[src].insert(i, v)
                ans.pop()
            return False

        dfs("JFK")
        return ans