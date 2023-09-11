class Solution:
    def groupThePeople(self, groupSizes: List[int]) -> List[List[int]]:
        ans=[]
        m={}

        for i in range(len(groupSizes)):
            m.setdefault(groupSizes[i], []).append(i)
            if(len(m[groupSizes[i]])==groupSizes[i]):
                ans.append(m[groupSizes[i]])
                del m[groupSizes[i]]

        return ans