class Solution:
    def minDifficulty(self, jobDifficulty: List[int], d: int) -> int:
        if len(jobDifficulty) < d: return -1

        @cache
        def newDay(i, d, max_diff):
            if i==len(jobDifficulty):
                return 0 if d==0 else float("inf")
            if d==0: return float("inf")

            max_diff = max(max_diff, jobDifficulty[i])
            ans = min(
                newDay(i+1, d, max_diff),
                max_diff + newDay(i+1, d-1, -1)
            )

            return ans

        return newDay(0, d, -1)