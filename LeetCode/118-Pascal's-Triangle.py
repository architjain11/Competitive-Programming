class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        ans=[[1]]
        for i in range(numRows-1):
            tmp=[0]+ans[-1]+[0]
            newRow=[]
            for j in range(len(ans[-1])+1):
                newRow.append(tmp[j]+tmp[j+1])
            ans.append(newRow)
        return ans