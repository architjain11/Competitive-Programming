class Solution:
    def minCost(self, colors: str, neededTime: List[int]) -> int:
        l = 0
        ans = 0

        for r in range(1, len(colors)):
            if colors[l] == colors[r]:
                if neededTime[l] < neededTime[r]:
                    ans += neededTime[l]
                    l = r
                else:
                    ans += neededTime[r]
            else: l = r

        return ans