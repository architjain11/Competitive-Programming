class Solution:
    def minFallingPathSum(self, grid: List[List[int]]) -> int:
        dp = grid[0]
        n = len(grid)

        for r in range(1, n):
            next = [float("inf")]*n
            for curr in range(n):
                for prev in range(n):
                    if prev != curr:
                        next[curr] = min(next[curr], grid[r][curr]+dp[prev])
            dp = next

        return min(dp)