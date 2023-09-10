class Solution:
    def countOrders(self, n: int) -> int:
        slots, ans=2*n, 1
        while slots>0:
            ans*=slots*(slots-1)//2
            slots-=2
        return ans%(10**9+7)