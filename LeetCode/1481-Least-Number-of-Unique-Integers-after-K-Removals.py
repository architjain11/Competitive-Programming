class Solution:
    def findLeastNumOfUniqueInts(self, arr: List[int], k: int) -> int:
        freq = Counter(arr)

        h = list(freq.values())
        heapq.heapify(h)

        ans = len(h)
        while k>0 and h:
            f = heapq.heappop(h)
            if k>=f:
                k-=f
                ans-=1

        return ans