class Solution:
    def findRelativeRanks(self, score: List[int]) -> List[str]:
        sorted_score = sorted(score, reverse=True)
        medals = ["Gold Medal", "Silver Medal", "Bronze Medal"]

        ranks = {score: medals[i] if i < 3 else str(i + 1) for i, score in enumerate(sorted_score)}

        return [ranks[score] for score in score]