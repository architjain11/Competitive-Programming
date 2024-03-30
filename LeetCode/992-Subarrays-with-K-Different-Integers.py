class Solution:
    def subarraysWithKDistinct(self, nums: List[int], k: int) -> int:
        count = defaultdict(int)
        ans = 0
        lf, ln = 0, 0

        for r in range(len(nums)):
            count[nums[r]] += 1

            while len(count) > k:
                count[nums[ln]] -= 1
                if count[nums[ln]] == 0:
                    count.pop(nums[ln])
                ln += 1
                lf = ln

            while count[nums[ln]] > 1:
                count[nums[ln]] -= 1
                ln += 1

            if len(count) == k:
                ans += ln-lf+1

        return ans