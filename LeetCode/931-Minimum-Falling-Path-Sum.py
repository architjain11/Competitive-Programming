class Solution:
    def minFallingPathSum(self, matrix: List[List[int]]) -> int:
        n = len(matrix)

        @cache
        def solve(r, c):
            if r==n: return 0
            if c<0 or c==n: return float('inf')

            ans = matrix[r][c] + min(
                solve(r+1, c-1),
                solve(r+1, c),
                solve(r+1, c+1)
            )
            return ans


        ans = float('inf')
        for c in range(n):
            ans = min(ans, solve(0, c))
        return ans