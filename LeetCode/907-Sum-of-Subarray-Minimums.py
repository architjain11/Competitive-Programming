class Solution:
    def sumSubarrayMins(self, arr: List[int]) -> int:
        mod = 10**9+7
        ans = 0
        st = []

        for i, n in enumerate(arr):
            while st and n<st[-1][1]:
                j, m = st.pop()
                l, r = j-st[-1][0] if st else j+1, i-j
                ans = (ans+m*l*r)%mod
            st.append((i, n))

        for i in range(len(st)):
            j, n = st[i]
            l, r = j-st[i-1][0] if i>0 else j+1, len(arr)-j
            ans = (ans+n*l*r)%mod

        return ans