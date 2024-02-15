class Solution:
    def largestPerimeter(self, nums: List[int]) -> int:
        nums.sort()
        ans, total = -1, 0

        for n in nums:
            if total>n: ans = total+n
            total += n

        return ans