class Solution:
    def numWays(self, steps: int, arrLen: int) -> int:
        mod=10**9+7

        @cache
        def solve(curr, remaining):
            if remaining==0:
                if curr==0: return 1
                return 0
            
            ans=solve(curr, remaining-1)
            if curr<arrLen-1:
                ans=(ans+solve(curr+1, remaining-1))%mod
            if curr>0:
                ans=(ans+solve(curr-1, remaining-1))%mod

            return ans

        return solve(0, steps)