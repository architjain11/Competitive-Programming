class Solution:
    def maximumSafenessFactor(self, grid: List[List[int]]) -> int:
        n = len(grid)
        
        def inbounds(r, c):
            return min(r, c)>=0 and max(r, c)<n

        def precomp():
            q = deque()
            mindist = {}
            for r in range(n):
                for c in range(n):
                    if grid[r][c]:
                        q.append([r, c, 0])
                        mindist[(r, c)] = 0
            while q:
                r, c, d = q.popleft()
                neighbors = [[r+1, c], [r-1, c], [r, c+1], [r, c-1]]
                for r2, c2 in neighbors:
                    if inbounds(r2, c2) and (r2, c2) not in mindist:
                        mindist[(r2, c2)] = d+1
                        q.append([r2, c2, d+1])
            
            return mindist
        
        mindist = precomp()
        mh = [(-mindist[(0, 0)], 0, 0)]
        visit = set()
        visit.add((0, 0))
        while mh:
            d, r, c = heapq.heappop(mh)
            d = -d
            if (r, c)==(n-1, n-1):
                return d
            neighbors = [[r+1, c], [r-1, c], [r, c+1], [r, c-1]]
            for r2, c2 in neighbors:
                    if inbounds(r2, c2) and (r2, c2) not in visit:
                        visit.add((r2, c2))
                        heapq.heappush(mh, (-min(d, mindist[(r2, c2)]), r2, c2))            
