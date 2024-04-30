class Solution:
    def wonderfulSubstrings(self, word: str) -> int:
        freq = {}
        freq[0] = 1
        mask, ans = 0, 0

        for c in word:
            bit = ord(c)-97
            mask ^= (1<<bit)
            if mask in freq:
                ans += freq[mask]
                freq[mask] += 1
            else: freq[mask] = 1

            for odd in range(0, 10):
                if(mask^(1<<odd)) in freq:
                    ans += freq[mask^(1<<odd)]

        return ans