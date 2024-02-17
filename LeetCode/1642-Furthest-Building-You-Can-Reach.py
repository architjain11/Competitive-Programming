class Solution:
    def furthestBuilding(self, heights: List[int], bricks: int, ladders: int) -> int:
        h = []

        for i in range(len(heights)-1):
            diff = heights[i+1]-heights[i]
            if diff<=0: continue

            bricks-=diff
            heapq.heappush(h, -diff)

            if bricks<0:
                if ladders==0:
                    return i
                ladders-=1
                bricks += -heapq.heappop(h)

        return len(heights)-1