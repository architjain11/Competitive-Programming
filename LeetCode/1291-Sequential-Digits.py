class Solution:
    def sequentialDigits(self, low: int, high: int) -> List[int]:
        ans = []
        lower, upper = len(str(low)), len(str(high))

        for digits in range(lower, upper+1):
            for start in range(1, 9):
                if start+digits>10: break

                number = start
                prev = start
                
                for i in range(digits-1):
                    number*=10
                    prev+=1
                    number+=prev
                
                if low<=number<=high: ans.append(number)

        return ans