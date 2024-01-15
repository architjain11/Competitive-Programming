class Solution:
    def findWinners(self, matches: List[List[int]]) -> List[List[int]]:
        zero, one, more = set(), set(), set()

        for match in matches:
            won, lost = match[0], match[1]

            if won not in one and won not in more: zero.add(won)

            if lost in zero:
                zero.remove(lost)
                one.add(lost)
            elif lost in one:
                one.remove(lost)
                more.add(lost)
            elif lost in more: continue
            else: one.add(lost)

        return [sorted(list(zero)), sorted(list(one))]