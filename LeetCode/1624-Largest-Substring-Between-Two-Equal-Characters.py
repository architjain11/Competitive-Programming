class Solution:
    def maxLengthBetweenEqualCharacters(self, s: str) -> int:
        indexes = {}
        ans = -1

        for i in range(len(s)):
            if s[i] in indexes: ans = max(ans, i-indexes[s[i]]-1)
            else: indexes[s[i]] = i

        return ans