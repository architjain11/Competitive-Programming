class Solution:
    def constrainedSubsetSum(self, nums: List[int], k: int) -> int:
        ans=nums[0]
        mh=[(-nums[0], 0)]

        for i in range(1, len(nums)):
            while i-mh[0][1]>k:
                heapq.heappop(mh)
            curr=max(nums[i], nums[i]-mh[0][0])
            ans=max(ans, curr)
            heapq.heappush(mh, (-curr, i))

        return ans