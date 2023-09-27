class Solution:
    def decodeAtIndex(self, s: str, k: int) -> str:
        decodedLen=0
        start=0

        for i, c in enumerate(s):
            if c.isalpha():
                decodedLen+=1
                if k==decodedLen: return c
            else: decodedLen*=int(c)

            if k<=decodedLen:
                start=i
                break

        for i in range(start, -1, -1):
            c=s[i]
            k%=decodedLen
            if k==0 and c.isalpha(): return c
            if c.isdigit(): decodedLen//=int(c)
            else: decodedLen-=1

        return "X"