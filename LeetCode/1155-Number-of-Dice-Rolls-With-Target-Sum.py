class Solution:
    def numRollsToTarget(self, n: int, k: int, target: int) -> int:
        mod = 10**9+7
        cache = {}

        def solve(rolls, target):
            if rolls == 0: return 1 if target == 0 else 0
            if (rolls, target) in cache: return cache[(rolls, target)]

            ans = 0
            for d in range(1, k+1):
                ans = (ans + solve(rolls-1, target-d))%mod
            
            cache[(rolls, target)] = ans
            return ans

        return solve(n, target)