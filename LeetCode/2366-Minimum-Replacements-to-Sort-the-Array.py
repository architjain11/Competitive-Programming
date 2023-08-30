class Solution:
    def minimumReplacement(self, nums: List[int]) -> int:
        largest=nums[-1]
        ans=0

        for i in range(len(nums)-2, -1, -1):
            if nums[i]<=largest:
                largest=nums[i]
                continue
            if nums[i]%largest:
                elements=nums[i]//largest+1
                largest=nums[i]//elements
            else: elements=nums[i]//largest

            ans+=elements-1
        
        return ans