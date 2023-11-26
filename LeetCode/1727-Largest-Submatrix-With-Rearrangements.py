class Solution:
    def largestSubmatrix(self, matrix: List[List[int]]) -> int:
        r, c = len(matrix), len(matrix[0])
        ans = 0
        prev = [0]*c

        for row in range(r):
            heights = matrix[row][::]
            for col in range(c):
                if heights[col]>0: heights[col]+=prev[col]
            heights_sorted = sorted(heights, reverse=True)
            for i in range(c):
                ans = max(ans, heights_sorted[i] * (i + 1))
            prev = heights

        return ans