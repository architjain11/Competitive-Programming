class Solution:
    def numberOfBeams(self, bank: List[str]) -> int:
        currRow = bank[0].count("1")
        ans = 0

        for i in range(1, len(bank)):
            nextRow = bank[i].count("1")
            if nextRow:
                ans += currRow*nextRow
                currRow=nextRow

        return ans  