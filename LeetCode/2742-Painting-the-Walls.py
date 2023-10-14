class Solution:
    def paintWalls(self, cost: List[int], time: List[int]) -> int:
        cache={}

        def solve(i, remaining):
            if remaining<=0: return 0
            if i==len(cost): return float("inf")
            if (i, remaining) in cache: return cache[(i, remaining)]

            painted=cost[i]+solve(i+1, remaining-1-time[i])
            notPainted=solve(i+1, remaining)
            
            cache[(i, remaining)]=min(painted, notPainted)
            return cache[(i, remaining)]

        return solve(0, len(cost))