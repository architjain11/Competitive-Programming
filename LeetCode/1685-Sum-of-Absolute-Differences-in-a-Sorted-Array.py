class Solution:
    def getSumAbsoluteDifferences(self, nums: List[int]) -> List[int]:
        prefix = [nums[0]]
        for i in range(1, len(nums)):
            prefix.append(prefix[-1]+nums[i])

        ans = []

        for i in range(len(nums)):
            lsum = prefix[i]-nums[i]
            rsum = prefix[-1]-prefix[i]
            lc = i
            rc = len(nums)-1-i

            l = lc*nums[i]-lsum
            r = rsum-rc*nums[i]
            ans.append(l+r)

        return ans