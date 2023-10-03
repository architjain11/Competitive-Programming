class Solution:
    def numIdenticalPairs(self, nums: List[int]) -> int:
        count=Counter(nums)
        ans=0

        for n, c in count.items():
            ans+=c*(c-1)//2
        
        return ans