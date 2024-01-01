class Solution:
    def findContentChildren(self, g: List[int], s: List[int]) -> int:
        g.sort()
        s.sort()

        content, cookie = 0, 0
        while cookie < len(s) and content < len(g):
            if s[cookie] >= g[content]: content += 1
            cookie += 1

        return content