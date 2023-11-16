class Solution:
    def findDifferentBinaryString(self, nums: List[str]) -> str:
        n=len(nums)
        
        def generate(s):
            if len(s)==n:
                if s not in nums: return s
                return ""
            
            add1=generate(s+"1")
            if add1: return add1
            return generate(s+"0")

        return generate("")