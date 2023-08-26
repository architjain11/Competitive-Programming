class Solution:
    def findLongestChain(self, pairs: List[List[int]]) -> int:
        pairs.sort(key=lambda p: p[1])
        ans=1
        last=pairs[0][1]

        for i in range(1, len(pairs)):
            if last<pairs[i][0]:
                ans+=1
                last=pairs[i][1]
        
        return ans