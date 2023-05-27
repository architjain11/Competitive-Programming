class Solution:
    def stoneGameIII(self, stoneValue: List[int]) -> str:
        cache = {}

        def dfs(i):
            if i == len(stoneValue): return 0
            if i in cache: return cache[i]

            res = float('-inf')
            for j in range(i, min(i+3, len(stoneValue))):
                res = max(res, sum(stoneValue[i:j+1])-dfs(j+1))
            cache[i] = res
            return res
        
        return "Alice" if dfs(0)>0 else ("Bob" if dfs(0)<0 else "Tie")