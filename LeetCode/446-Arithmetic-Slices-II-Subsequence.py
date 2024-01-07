class Solution:
    def numberOfArithmeticSlices(self, nums: List[int]) -> int:
        n = len(nums)
        ans = 0
        dp = [defaultdict(int) for _ in range(n)]

        for i in range(n):
            for j in range(i):
                diff = nums[i]-nums[j]
                dp[i][diff] += 1+dp[j][diff]
                ans += 1+dp[j][diff]

        return ans - (n*(n-1)//2)