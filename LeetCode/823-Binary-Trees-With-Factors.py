class Solution:
    def numFactoredBinaryTrees(self, arr: List[int]) -> int:
        mod=10**9+7
        arr.sort()
        dp=defaultdict(int)
        for a in arr:
            temp=1
            for b in arr:
                if b>a: break
                temp+=dp[b]*dp[a/b]
            dp[a]=temp
        return sum(dp.values())%mod