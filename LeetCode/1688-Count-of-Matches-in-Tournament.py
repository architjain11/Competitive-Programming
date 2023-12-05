class Solution:
    def numberOfMatches(self, n: int) -> int:
        ans = 0
        while n>1:
            if n%2 == 0:
                ans += n//2
                n/=2
            else:
                teams = (n-1)//2
                ans += teams
                n = teams+1

        return int(ans)