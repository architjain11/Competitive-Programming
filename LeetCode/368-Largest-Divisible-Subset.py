class Solution:
    def largestDivisibleSubset(self, nums: List[int]) -> List[int]:
        nums.sort()

        @cache
        def solve(i):
            if i==len(nums): return []
            
            ans = [nums[i]]
            for j in range(i+1, len(nums)):
                if nums[j]%nums[i]==0:
                    temp = [nums[i]] + solve(j)
                    if len(temp) > len(ans): ans = temp

            return ans
        
        ans = []
        for i in range(len(nums)):
            temp = solve(i)
            if len(temp) > len(ans): ans = temp

        return ans