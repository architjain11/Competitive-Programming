class Solution:
    def minimumTime(self, n: int, relations: List[List[int]], time: List[int]) -> int:
        adj=defaultdict(list)
        for source, dest in relations:
            adj[source].append(dest)

        maxTime={}
        def dfs(source):
            if source in maxTime: return maxTime[source]

            currTime=time[source-1]
            for v in adj[source]:
                currTime=max(currTime, time[source-1]+dfs(v))
            maxTime[source]=currTime
            return currTime

        for i in range(1, n+1):
            dfs(i)
        return max(maxTime.values())