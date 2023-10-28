class Solution:
    def countVowelPermutation(self, n: int) -> int:
        dp=[[], [1, 1, 1, 1, 1]]
        a, e, i, o, u=0, 1, 2, 3, 4
        mod=10**9+7

        for j in range(2, n+1):
            dp.append([0, 0, 0, 0, 0])
            prev=j-1

            dp[j][a]=dp[prev][e]
            dp[j][e]=(dp[prev][a]+dp[prev][i])%mod
            dp[j][i]=(dp[prev][a]+dp[prev][u]+dp[prev][e]+dp[prev][o])%mod
            dp[j][o]=(dp[prev][i]+dp[prev][u])%mod
            dp[j][u]=dp[prev][a]

        return sum(dp[n])%mod