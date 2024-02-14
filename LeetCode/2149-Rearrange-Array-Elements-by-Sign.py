class Solution:
    def rearrangeArray(self, nums: List[int]) -> List[int]:
        i, j = 0, 1
        ans = [0]*len(nums)

        for a in range(len(nums)):
            if nums[a] > 0: 
                ans[i] = nums[a]
                i+=2
            else: 
                ans[j] = nums[a]
                j+=2

        return ans