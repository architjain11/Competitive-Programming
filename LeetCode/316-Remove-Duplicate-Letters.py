class Solution:
    def removeDuplicateLetters(self, s: str) -> str:
        last={}
        st=[]
        visited=set()

        for i, letter in enumerate(s): last[letter]=i

        for i, letter in enumerate(s):
            if letter not in visited:
                while (st and st[-1]>letter and last[st[-1]]>i):
                    visited.remove(st.pop())

                st.append(letter)
                visited.add(letter)

        return ''.join(st)