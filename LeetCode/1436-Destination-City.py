class Solution:
    def destCity(self, paths: List[List[str]]) -> str:
        s = set()
        
        for i in range(len(paths)):
            s.add(paths[i][0])

        for i in range(len(paths)):
            if paths[i][1] not in s: return paths[i][1]

        return ""