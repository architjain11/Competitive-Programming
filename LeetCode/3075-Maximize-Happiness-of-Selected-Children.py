class Solution:
    def maximumHappinessSum(self, happiness: List[int], k: int) -> int:
        happiness.sort(reverse=True)
        total=0
        turns=0

        for i in range(k):
            total+=max(happiness[i]-turns, 0)
            turns+=1
        
        return total