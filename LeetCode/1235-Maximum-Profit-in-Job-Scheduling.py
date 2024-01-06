class Solution:
    def jobScheduling(self, startTime: List[int], endTime: List[int], profit: List[int]) -> int:
        intervals = sorted(zip(startTime, endTime, profit))

        @cache
        def solve(i):
            if i==len(intervals): return 0

            ans = solve(i+1)

            j = bisect.bisect(intervals, (intervals[i][1], -1, -1))
            ans = max(ans, intervals[i][2] + solve(j))

            return ans

        return solve(0)