class Solution:
    def minExtraChar(self, s: str, dictionary: List[str]) -> int:
        words=set(dictionary)
        dp={len(s): 0}

        def dfs(i):
            if i in dp: return dp[i]
            ans=1+dfs(i+1)
            for j in range(i, len(s)):
                if s[i:j+1] in words: ans=min(ans, dfs(j+1))
            dp[i]=ans
            return ans
        
        return dfs(0)
        