class Solution:
    def minOperations(self, nums: List[int], x: int) -> int:
        target=sum(nums)-x
        curr_sum=0
        max_win=-1
        l=0

        for r in range(len(nums)):
            curr_sum+=nums[r]
            
            while l<=r and curr_sum>target:
                curr_sum-=nums[l]
                l+=1
            
            if curr_sum==target: max_win=max(max_win, r-l+1)

        return -1 if max_win==-1 else len(nums)-max_win