class Solution {
public:
    int countOdds(int low, int high) {
        int ans=(low%2!=0 || high%2!=0)?1:0;
        return ans+=(high-low)/2;
    }
};