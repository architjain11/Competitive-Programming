class UnionFind:
    def __init__(self, n):
        self.parent = [i for i in range(n)]
        self.size = [1]*n
        self.count = n

    def find(self, x):
        if self.parent[x] != x: self.parent[x] = self.find(self.parent[x])
        return self.parent[x]
    
    def union(self, x, y):
        px, py = self.find(x), self.find(y)
        if px == py: return

        if self.size[px]<self.size[py]:
            self.parent[px] = py
            self.size[py] += self.size[px]
        else:
            self.parent[py] = x
            self.size[px] += self.size[py]
        self.count -= 1

class Solution:
    def canTraverseAllPairs(self, nums: List[int]) -> bool:
        uf = UnionFind(len(nums))
        fi = {}

        for i, n in enumerate(nums):
            f = 2
            while f*f <= n:
                if n%f == 0:
                    if f in fi: uf.union(i, fi[f])
                    else: fi[f] = i

                    while n%f == 0: n=n//f
                f += 1
            if n>1:
                if n in fi: uf.union(i, fi[n])
                else: fi[n] = i
        
        return uf.count == 1
