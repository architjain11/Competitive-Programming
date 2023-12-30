class Solution:
    def makeEqual(self, words: List[str]) -> bool:
        freq = defaultdict(int)
        n = len(words)

        for word in words:
            for char in word:
                freq[char] += 1

        for v in freq.values():
            if v%n != 0: return False

        return True