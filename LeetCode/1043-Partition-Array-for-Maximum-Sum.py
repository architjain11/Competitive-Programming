class Solution:
    def maxSumAfterPartitioning(self, arr: List[int], k: int) -> int:

        @cache
        def solve(i):
            cmax = 0
            ans = 0

            for j in range(i, min(i+k, len(arr))):
                cmax = max(cmax, arr[j])
                win = j-i+1
                ans = max(ans, solve(j+1)+cmax*win)

            return ans

        return solve(0)