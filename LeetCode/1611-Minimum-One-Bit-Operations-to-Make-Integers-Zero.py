class Solution:
    def minimumOneBitOperations(self, n: int) -> int:
        if n ==0: return 0
        
        sigBit = 0
        while 2**sigBit <= n: sigBit+=1
        sigBit-=1

        return 2**(sigBit+1)-1-self.minimumOneBitOperations(2**sigBit^n)