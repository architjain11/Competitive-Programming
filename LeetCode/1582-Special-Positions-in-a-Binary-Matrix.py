class Solution:
    def numSpecial(self, mat: List[List[int]]) -> int:
        m, n = len(mat), len(mat[0])
        rcount, ccount = [0]*m, [0]*n

        for r in range(m):
            for c in range(n):
                if mat[r][c]==1:
                    rcount[r]+=1
                    ccount[c]+=1

        ans = 0
        for r in range(m):
            for c in range(n):
                if mat[r][c]==1 and rcount[r]==1 and ccount[c]==1:
                    ans+=1
        
        return ans