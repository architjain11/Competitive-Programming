class Solution:
    def kInversePairs(self, n: int, k: int) -> int:
        MOD = 10**9 + 7
        
        @cache
        def dp(n, k):
            if k == 0: return 1
            if k < 0: return 0
            if n == 1: return 0
            
            return (dp(n - 1, k) + dp(n, k - 1) - dp(n - 1, k - n)) % MOD
        return dp(n, k)