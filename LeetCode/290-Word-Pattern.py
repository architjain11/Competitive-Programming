class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        if len(pattern)!=len(s.split()): return False
        m={}
        for key, value in zip(pattern, s.split()):
            if key not in m: m[key]=value
            else:
                if m[key]!=value: return False
        return False if len(set(m.values()))!=len(m) else True  