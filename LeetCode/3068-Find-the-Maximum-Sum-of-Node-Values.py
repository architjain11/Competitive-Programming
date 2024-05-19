class Solution:
    def maximumValueSum(self, nums: List[int], k: int, edges: List[List[int]]) -> int:
        change = [(n^k)-n for n in nums]
        change.sort(reverse=True)
        ans=sum(nums)

        for i in range(0, len(nums), 2):
            if i==len(nums)-1: break
            path_change=change[i]+change[i+1]
            if path_change<=0: break
            ans+=path_change

        return ans