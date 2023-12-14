class Solution:
    def onesMinusZeros(self, grid: List[List[int]]) -> List[List[int]]:
        m, n = len(grid), len(grid[0])

        rows = [sum(row) for row in grid]
        cols = [sum(col) for col in zip(*grid)]

        ans = [[0]*n for _ in range(m)]
        for i in range(m):
            for j in range(n):
                ans[i][j] = rows[i] + cols[j] - (m-rows[i]) - (n-cols[j])
        
        return ans