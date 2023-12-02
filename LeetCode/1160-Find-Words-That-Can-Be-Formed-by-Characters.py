class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        m = defaultdict(int)
        for c in chars: m[c] += 1

        ans = 0
        for word in words:
            m2 = defaultdict(int)
            for c in word: m2[c] += 1
            
            good = True
            for c, freq in m2.items():
                if m[c] < freq:
                    good = False
                    break

            if good: ans += len(word)

        return ans