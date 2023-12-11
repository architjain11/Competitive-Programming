class Solution:
    def findSpecialInteger(self, arr: List[int]) -> int:
        n = len(arr)
        criteria = n//4
        for i in range(n-criteria):
            if arr[i] == arr[i+criteria]: return arr[i]

        return -1
        