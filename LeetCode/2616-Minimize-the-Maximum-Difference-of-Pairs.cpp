class Solution {
public:
    bool isValid(int mid, vector<int>&nums, int p) {
        int count=0, n=nums.size();
        for(int i=0; i<n-1;) {
            if(abs(nums[i]-nums[i+1])<=mid) {
                count++;
                i+=2;
            }
            else i++;
            if(count==p) return true;
        }
        return false;
    }

    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());

        int l=0, r=1e9, ans=0;
        while(l<=r) {
            int mid=l+(r-l)/2;
            if(isValid(mid, nums, p)) {
                ans=mid;
                r=mid-1;
            }
            else
                l=mid+1;
        }
        return ans;
    }
};