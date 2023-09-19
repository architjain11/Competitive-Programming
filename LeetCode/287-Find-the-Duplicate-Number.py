class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        exists=set()
        return next(num for num in nums if num in exists or exists.add(num))