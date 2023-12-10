class Solution:
    def transpose(self, matrix: List[List[int]]) -> List[List[int]]:
        r, c = len(matrix), len(matrix[0])
        ans = []
        for i in range(c):
            tmp = []
            for j in range(r):
                tmp.append(matrix[j][i])
            ans.append(tmp)

        return ans