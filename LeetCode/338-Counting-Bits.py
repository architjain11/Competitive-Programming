class Solution:
    def countBits(self, n: int) -> List[int]:
        def count(x):
            res=0
            while x!=0:
                x&=x-1
                res+=1
            return res

        ans=[0]*(n+1)
        for x in range(n+1):
            ans[x]=count(x)
        return ans