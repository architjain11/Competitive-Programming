class Solution:
    def getWinner(self, arr: List[int], k: int) -> int:
        maxEle=max(arr)
        q=deque(arr[1:])
        wins=0
        first=arr[0]

        while q:
            second=q.popleft()
            if first>second:
                q.append(second)
                wins+=1
            else:
                q.append(first)
                first=second
                wins=1

            if first==maxEle or wins==k: return first