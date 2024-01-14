class Solution:
    def closeStrings(self, word1: str, word2: str) -> bool:
        w1_freq, w2_freq = Counter(word1), Counter(word2)

        return sorted(w1_freq.values()) == sorted(w2_freq.values()) and set(w1_freq.keys()) == set(w2_freq.keys())