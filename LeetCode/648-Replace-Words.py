class Solution:
    def replaceWords(self, dict: List[str], sentence: str) -> str:
        roots = set(dict)
        words = sentence.split()
        ans = []

        for word in words:
            for i in range(len(word) + 1):
                prefix = word[:i]
                if prefix in roots:
                    ans.append(prefix)
                    break
            else:
                ans.append(word)

        return ' '.join(ans)