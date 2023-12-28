class Solution:
    def getLengthOfOptimalCompression(self, s: str, k: int) -> int:
        cache = {}

        def solve(i, k, prev, prev_c):
            if k<0: return float("inf")
            if i==len(s): return 0
            if (i, k, prev, prev_c) in cache: return cache[(i, k, prev, prev_c)]

            if s[i] == prev:
                add = 1 if prev_c in [1, 9, 99] else 0
                ans = solve(i+1, k, prev, prev_c+1) + add
            else:
                ans = min(
                    solve(i+1, k-1, prev, prev_c),
                    1 + solve(i+1, k, s[i], 1)
                )
            
            cache[(i, k, prev, prev_c)] = ans
            return ans

        return solve(0, k, "", 0)