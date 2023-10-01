class Solution:
    def reverseWords(self, s: str) -> str:
        s=list(s)
        l=0
        for r in range(len(s)):
            if s[r]==" " or r==len(s)-1:
                tl, tr=l, r if r==len(s)-1 else r-1

                while tl<tr:
                    s[tl], s[tr]=s[tr], s[tl]
                    tl+=1
                    tr-=1
                l=r+1

        return "".join(s)