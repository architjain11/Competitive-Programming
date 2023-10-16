class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        ans=[1]
        for i in range(rowIndex):
            next=[0]*(len(ans)+1)
            for j in range(len(ans)):
                next[j]+=ans[j]
                next[j+1]+=ans[j]
            ans=next
        return ans