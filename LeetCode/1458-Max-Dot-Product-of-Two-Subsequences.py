class Solution:
    def maxDotProduct(self, nums1: List[int], nums2: List[int]) -> int:
        @cache # this decorator caches the result of the function using the key as the function call, along with the function parameters
        def solve(i, j):
            if i==len(nums1) or j==len(nums2): return 0

            product=nums1[i]*nums2[j]+solve(i+1, j+1)
            return max(product, solve(i+1, j), solve(i, j+1))

        if max(nums1)<0 and min(nums2)>0: return max(nums1)*min(nums2)
        if min(nums1)>0 and max(nums2)<0: return min(nums1)*max(nums2)

        return solve(0, 0)