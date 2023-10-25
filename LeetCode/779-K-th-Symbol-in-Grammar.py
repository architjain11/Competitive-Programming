class Solution:
    def kthGrammar(self, n: int, k: int) -> int:
        curr=0
        l, r = 1, 2**(n-1)

        for _ in range(n-1):
            m=(l+r)//2
            if k<=m: 
                r=m
            else:
                l=m+1
                curr=0 if curr else 1

        return curr