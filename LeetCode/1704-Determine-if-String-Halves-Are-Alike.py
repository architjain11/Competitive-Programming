class Solution:
    def halvesAreAlike(self, s: str) -> bool:
        vowels = "aeiouAEIOU"
        
        l, r = 0, 0
        mid = len(s)//2
        for a, b in zip(s[:mid], s[mid:]):
            if a in vowels: l+=1
            if b in vowels: r+=1

        return l==r