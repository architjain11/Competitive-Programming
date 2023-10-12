# """
# This is MountainArray's API interface.
# You should not implement it, or speculate about its implementation
# """
#class MountainArray:
#    def get(self, index: int) -> int:
#    def length(self) -> int:

class Solution:
    def findInMountainArray(self, target: int, mountain_arr: 'MountainArray') -> int:
        length=mountain_arr.length()

        l, r=1, length-2
        while l<=r:
            m=(l+r)//2
            before=mountain_arr.get(m-1)
            curr=mountain_arr.get(m)
            after=mountain_arr.get(m+1)

            if before<curr<after: l=m+1
            elif before>curr>after: r=m-1
            else: break
        peak=m

        l, r=0, peak
        while l<=r:
            m=(l+r)//2
            val=mountain_arr.get(m)
            if val<target: l=m+1
            elif val>target: r=m-1
            else: return m

        l, r=peak, length-1
        while l<=r:
            m=(l+r)//2
            val=mountain_arr.get(m)
            if val>target: l=m+1
            elif val<target: r=m-1
            else: return m

        return -1