class Graph:

    def __init__(self, n: int, edges: List[List[int]]):
        self.adj=[[] for _ in range(n)]
        for u, v, c in edges:
            self.adj[u].append((v, c))

    def addEdge(self, edge: List[int]) -> None:
        u, v, c=edge
        self.adj[u].append((v, c))

    def shortestPath(self, node1: int, node2: int) -> int:
        n=len(self.adj)
        pq=[(0, node1)]
        cost=[inf]*(n)
        cost[node1]=0

        while pq:
            cc, cn=heappop(pq)
            if cc>cost[cn]: continue
            if cn==node2: return cc

            for neighbor, c in self.adj[cn]:
                new_c=cc+c
                if cost[neighbor]>new_c:
                    cost[neighbor]=new_c
                    heappush(pq, (new_c, neighbor))

        return -1


# Your Graph object will be instantiated and called as such:
# obj = Graph(n, edges)
# obj.addEdge(edge)
# param_2 = obj.shortestPath(node1,node2)