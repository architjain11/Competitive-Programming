class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        count = Counter(arr)
        s = set()

        for c in count.values():
            if c in s: return False
            s.add(c)

        return True