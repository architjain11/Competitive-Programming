class Solution:
    def numSubmatrixSumTarget(self, matrix: List[List[int]], target: int) -> int:
        rows, cols = len(matrix), len(matrix[0])
        subsum = [[0]*cols for _ in range(rows)]

        for r in range(rows):
            for c in range(cols):
                top = subsum[r-1][c] if r>0 else 0
                left = subsum[r][c-1] if c>0 else 0
                topleft = subsum[r-1][c-1] if min(r, c)>0 else 0

                subsum[r][c] = matrix[r][c] + top + left - topleft

        ans = 0
        for r1 in range(rows):
            for r2 in range(r1, rows):
                count = defaultdict(int)
                count[0] = 1
                for c in range(cols):
                    currsum = subsum[r2][c] - (subsum[r1-1][c] if r1>0 else 0)
                    diff = currsum - target
                    ans += count[diff]
                    count[currsum] +=1
                    

        return ans