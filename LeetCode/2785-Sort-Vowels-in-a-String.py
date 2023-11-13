class Solution:
    def sortVowels(self, s: str) -> str:
        vowels=sorted([c for c in s if c.lower() in 'aeiou'], reverse=True)

        ans=""
        for c in s:
            if c.lower() in 'aeiou': ans+=vowels.pop()
            else: ans+=c

        return ans