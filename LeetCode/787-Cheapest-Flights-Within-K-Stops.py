class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, k: int) -> int:
        prices = [float("inf")] * n
        prices[src] = 0

        for i in range(k+1):
            tmp = prices.copy()

            for s, d, p in flights:
                if prices[s] == float("inf"): continue
                if prices[s] + p < tmp[d]: tmp[d] = prices[s] + p

            prices = tmp

        return -1 if prices[dst] == float("inf") else prices[dst]