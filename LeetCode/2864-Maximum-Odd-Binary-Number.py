class Solution:
    def maximumOddBinaryNumber(self, s: str) -> str:
        ones = s.count("1")
        return (ones-1)*"1" + (len(s)-ones)*"0" + "1"