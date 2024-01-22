class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:
        duplicate = sum(nums)-sum(set(nums))
        missing = len(nums)*(len(nums)+1)//2-sum(set(nums))

        return [duplicate, missing]