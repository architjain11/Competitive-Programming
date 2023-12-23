class Solution:
    def isPathCrossing(self, path: str) -> bool:
        prev = set()
        x, y = 0, 0

        for p in path:
            prev.add((x, y))

            if p=='N': y+=1
            elif p=='S': y-=1
            elif p=='E': x+=1
            else: x-=1

            if (x, y) in prev: return True
        
        return False