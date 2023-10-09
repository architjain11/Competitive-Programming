class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        def binarySearch(lsearch):
            l, r=0, len(nums)-1
            index=-1
            while l<=r:
                m=(l+r)//2
                if target>nums[m]: l=m+1
                elif target<nums[m]: r=m-1
                else:
                    index=m
                    if lsearch: r=m-1
                    else: l=m+1
            return index

        return [binarySearch(True), binarySearch(False)]