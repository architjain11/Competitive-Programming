class Solution:
    def minimumEffortPath(self, heights: List[List[int]]) -> int:
        rows, cols=len(heights), len(heights[0])
        minh=[[0, 0, 0]] #[diff, r, c]
        visit=set()
        directions=[[0, 1], [0, -1], [1, 0], [-1, 0]]

        while minh:
            diff, r, c=heapq.heappop(minh)
            if (r, c) in visit: continue
            visit.add((r, c))

            if (r, c)==(rows-1, cols-1): return diff

            for dr, dc in directions:
                newr, newc=r+dr, c+dc
                if(newr<0 or newc<0 or newr>=rows or newc>=cols or (newr, newc) in visit): continue
                newdiff=max(diff, abs(heights[r][c]-heights[newr][newc]))
                heapq.heappush(minh, [newdiff, newr, newc])