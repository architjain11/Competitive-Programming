class Solution:
    def reductionOperations(self, nums: List[int]) -> int:
        nums.sort()
        ans = 0
        items = 0

        for i in range(1, len(nums)):
            if nums[i-1] != nums[i]: items+=1
            ans+=items

        return ans