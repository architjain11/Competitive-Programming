class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
        res=list()
        if len(s)>12: return res

        def backtrack(i, dots, currIP):
            if dots==4 and i==len(s):
                res.append(currIP[:-1])
                return
            if dots>4: return

            for j in range(i, min(len(s), i+3)):
                if int(s[i:j+1])<=255 and (i==j or s[i]!='0'):
                    backtrack(j+1, dots+1, currIP+s[i:j+1]+'.')
        
        backtrack(0, 0, "")
        return res