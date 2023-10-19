class Solution:
    def backspaceCompare(self, s: str, t: str) -> bool:
        def finalString(a):
            st=[]
            for c in a:
                if st and c=='#': st.pop()
                elif c!='#': st.append(c)
            return st

        return finalString(s)==finalString(t)