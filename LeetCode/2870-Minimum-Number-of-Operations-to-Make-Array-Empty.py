class Solution:
    def minOperations(self, nums: List[int]) -> int:
        freq = Counter(nums)
        ans = 0

        for val in freq.values():
            if val==1: return -1
            ans += ceil(val/3)

        return ans