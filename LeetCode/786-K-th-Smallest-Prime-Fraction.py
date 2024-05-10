class Solution:
    def kthSmallestPrimeFraction(self, arr: List[int], k: int) -> List[int]:
        arr.sort()
        mh = []
        n = len(arr)

        for i in range(n):
            for j in range(i+1, n):
                if len(mh)<k:
                    heappush(mh, (-arr[i]/arr[j], i, j))
                else:
                    heappushpop(mh, (-arr[i]/arr[j], i, j))

        smallest, i, j = mh[0]
        
        return (arr[i], arr[j])