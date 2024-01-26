class Solution:
    def findPaths(self, m: int, n: int, maxMove: int, startRow: int, startColumn: int) -> int:
        mod = 10**9+7

        @cache
        def solve(r, c, moves):
            if (r<0 or r==m or
                c<0 or c==n): return 1
            if moves == 0: return 0
            return (
                solve(r+1, c, moves-1)+
                solve(r-1, c, moves-1)+
                solve(r, c+1, moves-1)+
                solve(r, c-1, moves-1)
            )%mod

        return solve(startRow, startColumn, maxMove)