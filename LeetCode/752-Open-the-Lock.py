class Solution:
    def openLock(self, deadends: List[str], target: str) -> int:
        if "0000" in deadends: return -1

        def child(lock):
            ans = []
            for i in range(4):
                dig = str((int(lock[i])+1)%10)
                ans.append(lock[:i]+dig+lock[i+1:])
                dig = str((int(lock[i])-1+10)%10)
                ans.append(lock[:i]+dig+lock[i+1:])
            return ans

        q = deque()
        q.append(["0000", 0])
        visit = set(deadends)
        while q:
            lock, turns = q.popleft()
            if lock == target: return turns
            for c in child(lock):
                if c not in visit:
                    visit.add(c)
                    q.append([c, turns+1])

        return -1
