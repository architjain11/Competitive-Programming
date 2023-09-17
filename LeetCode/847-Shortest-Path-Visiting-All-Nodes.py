class Solution:
    def shortestPathLength(self, graph: List[List[int]]) -> int:
        n=len(graph)
        allVisited=(1<<n)-1
        q=deque()

        visited=[[False for _ in range(n)] for _ in range(allVisited+1)]

        for node in range(n):
            initial=(1<<node)
            q.append((node, initial, 1))
            visited[initial][node]=True

        while q:
            curr_node, curr_mask, curr_len=q.popleft()
            if curr_mask==allVisited: return curr_len-1
            for neighbor in graph[curr_node]:
                new_mask=curr_mask | (1<<neighbor)
                if visited[new_mask][neighbor]: continue
                q.append((neighbor, new_mask, curr_len+1))
                visited[new_mask][neighbor]=True

        return -1