class Solution:
    def minIncrementForUnique(self, nums: List[int]) -> int:
        nums.sort()
        numTracker = 0
        ans = 0

        for n in nums:
            numTracker = max(numTracker, n)
            ans += numTracker-n
            numTracker+=1
        
        return ans