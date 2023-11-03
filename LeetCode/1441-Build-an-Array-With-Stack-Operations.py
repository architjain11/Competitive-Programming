class Solution:
    def buildArray(self, target: List[int], n: int) -> List[str]:
        ans=[]
        t, s=0, 1
        while t<len(target):
            ans.append('Push')
            if target[t]==s: t+=1
            else: ans.append('Pop')
            s+=1

        return ans
