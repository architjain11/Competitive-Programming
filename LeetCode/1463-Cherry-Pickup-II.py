class Solution:
    def cherryPickup(self, grid: List[List[int]]) -> int:
        rows, cols = len(grid), len(grid[0])

        @cache
        def solve(r, c1, c2):
            if c1==c2 or min(c1, c2)<0 or max(c1, c2)==cols: return 0
            if r == rows-1: return grid[r][c1] + grid[r][c2]

            ans = 0
            dir = [-1, 0, 1]

            for d1 in dir:
                for d2 in dir:
                    ans = max(
                        ans,
                        solve(r+1, c1+d1, c2+d2)
                    )
            ans += grid[r][c1] + grid[r][c2]
            return ans

        return solve(0, 0, cols-1)