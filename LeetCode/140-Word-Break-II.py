class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> List[str]:
        n = len(s)
        word_set = set(wordDict)

        dp = [[] for _ in range(n + 1)]
        dp[0] = [""]

        for i in range(1, n + 1):
            temp = []
            for j in range(i):
                suffix = s[j:i]
                if suffix in word_set:
                    for substring in dp[j]:
                        temp.append(f"{substring}{' ' if substring else ''}{suffix}")
            dp[i] = temp

        return dp[n]