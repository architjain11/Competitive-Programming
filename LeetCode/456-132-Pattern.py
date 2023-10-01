class Solution:
    def find132pattern(self, nums: List[int]) -> bool:
        st=[]
        currmin=nums[0]

        for n in nums[1:]:
            while st and n>=st[-1][0]: st.pop()
            if st and n>st[-1][1]: return True
            st.append([n, currmin])
            currmin=min(currmin, n)

        return False
