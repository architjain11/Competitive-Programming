class Solution:
    def minOperations(self, nums: List[int]) -> int:
        length=len(nums)
        nums=sorted(set(nums))
        ans=length
        r=0
        for l in range(len(nums)):
            while r<len(nums) and nums[r]<nums[l]+length: r+=1
            ans=min(ans, length-(r-l))
        return ans