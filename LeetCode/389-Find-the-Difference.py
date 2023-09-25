class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        ms, mt=Counter(s), Counter(t)

        for c in mt:
            if c not in ms or ms[c]<mt[c]: return c