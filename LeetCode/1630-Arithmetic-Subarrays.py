class Solution:
    def checkArithmeticSubarrays(self, nums: List[int], l: List[int], r: List[int]) -> List[bool]:
        def isArithmetic(arr):
            mini, maxi = min(arr), max(arr)

            if (maxi-mini)%(len(arr)-1) != 0: return False

            diff = (maxi-mini)/(len(arr)-1)
            arr=set(arr)
            curr=mini+diff
            while curr<maxi:
                if curr not in arr: return False
                curr+=diff

            return True

        ans=[]
        for i in range(len(l)):
            ans.append(isArithmetic(nums[l[i]:r[i]+1]))

        return ans
