class Solution:
    def findAllPeople(self, n: int, meetings: List[List[int]], firstPerson: int) -> List[int]:
        secrets = set([0, firstPerson])
        m = {}

        for s, d, t in meetings:
            if t not in m: m[t] = defaultdict(list)
            m[t][s].append(d)
            m[t][d].append(s)

        def solve(s, adj):
            if s in visit: return
            
            visit.add(s)
            secrets.add(s)

            for n in adj[s]:
                solve(n, adj)

        for t in sorted(m.keys()):
            visit = set()
            for s in m[t]:
                if s in secrets:
                    solve(s, m[t])

        return list(secrets)