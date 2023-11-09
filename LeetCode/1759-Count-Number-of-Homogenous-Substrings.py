class Solution:
    def countHomogenous(self, s: str) -> int:
        mod=10**9+7
        ans=0
        same=0

        for i in range(len(s)):
            if i==0 or s[i]==s[i-1]:
                same+=1
            else: same=1

            ans=(ans+same)%mod

        return ans