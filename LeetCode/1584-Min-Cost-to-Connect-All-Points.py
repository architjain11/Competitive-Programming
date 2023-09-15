class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        n=len(points)
        ans=0
        visit=set()
        minh=[[0, 0]]
        cache={ 0:0 }
        
        while len(visit)<n:
            cost, i=heapq.heappop(minh)
            if i in visit: continue
            ans+=cost
            visit.add(i)
            for j in range(n):
                if j not in visit:
                    x1, y1=points[i]
                    x2, y2=points[j]
                    dist=abs(x2-x1)+abs(y2-y1)
                    if dist<cache.get(j, float('inf')):
                        cache[j]=dist
                        heapq.heappush(minh, [dist, j])
        
        return ans