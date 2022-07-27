// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if(n==1)
            return n;
        long high=n, low=0;
        int mid, bad;
        while(high>=low) {
            mid = (high+low)/2;
            if(isBadVersion(mid)) {
                high=mid-1;
                bad=mid;

            }
            else
                low=mid+1;
        }
        return bad;
    }
};