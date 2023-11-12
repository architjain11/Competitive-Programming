class Solution:
    def numBusesToDestination(self, routes: List[List[int]], source: int, target: int) -> int:
        stopToBus=defaultdict(list)
        for bus, route in enumerate(routes):
            for stop in route:
                stopToBus[stop].append(bus)

        if source not in stopToBus or target not in stopToBus: return -1
        if source==target: return 0

        q=deque([source])
        takenBuses=set()
        visitedStops=set()
        ans=0

        while q:
            ans+=1
            stops=len(q)

            for _ in range(stops):
                current=q.popleft()
                for bus in stopToBus[current]:
                    if bus in takenBuses: continue
                    takenBuses.add(bus)

                    for next in routes[bus]:
                        if next in visitedStops: continue
                        if next==target: return ans

                        q.append(next)
                        visitedStops.add(next)

        return -1

