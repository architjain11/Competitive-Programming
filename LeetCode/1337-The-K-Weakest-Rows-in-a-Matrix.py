class Solution:
    def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:
        minh=[]
        for i, row in enumerate(mat):
            heapq.heappush(minh, (-sum(row), -i))
            if len(minh)>k: heapq.heappop(minh)
        
        return [-i for _, i in sorted(minh, reverse=True)]