class Solution:
    def findDiagonalOrder(self, nums: List[List[int]]) -> List[int]:
        diagonals = defaultdict(list)
        for row in range(len(nums)-1, -1, -1):
            for col in range(len(nums[row])):
                diag = row+col
                diagonals[diag].append(nums[row][col])

        ans = list()
        curr = 0
        while curr in diagonals:
            ans.extend(diagonals[curr])
            curr += 1

        return ans