class Solution:
    def minDeletions(self, s: str) -> int:
        count=collections.Counter(s)
        used=set()
        ans=0

        for letter, freq in count.items():
            while freq>0 and freq in used:
                freq-=1
                ans+=1
            used.add(freq)

        return ans