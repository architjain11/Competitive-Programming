class Solution:
    def minWindow(self, s: str, t: str) -> str:
        countt = Counter(t)
        win = {}

        have, need = 0, len(countt)
        ans, ansLen = [-1, -1], float('inf')

        l = 0
        for r in range(len(s)):
            curr = s[r]
            win[curr] = 1+win.get(curr, 0)

            if curr in countt and win[curr] == countt[curr]:
                have += 1

            while have == need:
                if r-l+1 < ansLen:
                    ans = [l, r]
                    ansLen = r-l+1

                win[s[l]] -= 1
                if s[l] in countt and win[s[l]] < countt[s[l]]:
                    have -= 1

                l += 1

        l, r = ans
        return s[l:r+1] if ansLen!=float('inf') else ""