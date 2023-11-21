class Solution:
    def countNicePairs(self, nums: List[int]) -> int:
        mod = 10**9+7

        def reverse(n):
            rev = 0
            while n:
                rev = rev*10+n%10
                n//=10
            return rev

        arr = []
        for num in nums:
            arr.append(num-reverse(num))

        dict = defaultdict(int)
        ans = 0
        for num in arr:
            ans = (ans+dict[num])%mod
            dict[num]+=1

        return ans