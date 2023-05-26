class Solution:
    def stoneGameII(self, piles: List[int]) -> int:
        cache = {}

        def dfs(alice, i, m):
            if i == len(piles): return 0
            if (alice, i, m) in cache: return cache[(alice, i, m)]

            res = 0 if alice else float('inf')
            total = 0

            for x in range(1, 2*m+1):
                if i+x > len(piles): break
                total += piles[i+x-1]

                if alice:
                    res = max(res, total + dfs(not alice, i+x, max(x, m)))
                else:
                    res = min(res, dfs(not alice, i+x, max(x, m)))
            
            cache[(alice, i, m)] = res
            return res
        
        return dfs(True, 0, 1)