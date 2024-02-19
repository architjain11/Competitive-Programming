class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        if not n: return False

        while n%2==0: n/=2
        return n==1