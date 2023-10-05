class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        count=defaultdict(int)

        for n in nums:
            count[n]+=1
            if len(count)<=2: continue
            newcount=defaultdict(int)
            for k, v in count.items():
                if v>1:
                    newcount[k]=v-1
            count=newcount

        ans=[]
        for n in count:
            if nums.count(n)>len(nums)//3: ans.append(n)
        
        return ans
            