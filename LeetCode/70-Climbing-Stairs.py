class Solution:
    def climbStairs(self, n: int) -> int:
        prev, curr, nxt = 0, 1, 0
        
        for i in range(n):
            nxt = prev + curr
            prev, curr = curr, nxt

        return curr