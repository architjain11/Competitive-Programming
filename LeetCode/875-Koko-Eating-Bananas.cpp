class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1, mid;
        int high=*max_element(piles.begin(), piles.end());
        int ans=high;
        while(low<=high) {
            mid = (low+high)/2;
            long int result=0;
            for(auto x: piles) {
                result += ceil((double)x/mid);
            }
            if(result<=h) {
                ans = ans>mid?mid:ans;
                high = mid-1;
            }
            else
                low = mid+1;
        }
        return ans;
    }
};