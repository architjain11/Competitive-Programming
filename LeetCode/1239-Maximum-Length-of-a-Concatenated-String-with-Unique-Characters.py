class Solution:
    def maxLength(self, arr: List[str]) -> int:
        s = set()

        def overlap(s, c):
            count = Counter(s) + Counter(c)
            return max(count.values())>1

        def backtrack(i):
            if i == len(arr): return len(s)

            ans = 0
            if not overlap(s, arr[i]):
                for c in arr[i]: s.add(c)
                ans = backtrack(i+1)
                for c in arr[i]: s.remove(c)

            return max(ans, backtrack(i+1))

        return backtrack(0)