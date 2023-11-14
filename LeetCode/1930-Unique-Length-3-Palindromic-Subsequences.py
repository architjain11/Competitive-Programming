class Solution:
    def countPalindromicSubsequence(self, s: str) -> int:
        letters=set(s)
        ans=0

        for l in letters:
            i, j=s.index(l), s.rindex(l)
            middle=set()
            for k in range(i+1, j): middle.add(s[k])
            ans+=len(middle)

        return ans