class Solution:
    def minTaps(self, n: int, ranges: List[int]) -> int:
        inf=int(1e9)

        dp=[inf]*(n+1)
        dp[0]=0

        for i in range(n+1):
            start, end=max(0, i-ranges[i]), min(n, i+ranges[i])
            for j in range(start, end+1):
                dp[end]=min(dp[end], dp[j]+1)

        return -1 if dp[n]==inf else dp[n]