class Solution:
    def eliminateMaximum(self, dist: List[int], speed: List[int]) -> int:
        reached=[]

        for i in range(len(dist)):
            reached.append(dist[i]/speed[i])

        heapq.heapify(reached)

        ans=0
        while reached:
            if heapq.heappop(reached)<=ans: break
            ans+=1
            
        return ans
