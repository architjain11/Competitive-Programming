class Solution:
    def longestStrChain(self, words: List[str]) -> int:
        words.sort(key=lambda w: -len(w))
        index={}
        for i, w in enumerate(words): index[w]=i

        cache={}
        def dfs(i):
            if i in cache: return cache[i]
            ans=1
            for j in range(len(words[i])):
                w=words[i]
                predecessor=w[:j]+w[j+1:]
                if predecessor in index:
                    ans=max(ans, 1+dfs(index[predecessor]))
            
            cache[i]=ans
            return ans

        for i, _ in enumerate(words):
            dfs(i)
        return max(cache.values())