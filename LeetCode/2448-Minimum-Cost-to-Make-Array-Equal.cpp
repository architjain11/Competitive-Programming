class Solution {
public:
    long long func(vector<int>& nums, vector<int>& cost, int x) {
        long long res=0;
        for(int i=0; i<nums.size(); ++i)
            res+=1L*abs(nums[i]-x)*cost[i];
        return res;
    }

    long long minCost(vector<int>& nums, vector<int>& cost) {
        long long l=1, r=1000000, ans=func(nums, cost, 1);
        while(l<r) {
            long long mid=(l+r)/2;
            long long y1=func(nums, cost, mid), y2=func(nums, cost, mid+1);
            ans=min(y1, y2);
            if(y1<y2) r=mid;
            else l=mid+1;
        }
        return ans;
    }
};