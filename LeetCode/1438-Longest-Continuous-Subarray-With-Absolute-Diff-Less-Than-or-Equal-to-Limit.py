class Solution:
    def longestSubarray(self, nums: List[int], limit: int) -> int:
        minq, maxq = deque(), deque()
        l=0
        ans=0

        for r in range(len(nums)):
            while minq and nums[r]<minq[-1]: minq.pop()
            while maxq and nums[r]>maxq[-1]: maxq.pop()

            minq.append(nums[r])
            maxq.append(nums[r])

            while maxq[0]-minq[0]>limit:
                if nums[l]==maxq[0]: maxq.popleft()
                if nums[l]==minq[0]: minq.popleft()
                l+=1
            
            ans=max(ans, r-l+1)

        return ans