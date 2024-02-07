class Solution:
    def frequencySort(self, s: str) -> str:
        count = Counter(s)
        buckets = defaultdict(list)

        for c, freq in count.items():
            buckets[freq].append(c)

        ans = []
        for i in range(len(s), 0, -1):
            for c in buckets[i]:
                ans.append(c*i)
        
        return "".join(ans)