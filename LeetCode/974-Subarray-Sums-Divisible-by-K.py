class Solution:
    def subarraysDivByK(self, nums: List[int], k: int) -> int:
        prefix = 0
        ans = 0
        m = defaultdict(int)
        m[0] = 1

        for n in nums:
            prefix+=n
            remainder = prefix % k

            if remainder in m:
                ans += m[remainder]
            m[remainder] += 1

        return ans